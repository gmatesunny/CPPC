/*
 * BankAccount.h
 *
 *  Created on: Jun 17, 2016
 *      Author: roshan
 */

#ifndef INCLUDE_BANKACCOUNT_H_
#define INCLUDE_BANKACCOUNT_H_

struct BankAccount {
	int balance;

	BankAccount();
	explicit BankAccount(const int bonus);
	void deposit(const int money);
	bool withdraw(const int money);
	virtual ~BankAccount();
};



#endif /* INCLUDE_BANKACCOUNT_H_ */
