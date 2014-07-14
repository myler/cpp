#include <cstring>
#include "dma.h"

base_DMA::base_DMA(const char *l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

base_DMA::base_DMA(const base_DMA &rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

base_DMA::~base_DMA()
{
	delete [] label;
}

base_DMA &base_DMA::operator=(const base_DMA &rs)
{
	if (this == &rs)
	{
		return *this;
	}

	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;

	return *this;
}

std::ostream &operator<<(std::ostream &os, const base_DMA &rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;

	return os;
}

lacks_DMA::lacks_DMA(const char *c, const char *l, int r)
 : base_DMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

lacks_DMA::lacks_DMA(const char *c, const base_DMA &rs)
 : base_DMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream &operator<<(std::ostream &os, const lacks_DMA &ls)
{
	os << (const base_DMA &) ls;
	os << "Color: " << ls.color << std::endl;

	return os;
}

has_DMA::has_DMA(const char *s, const char *l, int r)
 : base_DMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

has_DMA::has_DMA(const has_DMA &hs)
 : base_DMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

has_DMA::~has_DMA()
{
	delete [] style;
}

has_DMA &has_DMA::operator=(const has_DMA &hs)
{
	if (this == &hs)
	{
		return *this;
	}

	base_DMA::operator=(hs);
	delete [] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);

	return *this;
}

std::ostream &operator<<(std::ostream &os, const has_DMA &hs)
{
	os << (const base_DMA &) hs;
	os << "Style: " << hs.style << std::endl;

	return os;
}