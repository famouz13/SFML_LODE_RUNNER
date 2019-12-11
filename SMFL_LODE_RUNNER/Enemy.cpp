#include"Enemy.h"


void Enemy::Draw(sf::RenderWindow& window) {
	if (getDirection() == 1) {
		sf::Sprite enemy(characterTexture, sf::IntRect(306, 97, 32, 40));
		enemy.setPosition(getX() * 32, getY() * 32 - 5);
		window.draw(enemy);
	}
	else if (getDirection() == 2) {
		sf::Sprite enemy(characterTexture, sf::IntRect(133, 137, 35, 40));
		enemy.setPosition(getX() * 32, getY() * 32 - 5);
		window.draw(enemy);
	}
	else if (getDirection() == 3 || getDirection() == 4) {
		sf::Sprite enemy(characterTexture, sf::IntRect(131, 3, 40, 45));
		enemy.setPosition(getX() * 32, getY() * 32 - 5);
		window.draw(enemy);
	}
	if (getMaxLoss() == getLoss()) setLoss(0);
	else setLoss(getLoss() + 1);
}



void Enemy::Move(Pole& gamep,Base&obj) {
	int movement = rand() % 10;
	int direct = 0;
	if (movement > 3) direct = obj.getDirection() % 4;
	else direct = rand() % 4 + 1;

	if (gamep.gamePole[(int)getY()][(int)getX()] == 'P') {
		if (getLoss() == getMaxLoss()-1) { gamep.gamePole[(int)getY()][(int)getX()] = ' '; setMaxLoss(5); isInPit = false; }
		else { setMaxLoss(20); isInPit = true; }
	}

	if (!isInPit) {
		if (direct == 1) {
			if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX() + 1] == 'W') setX(getX() + 1 * getSpeed());
			else if (gamep.gamePole[(int)getY() + 1][(int)getX()] == 'W' && gamep.gamePole[(int)getY() + 1][(int)getX() + 1] != ' '
				&& getX() + 1 < 32 - 1) {
				setX(getX() + 1 * getSpeed());
				setDirection(1);
			}
		}
		else if (direct == 2) {
			if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX() - 1] == 'W') setX(getX() - 1 * getSpeed());
			else if (gamep.gamePole[(int)getY() + 1][(int)getX()] == 'W' && gamep.gamePole[(int)getY() + 1][(int)getX() - 1] != ' '
				&& getX() - 1 >= 0) {
				setX(getX() - 1 * getSpeed());
				setDirection(2);
			}
		}
		else if (direct == 3) {
			if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() - 1][(int)getX()] != ' ') {
				setY(getY() - 1 * getSpeed());
				setDirection(3);
			}
		}
		else if (direct == 4) {
			if (gamep.gamePole[(int)getY()][(int)getX()] == '=' && gamep.gamePole[(int)getY() + 1][(int)getX()] != 'W') {
				setY(getY() + 1 * getSpeed());
				setDirection(4);
			}
		}
	}
	if (obj.getX() == this->getX() && obj.getY() == this->getY()) { obj.setIsAlive(false); }

}

