#include "gtest/gtest.h"
#include "BankAccount.h"



struct BankAccountTest : testing::Test{

	BankAccount *account;

	BankAccountTest(){
		account = new BankAccount;
	}
	~BankAccountTest(){
		delete account;
	}
};



struct account_state {
	int initial_balance;
	int withdraw_amount;
	int final_balance;
	bool success;
};


struct WithdrawAccountTest : BankAccountTest , testing::WithParamInterface<account_state> {
	WithdrawAccountTest() {
		if (GetParam().initial_balance > 0)
			account->balance = GetParam().initial_balance;
		else
			account->balance = 0;
	}
};




TEST_P(WithdrawAccountTest, FinalBalance) {

	bool success =  account->withdraw(GetParam().withdraw_amount);
	EXPECT_EQ(GetParam().final_balance, account->balance);
	EXPECT_EQ(GetParam().success, success);

}

INSTANTIATE_TEST_CASE_P(Deafult, WithdrawAccountTest, testing::Values(
		account_state{100, 90, 10, true},
		account_state{100, 110, 100, false},
		account_state{-100, -110, 0, false}));



TEST_F(BankAccountTest, BalanceCheck) {
	EXPECT_EQ(0, account->balance);
}


TEST_F(BankAccountTest, CanDepositMoney){
	account->deposit(100);
	EXPECT_EQ(100, account->balance);
}


