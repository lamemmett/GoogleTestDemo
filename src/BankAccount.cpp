#include <stdexcept>
#include "BankAccount.h"

BankAccount::BankAccount()
{
	balance = 0;
}

int BankAccount::GetBalance()
{
	return balance;
}

void BankAccount::Deposit(int ammount)
{
	if (ammount < 0)
	{
		throw std::invalid_argument("Negative Deposit");
	}
	else
	{
		balance += ammount;
	}
}

void BankAccount::Withdraw(int ammount)
{
	if (ammount < 0)
	{
		throw std::invalid_argument("Negative Withdrawal");
	}
	else if (ammount > balance)
	{
		throw std::out_of_range("Insufficient Balance");
	}
	else
	{
		balance -= ammount;
	}
}
