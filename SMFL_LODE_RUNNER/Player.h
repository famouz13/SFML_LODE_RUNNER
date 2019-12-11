#pragma once
#include"Base.h"
//#include"Pole.h"


class Player:virtual public Base {
	std::string nickname;
	int score;
	int cntOfTraps;
public:
	int getScore()const { return score; }
	std::string getNickName()const { return nickname; }
	
	void setNickname(const std::string& gottenName) { nickname = gottenName; }
	void setScore(int newScore) { score = newScore; }
	bool operator<(const Player& obj) { return this->getScore() > obj.getScore(); }
	bool checkGame(Pole& gamep, sf::RenderWindow& window);
	virtual void Move(Pole& gamep,Base& obj)override;
	virtual void Draw(sf::RenderWindow& window)override;

	Player();
	Player(float x, float y,float speed,const std::string&newNick);
	~Player();
};