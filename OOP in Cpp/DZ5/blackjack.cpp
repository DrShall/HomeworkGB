#include "blackjack.h"
#include <iostream>

Card::Card(suit cardSuit, value cardValue): suit_(cardSuit), value_(cardValue)
{
	cardBack_ = true;
}

void Card::flip()
{
	cardBack_ = !cardBack_;
}

int Card::getValue()
{
	return value_;
}

void Hand::add(Card* newCard)
{
	cards.push_back(newCard);
}

void Hand::clear()
{
	cards.clear();
}

int Hand::getValue()
{
	int sum = 0;
	for(auto it: cards)
		sum += it->getValue();
	return sum;
}

bool GenericPlayer::isBoosted()
{
	if( getValue() > 21)
		return true;
	else
		return false;
}

void GenericPlayer::bust()
{
	std::cout << name << " ";
	if(isBoosted())
		std::cout << "boosted" << std::endl;
}

Blackjack::Blackjack()
{

}
