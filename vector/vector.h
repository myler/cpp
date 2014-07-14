#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		// RECT for rectangular, POL for Polar modes
	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode;

		//private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();

		double x_val() const { return x; }
		double y_val() const { return y; }
		double mag_val() const { return mag; }
		double ang_val() const { return ang; }
		void polar_mode();
		void rect_mode();

		//operator overloading
		Vector operator+(const Vector &b) const;
		Vector operator-(const Vector &b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		//friends
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream &
			   operator<<(std::ostream &os, const Vector &v);
	};
} // end namespace VECTOR

#endif // VECTOR_H
