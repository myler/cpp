#ifndef STOCK2_H
#define STOCK2_H

#include <string>

class Stock
{
private:
	std::string m_company;
	int m_shares;
	double m_share_val;
	double m_total_val;
	void set_tot() { m_total_val = m_shares * m_share_val; }
public:
	Stock();
	Stock(const std::string &company, long shares = 0, double price = 0.0);
	~Stock();

	void buy(long shares, double price);
	void sell(long shares, double price);
	void update(double price);
	void show() const;
	const Stock &top_val(const Stock &s) const;
};

#endif // STOCK2_H
