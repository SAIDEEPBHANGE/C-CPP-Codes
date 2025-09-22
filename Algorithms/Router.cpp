#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

class Router {
private:
    int memoryLimit;                         // Maximum number of packets the router can store
    deque<vector<int>> packets;              // Deque to maintain packets in FIFO order
    unordered_map<string, vector<vector<int>>> packetMap; // Map for checking duplicates by (source, destination, timestamp)

public:
    // Constructor to initialize Router with memory limit
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    // Method to add a packet, returns true if added, false if it's a duplicate or memory exceeds
    bool addPacket(int source, int destination, int timestamp) {
        // Check if the packet is a duplicate (source + destination + timestamp)
        string key = to_string(source) + "-" + to_string(destination) + "-" + to_string(timestamp);
        if (packetMap.find(key) != packetMap.end()) {
            return false; // Duplicate packet, don't add it
        }

        // If memory limit is reached, remove the oldest packet from FIFO
        if (packets.size() >= memoryLimit) {
            vector<int> oldestPacket = packets.front();
            string oldestKey = to_string(oldestPacket[0]) + "-" + to_string(oldestPacket[1]) + "-" + to_string(oldestPacket[2]);
            packetMap.erase(oldestKey); // Remove oldest packet from the map
            packets.pop_front(); // Remove from deque
        }

        // Add the new packet to the deque
        vector<int> packet = {source, destination, timestamp};
        packets.push_back(packet);
        
        // Add the packet to the map for future duplicate checks
        packetMap[key].push_back(packet);
        return true;
    }

    // Method to forward the next packet in FIFO order and remove it from the router's memory
    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {}; // No packets to forward
        }

        // Get the next packet in FIFO order
        vector<int> nextPacket = packets.front();
        string key = to_string(nextPacket[0]) + "-" + to_string(nextPacket[1]) + "-" + to_string(nextPacket[2]);
        
        // Remove it from the map
        packetMap.erase(key);
        
        // Remove from deque
        packets.pop_front();

        return nextPacket;
    }

    // Method to count packets with a specific destination and timestamp range
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;

        // Iterate over the packets in the router
        for (const auto& packet : packets) {
            if (packet[1] == destination && packet[2] >= startTime && packet[2] <= endTime) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Router* router = new Router(5); // Router with memory limit of 5 packets

    // Test adding packets
    cout << router->addPacket(1, 2, 10) << endl; // true
    cout << router->addPacket(1, 3, 11) << endl; // true
    cout << router->addPacket(1, 2, 12) << endl; // true
    cout << router->addPacket(1, 2, 12) << endl; // false (duplicate)
    cout << router->addPacket(2, 3, 13) << endl; // true
    cout << router->addPacket(4, 5, 14) << endl; // true
    cout << router->addPacket(3, 2, 15) << endl; // true
    cout << router->addPacket(1, 3, 16) << endl; // true (older packet removed)

    // Test forwarding packets
    vector<int> forwardedPacket = router->forwardPacket();
    cout << forwardedPacket[0] << " " << forwardedPacket[1] << " " << forwardedPacket[2] << endl; // 1 2 10

    // Test getCount
    cout << router->getCount(3, 10, 15) << endl; // 2 (Packets with destination 3 and timestamp between 10 and 15)
    
    // Cleanup
    delete router;
    return 0;
}
#include <iostream>
#include <deque>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Router {
private:
    int memoryLimit;  // Maximum number of packets the router can store
    deque<vector<int>> packets; // Deque to maintain packets in FIFO order
    unordered_map<string, vector<vector<int>>> packetMap; // Map for checking duplicates
    unordered_map<int, map<int, int>> destinationTimestampMap; // Tracks packets by destination and timestamp

public:
    // Constructor to initialize Router with memory limit
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    // Method to add a packet, returns true if added, false if it's a duplicate or memory exceeds
    bool addPacket(int source, int destination, int timestamp) {
        // Check if the packet is a duplicate (source + destination + timestamp)
        string key = to_string(source) + "-" + to_string(destination) + "-" + to_string(timestamp);
        if (packetMap.find(key) != packetMap.end()) {
            return false; // Duplicate packet, don't add it
        }

        // If memory limit is reached, remove the oldest packet from FIFO
        if (packets.size() >= memoryLimit) {
            vector<int> oldestPacket = packets.front();
            string oldestKey = to_string(oldestPacket[0]) + "-" + to_string(oldestPacket[1]) + "-" + to_string(oldestPacket[2]);
            packetMap.erase(oldestKey); // Remove oldest packet from the map
            packets.pop_front(); // Remove from deque

            // Also remove from destinationTimestampMap
            destinationTimestampMap[oldestPacket[1]].erase(oldestPacket[2]);
            if (destinationTimestampMap[oldestPacket[1]].empty()) {
                destinationTimestampMap.erase(oldestPacket[1]);
            }
        }

        // Add the new packet to the deque
        vector<int> packet = {source, destination, timestamp};
        packets.push_back(packet);

        // Add the packet to the map for future duplicate checks
        packetMap[key].push_back(packet);

        // Add the packet to the destinationTimestampMap for fast range queries
        destinationTimestampMap[destination][timestamp]++;

        return true;
    }

    // Method to forward the next packet in FIFO order and remove it from the router's memory
    vector<int> forwardPacket() {
        if (packets.empty()) {
            return {}; // No packets to forward
        }

        // Get the next packet in FIFO order
        vector<int> nextPacket = packets.front();
        string key = to_string(nextPacket[0]) + "-" + to_string(nextPacket[1]) + "-" + to_string(nextPacket[2]);

        // Remove it from the map
        packetMap.erase(key);

        // Remove from deque
        packets.pop_front();

        // Remove from destinationTimestampMap
        destinationTimestampMap[nextPacket[1]].erase(nextPacket[2]);
        if (destinationTimestampMap[nextPacket[1]].empty()) {
            destinationTimestampMap.erase(nextPacket[1]);
        }

        return nextPacket;
    }

    // Method to count packets with a specific destination and timestamp range
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;

        // Get the timestamp map for the given destination
        auto& timestampMap = destinationTimestampMap[destination];

        // Iterate through the timestamps and count packets within the range [startTime, endTime]
        auto it = timestampMap.lower_bound(startTime);
        while (it != timestampMap.end() && it->first <= endTime) {
            count += it->second;
            ++it;
        }

        return count;
    }
};

int main() {
    Router* router = new Router(5); // Router with memory limit of 5 packets

    // Test adding packets
    cout << router->addPacket(1, 2, 10) << endl; // true
    cout << router->addPacket(1, 3, 11) << endl; // true
    cout << router->addPacket(1, 2, 12) << endl; // true
    cout << router->addPacket(1, 2, 12) << endl; // false (duplicate)
    cout << router->addPacket(2, 3, 13) << endl; // true
    cout << router->addPacket(4, 5, 14) << endl; // true
    cout << router->addPacket(3, 2, 15) << endl; // true
    cout << router->addPacket(1, 3, 16) << endl; // true (older packet removed)

    // Test forwarding packets
    vector<int> forwardedPacket = router->forwardPacket();
    cout << forwardedPacket[0] << " " << forwardedPacket[1] << " " << forwardedPacket[2] << endl; // 1 2 10

    // Test getCount
    cout << router->getCount(3, 10, 15) << endl; // 2 (Packets with destination 3 and timestamp between 10 and 15)
    
    // Cleanup
    delete router;
    return 0;
}
