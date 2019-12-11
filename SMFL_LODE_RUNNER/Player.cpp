#include "Player.h"
#include<iostream>
#pragma warning(disable:4996)
using namespace std;


void Player::Move(Pole& gamep,Base& obj) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&&cntOfTraps>0) {
		if (gamep.gamePole[(int)getY() + 1][(int)getX()] == 'W') {
			gamep.gamePole[(int)getY()][(int)getX()] = 'P';
			cntOfTraps--;
			}
	}
	 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { 
		if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX()+1] == 'W') setX(getX() + 1*getSpeed());
		else if (gamep.gamePole[(int)getY() + 1][(int)getX()] == 'W' && gamep.gamePole[(int)getY() + 1][(int)getX() + 1] != ' '
			&& getX() + 1 < 32 - 1) {
			setX(getX() +  getSpeed());
			setDirection(1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
		if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX() - 1] == 'W') setX(getX() - 1 * getSpeed());
		else if (gamep.gamePole[(int)getY() + 1][(int)getX()] == 'W' && gamep.gamePole[(int)getY() + 1][(int)getX() - 1] != ' '
			&& getX() - 1 >= 0) {
			setX(getX() -  getSpeed());
			setDirection(2);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() - 1][(int)getX()] != ' ') {
			setY(getY() -  getSpeed());
			setDirection(3);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX()] != 'W') { 
			setY(getY() + getSpeed()); 
			setDirection(4);
		}
		
	}
if (gamep.gamePole[(int)getY()][(int)getX()] == '$') {
		setScore(getScore() + 25); 
		gamep.gamePole[(int)getY()][(int)getX()] = ' ';
		gamep.cntOfMoney--;
	}
};

void Player::Draw(sf::RenderWindow&window) {
	if (getDirection() == 1) { 
		sf::Sprite player(characterTexture, sf::IntRect(21, 210, 40, 45)); 
		player.setPosition(getX() * 32, getY() * 32-5);
		window.draw(player);
	}
	else if (getDirection() == 2) { 
		sf::Sprite player(characterTexture, sf::IntRect(21, 81, 40, 45)); 
		player.setPosition(getX() * 32, getY() * 32-5);
		window.draw(player);
	}
	else if (getDirection() == 3 || getDirection() == 4) { 
		sf::Sprite player(characterTexture, sf::IntRect(21, 11, 40, 45)); 
	    player.setPosition(getX() * 32, getY() * 32-5);
	    window.draw(player);
}
	sf::Text scoreT;
	sf::Font scoreF;
	sf::Text level1;
	level1.setFont(scoreF);
	level1.setFillColor(sf::Color::White);
	level1.setString("LEVEL1");
	level1.setPosition(sf::Vector2f(800, 5));
	string scoreStr;
	char buf[20];
	scoreStr += "SCORE: ";
	scoreStr += _itoa(getScore(),buf,10);
	scoreF.loadFromFile("resources/ldrFONT.ttf");
	scoreT.setFont(scoreF);
	scoreT.setString(scoreStr);
	scoreT.setFillColor(sf::Color::White);
	scoreT.setPosition(sf::Vector2f(800, 30));
	window.draw(scoreT);
	window.draw(level1);
	if (getMaxLoss() == getLoss()) setLoss(0);
	else setLoss(getLoss() + 1);
};

 static sf::Clock start;

bool Player::checkGame(Pole&gamep, sf::RenderWindow& window) {
	if (gamep.exit||!is_Alive()) {
		if (!is_Alive()) {
			window.clear();
			sf::Texture end;
			end.loadFromFile("resources/gOver.jpg");
			sf::Sprite ends(end, sf::IntRect(0,0,800,450));
			ends.setPosition(70,50);
			window.draw(ends);
			window.display();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {};
			return 1;
		}
		else if (gamep.gamePole[(int)getY() - 1][(int)getX()] == 'E') {
			window.clear();
			setScore(getScore() + (8000/start.getElapsedTime().asSeconds()));
			sf::Texture end;
			end.loadFromFile("resources/win.png");
			sf::Sprite ends(end, sf::IntRect(20,20,700,400));
			ends.setPosition(70, 50);
			window.draw(ends);
			window.display();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {};
			return 1;
		}
	}
	return 0;
};

 Player::Player(float x, float y, float speed, const std::string& newNick):Player() {
	 setX(x); setY(y); setSpeed(speed);  setNickname(newNick); setIsAlive(true);
	 setDirection(1);
 };

 Player::Player() { setScore(0); setNickname(""); setIsAlive(0); characterTexture.loadFromFile("resources/player.png"); setLoss(0); setMaxLoss(3); cntOfTraps = 2; };
 Player::~Player() {       };