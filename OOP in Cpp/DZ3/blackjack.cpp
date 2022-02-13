#include "blackjack.h"

Card::Card(suit cardSuit, value cardValue): suit_(cardSuit), value_(cardValue) { }

void Card::Flip()
{
	cardBack_ = !cardBack_;
}

int Card::getValue()
{
	return value_;
}

Blackjack::Blackjack()
{

}
