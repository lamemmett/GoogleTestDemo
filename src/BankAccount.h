#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

class BankAccount
{
public:
	BankAccount();
	int GetBalance();
	void Deposit(int ammount);
	void Withdraw(int ammount);
private:
	int balance;
};

#endif
