#ifndef BRASS_H
#define BRASS_H

#include <string>

class Brass
{
private:
	std::string full_name;
	long account_number;
	double balance;
public:
	Brass(const std::string &s = "Nullbody", long an = -1, 
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

class BrassPlus : public Brass
{
private:
	double max_loan;
	double rate;
	double owes_bank;
public:
	BrassPlus(const std::string &s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500,
		double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { max_loan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owes_bank = 0; }
};

#endif // BRASS_H
