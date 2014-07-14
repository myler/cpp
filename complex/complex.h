#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

namespace COMPLEX
{
	class Complex
	{
	private:
		double m_real_part;
		double m_imaginary_part;
	public:
		Complex();
		Complex(double real_part, double imaginary_part);
		~Complex();

		void set_real(double real_part);
		void set_imaginary(double imaginary_part);

		Complex operator+(const Complex &c) const;
		Complex operator-(const Complex &c) const;
		Complex operator*(double n) const;
		Complex operator*(const Complex &c) const;
		Complex operator~() const;

		friend std::ostream &operator<<(std::ostream &os, const Complex &c);
		friend std::istream &operator>>(std::istream &is, Complex &c);
		friend Complex operator*(double n, const Complex &c);
	};
} // COMPLEX

#endif // COMPLEX_H
