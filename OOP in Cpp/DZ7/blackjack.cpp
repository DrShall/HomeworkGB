#include "blackjack.h"
#include <iostream>

Card::Card(SUIT cardSuit, VALUE cardValue): suit_(cardSuit), value_(cardValue)
{
	cardBack_ = true;
}

void Card::flip()
{
	cardBack_ = !cardBack_;
}

int Card::getValue() const
{
	int val = 0;
	if(!cardBack_)
	{
		val = value_;
	}

	return (val > 10 ? 10 : val);
}

std::ostream& operator<< ( std::ostream& os, const Card& card)
{
	const std::string value[]{ "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	const std::string suit[]{ "\u2660", "\u2663", "\u2666", "\u2665"};   //символы пики, крести, бубны, черви

	if(card.cardBack_)
		os << "XX";
	else
		os << value[card.value_] << suit[card.suit_];

	return os;
}

Hand::Hand() { cards_.reserve(7); }

void Hand::add(Card* newCard)
{
	cards_.push_back(newCard);
}

void Hand::clear()
{
	for(auto it: cards_)
	{
		delete it;
		it = nullptr;
	}
	cards_.clear();
}

int Hand::getValue() const
{
	int sum = 0;
	for(auto it: cards_)
		sum += it->getValue();
	return sum;
}

Hand::~Hand() { clear(); }

bool GenericPlayer::isBusted() const
{
	return ( getValue() > 21);
}

void GenericPlayer::bust() const
{
	std::cout << name_ << " ";
	if(isBusted())
		std::cout << "busted" << std::endl;
}

std::ostream& operator<< ( std::ostream& os, const GenericPlayer& gp)
{
	os << gp.name_ << ":\t";
	if(!gp.cards_.empty())
	{
		for(auto it: gp.cards_)
			os << it << "\t";
		int sum = gp.getValue();
		if(sum)
			os << "( " << sum << " )";
	}
	else
		os << "<empty>";
	return os;
}

bool Player::isHitting() const
{
	std::cout << name_ << ", do you want a hit? (y/n): ";
	char choice;
	std::cin >> choice;
	return (choice == 'y' || choice == 'Y');
}

void Player::win() const
{
	std::cout << name_ << " wins." << std::endl;
}

void Player::lose() const
{
	std::cout << name_ << " loses." << std::endl;
}

void Player::push() const
{
	std::cout << name_ << " pushes." << std::endl;
}

bool House::isHitting() const
{
	return (getValue() <= 16);
}

void House::flipFirstCard()
{
	if(!(cards_.empty()))
		cards_[0]->flip();
	else
		std::cout << "No card." << std::endl;
}

