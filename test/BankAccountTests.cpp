#include "gtest/gtest.h"
#include "BankAccount.h"

namespace {
	TEST(BankAccountTests, InitialEmptyBalance)
	{
		BankAccount acc;
		EXPECT_EQ(0, acc.GetBalance());
	}

	TEST(BankAccountTests, NegativeDeposit)
	{
		BankAccount acc;
		EXPECT_THROW(acc.Deposit(-1), std::invalid_argument);
	}

	TEST(BankAccountTests, BalanceAfterDeposit)
	{
		BankAccount acc;
		acc.Deposit(10);
		EXPECT_EQ(10, acc.GetBalance());
	}

	TEST(BankAccountTests, NegativeWithdrawal)
	{
		BankAccount acc;
		EXPECT_THROW(acc.Withdraw(-5), std::invalid_argument);
	}

	TEST(BankAccountTests, InsufficientBalance)
	{
		BankAccount acc;
		EXPECT_THROW(acc.Withdraw(5), std::out_of_range);

		acc.Deposit(20);
		EXPECT_THROW(acc.Withdraw(21), std::out_of_range);

		EXPECT_NO_THROW(acc.Withdraw(20));
	}
}
