#include <iostream>
using namespace std;

class BankAccount {
	double balance;
	
	public:
		BankAccount(){
			balance = 0.0;
		}
		
		BankAccount(double initialbalance): balance(initialbalance){}
		
		BankAccount(const BankAccount &account): balance(account.balance){}
		
		void deduct(double amount){
			balance -= amount;
		}
		
		double getbalance() const {
			return balance;
		}
	
};

int main(){
	BankAccount a1;
	cout << "Balnce of Account1: $" << a1.getbalance() << "\n" << endl;
	
	BankAccount a2(1000.0);
	cout << "Balance of Account2: $" << a2.getbalance() << "\n" << endl;
	
	BankAccount a3(a2);
	a3.deduct(200.0);
	cout << "Balance of Account3 after deduction: $" << a3.getbalance() << endl;
	cout << "Balance of Account2: $" << a2.getbalance() << endl;
}
