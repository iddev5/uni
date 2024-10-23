#include <iostream>
using namespace std;

class Account {
  char depositor_name[32];
  unsigned long account_no;
  char type[8];
  unsigned long balance;
public:
  void getdata() {
    cout << "Enter details of account: " << endl;
    cout << "Depositor Name: "; 
    cin >> depositor_name;

    cout << "Account Number: ";
    cin >> account_no;

    cout << "Account Type: ";
    cin >> type;

    cout << "Account Balance: ";
    cin >> balance;
    cout << endl;    
  }

  void deposit(unsigned long amount) {
    balance += amount;
  }

  void withdraw(unsigned long amount) {
    if (amount > balance) {
      cout << "Insufficient balance. Cannot withdraw" << endl;
      return;
    }
    balance -= amount;
  }
  
  void display() {
    cout << "Account Details: " << endl;
    cout << "Name: " << depositor_name << endl;
    cout << "Balance: " << balance << endl;
  }
};

int main() {
  Account acc;
  acc.getdata();
  
  while (true) {
    int choice, amount;
    cout << "1. Deposit\n2. Withdraw\n3. Display\n4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1: 
        cout << "Enter amount to deposit: ";
        cin >> amount;
        acc.deposit(amount);
        break;
      case 2: 
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        acc.withdraw(amount);
        break;
      case 3:
        acc.display();
        break;
      case 4:
        return 0;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  }
  
  return 0;
}