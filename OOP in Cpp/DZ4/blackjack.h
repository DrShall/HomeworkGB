#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>

enum suit   //масти карт
	{
	spades,   //пики
	clubs,   // крести (трефы)
	diamonds,   //бубны
	hearts   //червы
	};

enum value   //достоинства карт
	{
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 10,   //валет
	queen = 10,   //дама
	king = 10,   //король
	ace = 1   //туз
	};

class Card
{
	protected:
		bool cardBack_;   // 1 - вверх рубашкой, 0 - вверх лицом
		suit suit_;
		value value_;
	public:
		Card(suit cardSuit, value cardValue);
		void flip();
		int getValue();
};

class Hand
{
	protected:
		std::vector<Card*> cards;
	public:
		Hand() = default;
		void add(Card* newCard);
		void clear();
		int getValue();
};

class Blackjack
{
	public:
		Blackjack();
};

#endif // BLACKJACK_H
