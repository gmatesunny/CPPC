/*
 * BankAccount.cpp
 *
 *  Created on: Jun 17, 2016
 *      Author: roshan
 */

#include "BankAccount.h"

BankAccount::BankAccount() {
	// TODO Auto-generated constructor stub
	balance = 0;
}

BankAccount::~BankAccount() {


}

BankAccount::BankAccount(const int bonus) {

	if (bonus > 0)
		balance += bonus;
	else
		balance = 0;

}

void BankAccount::deposit(const int money) {

	if ( money >= 0)
		balance += money;
}

bool BankAccount::withdraw(const int money) {

	if ( money > 0 && money <= balance) {
		balance -= money;
		return true;
	}
	else {
		return false;
	}

}
