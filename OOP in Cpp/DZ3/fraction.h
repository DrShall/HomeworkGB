#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
		int numertor_;
		int denomerator_;
	public:
		Fraction(int numerator, int denomerator);
		void print();
		Fraction operator*(const Fraction& right);
		Fraction operator/(const Fraction& right);
		Fraction operator+(const Fraction& right);
		Fraction operator-(const Fraction& right);
		Fraction operator-();
		bool operator==(const Fraction& right);
		bool operator!=(const Fraction& right);
		bool operator<(const Fraction& right);
		bool operator>(const Fraction& right);
		bool operator<=(const Fraction& right);
		bool operator>=(const Fraction& right);
};

#endif // FRACTION_H
