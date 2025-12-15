#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <iterator>
using namespace std;
class Task {
public:
    int UserId;
    int taskId;
    int priority;
    Task(int uId, int tId, int p) : UserId(uId), taskId(tId), priority(p) {}
};
class TaskManager {
public:
    // Using a vector of Task* for the first method
    vector<Task*> tasks;
    // Constructor that initializes tasks from a 2D vector input
    TaskManager(vector<vector<int>>& tasksInput) {
        for (auto& i : tasksInput) {
            tasks.push_back(new Task(i[0], i[1], i[2]));
        }
    }
    // Add a new task
    void add(int userId, int taskId, int priority) {
        tasks.push_back(new Task(userId, taskId, priority));
    }
    // Edit the priority of an existing task by taskId
    void edit(int taskId, int newPriority) {
        for (auto& task : tasks) {
            if (task->taskId == taskId) {
                task->priority = newPriority;
                return;
            }
        }
    }
    // Remove a task by taskId
    void rmv(int taskId) {
        auto it = remove_if(tasks.begin(), tasks.end(), [taskId](Task* task) {
            return task->taskId == taskId;
        });
        if (it != tasks.end()) {
            delete *it;
            tasks.erase(it);
        }
    }
    // Get the task with the highest priority
    int execTop() {
        if (tasks.empty())
            return -1;
        auto topTask =
            *max_element(tasks.begin(), tasks.end(), [](Task* a, Task* b) {
                return a->priority < b->priority;
            });
        return topTask->taskId;
    }
    // Destructor to clean up dynamically allocated memory
    ~TaskManager() {
        for (auto task : tasks) {
            delete task;
        }
    }
};
// Second approach using priority queue and unordered_map
class TaskManagerPQ {
public:
    priority_queue<tuple<int, int, int>> pq;  // max-heap based on priority
    unordered_map<int, tuple<int, int>> taskMap;  // stores taskId -> (priority, userId)
    // Constructor that initializes tasks from a 2D vector input
    TaskManagerPQ(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            pq.push({priority, taskId, userId});
            taskMap[taskId] = {priority, userId};
        }
    }
    // Add a new task
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId, userId});
        taskMap[taskId] = {priority, userId};
    }
    // Edit the priority of an existing task by taskId
    void edit(int taskId, int newPriority) {
        auto [oldPriority, userId] = taskMap[taskId];
        pq.push({newPriority, taskId, userId});
        taskMap[taskId] = {newPriority, userId};
    }
    // Remove a task by taskId
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    // Get the task with the highest priority
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop(); 
            if (taskMap.find(taskId) != taskMap.end() && taskMap[taskId] == make_tuple(priority, userId)) {
                taskMap.erase(taskId); 
                return userId; 
            }
        } 
        return -1;
    }
};
// Test case to demonstrate both TaskManager and TaskManagerPQ
int main() {
    vector<vector<int>> tasksInput = {{1, 101, 3}, {2, 102, 5}, {3, 103, 1}, {4, 104, 2}};
    // First approach with vector of Task pointers
    TaskManager tm(tasksInput);
    cout << "Exec top (before add): " << tm.execTop() << endl; // Should return 102 (highest priority)
    tm.add(5, 105, 6);  // Adding a new task
    cout << "Exec top (after add): " << tm.execTop() << endl; // Should return 105 (highest priority after add)
    tm.edit(104, 7);  // Editing priority of taskId 104
    cout << "Exec top (after edit): " << tm.execTop() << endl; // Should return 104 (highest priority after edit)
    tm.rmv(103);  // Removing taskId 103
    cout << "Exec top (after rmv): " << tm.execTop() << endl; // Should return 104 (highest priority after remove)
    // Second approach with priority_queue and unordered_map
    TaskManagerPQ tmPQ(tasksInput);
    cout << "Exec top (before add) with PQ: " << tmPQ.execTop() << endl; // Should return 2 (userId)
    tmPQ.add(6, 106, 8);  // Adding a new task
    cout << "Exec top (after add) with PQ: " << tmPQ.execTop() << endl; // Should return 6 (userId 106)
    tmPQ.edit(101, 9);  // Editing priority of taskId 101
    cout << "Exec top (after edit) with PQ: " << tmPQ.execTop() << endl; // Should return 101 (userId 1)
    tmPQ.rmv(102);  // Removing taskId 102
    cout << "Exec top (after rmv) with PQ: " << tmPQ.execTop() << endl; // Should return 106 (highest priority)
    return 0;
}
