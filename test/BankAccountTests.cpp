#include "gtest/gtest.h"
#include "BankAccount.h"

namespace {

class BankAccountTests : public ::testing::Test {
protected:
	BankAccount acc;
};

TEST_F(BankAccountTests, InitialEmptyBalance)
{
	EXPECT_EQ(0, acc.GetBalance());
}

TEST_F(BankAccountTests, NegativeDeposit)
{
	EXPECT_THROW(acc.Deposit(-1), std::invalid_argument);
}

TEST_F(BankAccountTests, BalanceAfterDeposit)
{
	acc.Deposit(10);
	EXPECT_EQ(10, acc.GetBalance());
}

TEST_F(BankAccountTests, NegativeWithdrawal)
{
	EXPECT_THROW(acc.Withdraw(-5), std::invalid_argument);
}

TEST_F(BankAccountTests, InsufficientBalance)
{
	EXPECT_THROW(acc.Withdraw(5), std::out_of_range);

	acc.Deposit(20);
	EXPECT_THROW(acc.Withdraw(21), std::out_of_range);

	EXPECT_NO_THROW(acc.Withdraw(20));
}

} // namespace
