#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

class BankAccount {
private:
	enum { BANK_NUM_LEN = 40, NAME_LEN = 60 };
	char name[NAME_LEN];
	char bank_num[BANK_NUM_LEN];
	double balance;
public:
	BankAccount(const char * name_init = "empty", const char * bank_num_init = "0", double balance_init = 0.0);
	~BankAccount();
	void show() const;
	void acquire(double money);
	void spend(double money);
};

#endif
