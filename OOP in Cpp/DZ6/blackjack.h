#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include <string>
#include <ostream>

enum SUIT   //масти карт
	{
	spades,   //пики
	clubs,   // крести (трефы)
	diamonds,   //бубны
	hearts   //червы
	};

enum VALUE   //достоинства карт
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
	jack = 11,   //валет
	queen = 12,   //дама
	king = 13,   //король
	ace = 1   //туз
	};

class Card
{
	protected:
		bool cardBack_;   // 1 - вверх рубашкой, 0 - вверх лицом
		SUIT suit_;
		VALUE value_;
		friend std::ostream& operator<< ( std::ostream& os, const Card& card);
	public:
		Card(SUIT cardSuit, VALUE cardValue);
		void flip();   //перевернуть карту
		int getValue() const;
};

class Hand
{
	protected:
		std::vector<Card*> cards_;
	public:
		Hand();
		void add(Card* newCard);
		void clear();
		int getValue() const;
		virtual ~Hand();
};

class GenericPlayer : public Hand
{
	protected:
		std::string name_;
		friend std::ostream& operator<< ( std::ostream& os, const GenericPlayer& gp);
	public:
		GenericPlayer(const std::string& name) : name_(name) { }
		virtual bool isHitting() const = 0;   //нужна ли еще карта?
		bool isBusted() const;   // у игрока перебор?
		void bust() const;   //объявляет имя игрока и объявляет, что у него перебор
		virtual ~GenericPlayer();
};

class Player : public GenericPlayer
{
	public:
		Player(const std::string& name) : GenericPlayer(name) { }
		virtual bool isHitting() const;   //нужна ли еще карта?
		void win() const;   //выводит имя игрока и сообщает, что он выиграл
		void lose() const;   //выводит имя игрока и сообщает, что он проиграл
		void push() const;   //выводит имя игрока и сообщает, что он сыграл вничью
		virtual ~Player();
};

class House : public GenericPlayer
{
	public:
		House(const std::string& name = "Dealer") : GenericPlayer(name) { }
		virtual bool isHitting() const;
		void flipFirstCard();
		virtual ~House();
};

class Blackjack
{
	public:
		Blackjack();
};

#endif // BLACKJACK_H
