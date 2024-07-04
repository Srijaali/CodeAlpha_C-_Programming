// Banking System
// A C++ project designed with an object-oriented
// approach, with classes for customers, accounts,
// transactions, and banking services. Features included
// creating and managing customers, accounts, and
// transactions, as well as performing banking services
// such as withdrawals, deposits, and transfers. It also
// allows customers to view their account information,
// including account balances, recent transactions, and
// other details.

#include <iostream>
#include <string>
using namespace std;

// Transaction Class
class Transaction {
public:
    Transaction(const string& type, double amount) : type(type), amount(amount) {}

    string getType() const {
        return type;
    }

    double getAmount() const {
        return amount;
    }

private:
    string type;
    double amount;
};

// Account Class
class Account {
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance), transactionCount(0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        addTransaction(new Transaction("Deposit", amount));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            addTransaction(new Transaction("Withdrawal", amount));
            return true;
        }
        return false;
    }

    void addTransaction(Transaction* transaction) {
        if (transactionCount < 100) {
            transactions[transactionCount++] = transaction;
        }
    }

    Transaction** getTransactions() const {
        return const_cast<Transaction**>(transactions);
    }

    int getTransactionCount() const {
        return transactionCount;
    }

private:
    int accountNumber;
    double balance;
    Transaction* transactions[100]; // Assume an account can have a maximum of 100 transactions
    int transactionCount;
};

// Customer Class
class Customer {
public:
    Customer(const string& name, int id) : name(name), id(id), accountCount(0) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    void addAccount(Account* account) {
        if (accountCount < 10) {
            accounts[accountCount++] = account;
        }
    }

    Account** getAccounts() const {
        return const_cast<Account**>(accounts);
    }

    int getAccountCount() const {
        return accountCount;
    }

private:
    string name;
    int id;
    Account* accounts[10]; // Assume a customer can have a maximum of 10 accounts
    int accountCount;
};

// Main Program
int main() {
    // Create customers
    Customer customer1("John Doe", 1);
    Customer customer2("Jane Smith", 2);

    // Create accounts
    Account account1(1001, 500.0);
    Account account2(1002, 1000.0);

    // Add accounts to customers
    customer1.addAccount(&account1);
    customer2.addAccount(&account2);

    // Perform transactions
    account1.deposit(200.0);
    account1.withdraw(150.0);
    account2.deposit(300.0);
    account2.withdraw(500.0);

    // Display account information
    cout << "Customer: " << customer1.getName() << ", ID: " << customer1.getId() << endl;
    Account** accounts1 = customer1.getAccounts();
    for (int i = 0; i < customer1.getAccountCount(); ++i) {
        Account* account = accounts1[i];
        cout << "  Account Number: " << account->getAccountNumber() << ", Balance: " << account->getBalance() << endl;

        Transaction** transactions = account->getTransactions();
        for (int j = 0; j < account->getTransactionCount(); ++j) {
            Transaction* transaction = transactions[j];
            cout << "    Transaction: " << transaction->getType() << ", Amount: " << transaction->getAmount() << endl;
        }
    }

    cout << "Customer: " << customer2.getName() << ", ID: " << customer2.getId() << endl;
    Account** accounts2 = customer2.getAccounts();
    for (int i = 0; i < customer2.getAccountCount(); ++i) {
        Account* account = accounts2[i];
        cout << "  Account Number: " << account->getAccountNumber() << ", Balance: " << account->getBalance() << endl;

        Transaction** transactions = account->getTransactions();
        for (int j = 0; j < account->getTransactionCount(); ++j) {
            Transaction* transaction = transactions[j];
            cout << "    Transaction: " << transaction->getType() << ", Amount: " << transaction->getAmount() << endl;
        }
    }

    return 0;
}
