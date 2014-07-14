#include <iostream>
#include "stock2.h"

Stock::Stock()
{
	m_company = "no name";
	m_shares = 0.0;
	m_share_val = 0.0;
	m_total_val = 0.0;
}

Stock::Stock(const std::string &company, long shares, double price)
{
	m_company = company;

	if (shares < 0)
	{
		std::cout << "Number of shares can't be negative;"
		<< m_company << " shares set to 0." << std::endl;
		m_shares = 0;
	} else {
		m_shares = shares;
	}

	m_share_val = price;
	set_tot();
}

Stock::~Stock() {}

void Stock::buy(long shares, double price)
{
	if (shares < 0)
	{
		std::cout << "Number of purchased can't be negative. "
		<< "Transaction is aborded." << std::endl;
	} else {
		m_shares += shares;
		m_share_val = price;
		set_tot();
	}
}

void Stock::sell(long shares, double price)
{
	if (shares < 0)
	{
		std::cout << "Number of sold can't be negative. "
		<< "Transaction is aborded." << std::endl;
	} else if (shares > m_shares)
	{
		std::cout << "You can't sell more than you have! "
		<< "Transaction is aborded." << std::endl;
	} else {
		m_shares -= shares;
		m_share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	m_share_val = price;
	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::endl;
	using std::ios_base;

	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << m_company
	<< "\tShares: " << m_shares << endl;
	cout << "\tShare Price: $" << m_share_val;
	cout.precision(2);
	cout << "\tTotal Worth: $" << m_total_val << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

const Stock &Stock::top_val(const Stock &s) const
{
	if (s.m_total_val > m_total_val)
	{
		return s;
	} else {
		return *this;
	}
}