#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <string>
#include <iostream>

class DivisionByZero
{
		std::string message_;
	public:
		DivisionByZero(std::string message) : message_(message) { }
		const std::string& getMessage() const { return message_; }
};

namespace mylib
{
	template <typename T>
	double div(T numerator, T denominator)
	{
		if( denominator == 0)
			throw DivisionByZero(" Division by zero");
		return numerator / denominator;
	}
}

class Ex
{
		double x_;
	public:
		Ex(double x) : x_(x) { }
		double getX() const { return x_;}
};

class Bar
{
		double y_;
	public:
		Bar(double y = 0.0) : y_(y) { }
		void set(double a)
		{
			if( (y_ + a) > 100)
				throw Ex(a*y_);
			else
				y_ = a;
		}
};

class OffTheField
{
		int currentPosX_;
		int currentPosY_;
		int newPosX_;
		int newPosY_;
		const std::string messageX = "Going out of field by X!";
		const std::string messageY = "Going out of field by Y!";
	public:
		OffTheField( int posX, int posY, int newX, int newY ) : currentPosX_(posX), currentPosY_(posY), newPosX_(newX), newPosY_(newY) { getError(); }
		void getError();
};

class IllegalCommand
{
		int currentPosX_;
		int currentPosY_;
		int newPosX_;
		int newPosY_;
		const std::string messageX = "Wrong step by X!";
		const std::string messageY = "Wrong step by Y!";
	public:
		IllegalCommand( int posX, int posY, int newX, int newY ) : currentPosX_(posX), currentPosY_(posY), newPosX_(newX), newPosY_(newY) { getError(); }
		void getError();
};

class Robot
{
		int x_;
		int y_;
	public:
		Robot(int x, int y) : x_(x), y_(y) { std::cout << "Starting position: x = " << x_ << " y = " << y_ << std::endl; }
		void move(int offsetX, int offsetY);
};

#endif
