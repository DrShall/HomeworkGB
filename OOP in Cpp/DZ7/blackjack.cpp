#include "blackjack.h"
#include <iostream>
#include <algorithm>

Card::Card(SUIT cardSuit, VALUE cardValue): suit_(cardSuit), value_(cardValue)
{
	cardBack_ = false;
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
	if(cards_.empty())
		return 0;
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
	std::cout << name_ << " busted" << std::endl;
}

std::ostream& operator<< ( std::ostream& os, const GenericPlayer& gp)
{
	os << gp.name_ << ":\t";
	if(!gp.cards_.empty())
	{
		for(auto it: gp.cards_)
			os << *it << "\t";
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

void Deck::populate()
{
	clear();
	SUIT suits;
	VALUE values;
	for( int s = spades; s <= hearts; ++s)
		for( int v = ace; v <= king; ++v)
			add(new Card( static_cast<SUIT>(s), static_cast<VALUE>(v)));
}

void Deck::shuffle()
{
	std::random_shuffle( cards_.begin(), cards_.end());
}

void Deck::deal(Hand &inHand)
{
	if(cards_.empty())
		std::cout << "Unable to deal." << std::endl;
	else
	{
		inHand.add(cards_.back());
		cards_.pop_back();
	}
}

void Deck::additionalCards(GenericPlayer &aGP)
{
	while( !aGP.isBusted() && aGP.isHitting())
	{
		deal(aGP);
		std::cout << aGP << std::endl;
		if(aGP.isBusted())
			aGP.bust();
	}
}

Blackjack::Blackjack(const std::vector<std::string>& names)
{
	for( auto it: names)
	{
		players_.push_back(Player(it));
		deck_.populate();
		deck_.shuffle();
	}
}

void Blackjack::play()
{
	for( int i = 0; i < 2; ++i)
	{
		for( auto p: players_)
		{
			deck_.deal(p);
		}
		deck_.deal(house_);
	}
	house_.flipFirstCard();

	for(auto p: players_)
		deck_.additionalCards(p);

	house_.flipFirstCard();
	deck_.additionalCards(house_);

	if(house_.isBusted())
	{
		for( auto p: players_)
			if( !p.isBusted())
				p.win();
	}
	else
	{
		for( auto p: players_)
		{
			if( !p.isBusted())
			{
				if(p.getValue() > house_.getValue())
					p.win();
				else if(p.getValue() < house_.getValue())
					p.lose();
				else
					p.push();
			}
		}
	}
	for(auto p: players_)
		p.clear();
}
