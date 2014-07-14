#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format set_format();
void restrore(format f, precis p);

Brass::Brass(const string &s, long an, double bal)
{
	full_name = s;
	account_number = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Negative Deposit not allowed; "
		<< "Deposit is cancelled." << endl;
	} else {
		balance += amt;
	}
}

void Brass::Withdraw(double amt)
{
	format initial_state = set_format();
	precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdraw amount must be positive; "
		<< "Withdraw cancelled." << endl;
	} else if (amt <= balance)
	{
		balance -= amt;	
	} else {
		cout << "Withdraw amount of $" << amt
		<< " exceeds your balance." << endl;
		cout << "Withdraw cancelled." << endl;
	}

	restrore(initial_state, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initial_state = set_format();
	precis prec = cout.precision(2);

	cout << "Client: " << full_name << endl;
	cout << "Account Number: " << account_number << endl;
	cout << "Balance: $" << balance << endl;

	restrore(initial_state, prec);
}

BrassPlus::BrassPlus(const string &s, long an, double bal,
	double ml, double r) : Brass(s, an, bal)
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
	 : Brass(ba)
{
	max_loan = ml;
	owes_bank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	format initial_state = set_format();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum loan: $" << max_loan << endl;
	cout << "Owed to bank: $" << owes_bank << endl;
	cout.precision(3);
	cout << "Loan rate: " << 100 * rate << "%" << endl;

	restrore(initial_state, prec);
}

void BrassPlus::Withdraw(double amt)
{
	format initial_state = set_format();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	} else if (amt <= bal + max_loan - owes_bank)
	{
		double advance = amt - bal;
		owes_bank += advance * (10. + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	} else {
		cout << "Credit limit exceeded. Transaction cancelled." << endl;
	}

	restrore(initial_state, prec);
}

format set_format()
{
	return cout.setf(std::ios_base::fixed,
		std::ios_base::floatfield);
}

void restrore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}