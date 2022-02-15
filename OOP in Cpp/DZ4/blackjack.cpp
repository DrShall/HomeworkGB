#include "blackjack.h"

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

Blackjack::Blackjack()
{

}
