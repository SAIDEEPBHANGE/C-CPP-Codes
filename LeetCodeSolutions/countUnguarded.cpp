#include <bits/stdc++.h>
using namespace std;
class Bank {
private:
    vector<long long>& balanceDetails;
    int n;
public:
    Bank(vector<long long>& balance)
        : balanceDetails(balance), n(balance.size()) {}
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n)
            return false;
        if (balanceDetails[account1 - 1] < money)
            return false;
        balanceDetails[account1 - 1] -= money;
        balanceDetails[account2 - 1] += money;
        return true;
    }
    bool deposit(int account, long long money) {
        if (account < 1 || account > n)
            return false;
        balanceDetails[account - 1] += money;
        return true;
    }
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n)
            return false;
        if (balanceDetails[account - 1] < money)
            return false;
        balanceDetails[account - 1] -= money;
        return true;
    }
};
// ✅ Helper to print balances
void printBalances(const vector<long long>& balance) {
    cout << "Current balances: ";
    for (auto b : balance) cout << b << " ";
    cout << "\n";
}
// ✅ Test runner
int main() {
    vector<long long> balance = {1000, 2000, 3000, 4000, 5000};
    Bank bank(balance);
    cout << "Initial ";
    printBalances(balance);
    // Test 1: Valid transfer
    cout << "\nTest 1: Transfer 500 from account 1 -> 3\n";
    cout << (bank.transfer(1, 3, 500) ? "Success\n" : "Failed\n");
    printBalances(balance);
    // Test 2: Withdraw success
    cout << "\nTest 2: Withdraw 1000 from account 2\n";
    cout << (bank.withdraw(2, 1000) ? "Success\n" : "Failed\n");
    printBalances(balance);
    // Test 3: Withdraw failure (too much money)
    cout << "\nTest 3: Withdraw 10000 from account 2 (should fail)\n";
    cout << (bank.withdraw(2, 10000) ? "Success\n" : "Failed\n");
    printBalances(balance);
    // Test 4: Deposit success
    cout << "\nTest 4: Deposit 2000 into account 5\n";
    cout << (bank.deposit(5, 2000) ? "Success\n" : "Failed\n");
    printBalances(balance);
    // Test 5: Invalid account (out of range)
    cout << "\nTest 5: Transfer 100 from account 6 -> 1 (should fail)\n";
    cout << (bank.transfer(6, 1, 100) ? "Success\n" : "Failed\n");
    printBalances(balance);
    // Test 6: Chain transactions
    cout << "\nTest 6: Deposit 1000 into account 1, then transfer to account 4\n";
    bank.deposit(1, 1000);
    bank.transfer(1, 4, 500);
    printBalances(balance);
    cout << "\n✅ All tests completed.\n";
    return 0;
}