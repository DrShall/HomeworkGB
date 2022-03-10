#include "myclasses.h"
#include <math.h>

void OffTheField::getError()
{
	if( newPosX_ < 1 || newPosX_ > 10 )
		std::cout << std::endl << messageX << std::endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
				  << newPosX_ << " : " << newPosY_ << " )" << std::endl;
	if( newPosY_ < 1 || newPosY_ > 10 )
		std::cout << std::endl << messageY << std::endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
				  << newPosX_ << " : " << newPosY_ << " )" << std::endl;
}

void IllegalCommand::getError()
{
	if( abs( currentPosX_ - newPosX_ ) > 1 )
		std::cout << std::endl << messageX << std::endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
				  << newPosX_ << " : " << newPosY_ << " )" << std::endl;
	if( abs( currentPosY_ - newPosY_ ) > 1 )
		std::cout << std::endl << messageY << std::endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
				  << newPosX_ << " : " << newPosY_ << " )" << std::endl;
}

void Robot::move(int offsetX, int offsetY)
{
	int newX = x_ + offsetX;
	int newY = y_ + offsetY;
	if( abs( offsetX ) > 1 || abs( offsetY ) > 1 )
		throw IllegalCommand( x_, y_, newX, newY );
	else if( newX < 1 || newX > 10 || newY < 1 || newY > 10 )
		throw OffTheField( x_, y_, newX, newY );

	std::cout << "Robot stepped from ( " << x_ << " : " << y_ << " ) to ( " << newX << " : " << newY << " )" << std::endl;
	x_ = newX;
	y_ = newY;
}
