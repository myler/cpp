#ifndef DMA_H
#define DMA_H

#include <iostream>

class base_DMA
{
private:
	char *label;
	int rating;
public:
	base_DMA(const char *l = "null", int r = 0);
	base_DMA(const base_DMA &rs);
	virtual ~base_DMA();

	base_DMA &operator=(const base_DMA &rs);

	friend std::ostream &operator<<(std::ostream &os,
		const base_DMA &rs);
};

class lacks_DMA : public base_DMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacks_DMA(const char *c = "black", const char *l = "null",
		int r = 0);
	lacks_DMA(const char *c, const base_DMA &rs);

	friend std::ostream &operator<<(std::ostream &os,
		const lacks_DMA &rs);
};

class has_DMA : public base_DMA
{
private:
	char *style;
public:
	has_DMA(const char *s = "none", const char *l = "null",
		int r = 0);
	has_DMA(const char *s, const base_DMA &rs);
	has_DMA(const has_DMA &hs);
	~has_DMA();

	has_DMA &operator=(const has_DMA &rs);

	friend std::ostream &operator<<(std::ostream &os,
		const has_DMA &rs);
};

#endif // DMA_H
