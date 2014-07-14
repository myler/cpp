#include <iostream>
#include "complex.h"

namespace COMPLEX {
	Complex::Complex()
	{
		m_real_part = m_imaginary_part = 0.0;
	}

	Complex::Complex(double real_part, double imaginary_part)
	{
		m_real_part = real_part;
		m_imaginary_part = imaginary_part;
	}

	Complex::~Complex() {}

	void Complex::set_real(double real_part)
	{
		m_real_part = real_part;
	}

	void Complex::set_imaginary(double imaginary_part)
	{
		m_imaginary_part = imaginary_part;
	}

	Complex Complex::operator+(const Complex &c) const
	{
		// Complex temp;
		// temp.m_real_part = m_real_part + c.m_real_part;
		// temp.m_imaginary_part = m_imaginary_part + c.m_imaginary_part;

		// return temp;
		return Complex(m_real_part + c.m_real_part, m_imaginary_part + c.m_imaginary_part);
	}

	Complex Complex::operator-(const Complex &c) const
	{
		return Complex(m_real_part - c.m_real_part, m_imaginary_part - c.m_imaginary_part);
	}

	Complex Complex::operator~() const
	{
		return Complex(m_real_part, -m_imaginary_part);
	}

	Complex Complex::operator*(double n) const
	{
		return Complex(n * m_real_part, n * m_imaginary_part);
	}

	Complex operator*(double n, const Complex &c)
	{
		return c * n;
	}

	Complex Complex::operator*(const Complex &c) const
	{
		Complex temp;
		temp.m_real_part = m_real_part * c.m_real_part 
		- m_imaginary_part * c.m_imaginary_part;
		temp.m_imaginary_part = m_real_part * c.m_real_part 
		+ m_imaginary_part * c.m_imaginary_part;

		return temp;
	}

	std::ostream &operator<<(std::ostream &os, const Complex &c)
	{
		os << "(" << c.m_real_part << ", " << c.m_imaginary_part << "i)";

		return os;
	}

	std::istream &operator>>(std::istream &is, Complex &c)
	{
		double real_part, imaginary_part;
		std::cout << "real: ";
		is >> real_part;
		std::cout << "imaginary: ";
		is >> imaginary_part;
		std::cout << std::endl;
		c.set_real(real_part);
		c.set_imaginary(imaginary_part);

		return is;
	}
} // COMPLEX
