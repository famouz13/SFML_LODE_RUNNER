#include "Menu.h"
#include<Windows.h>
#include<iostream>
#pragma warning(disable:4996)

#define HEIGHT 1000
#define WIDTH 600

#define widthM 1000
#define heightM 600

void Menu::PrintMenu(sf::RenderWindow& window) {
	for (int i = 0; i < cnt_of_menu_Puncts; i++) {
		window.draw(menuText[i]);
	}
	sf::Texture texture; //текстура лого 
	texture.loadFromFile("resources/lodeRlogo.png");
	sf::Sprite sprite(texture);
	sprite.move(sf::Vector2f(widthM/ 3, heightM / 7));
	window.draw(sprite);
};

void Menu::moveUp() { //перемещение вниз/вверх по меню
	if (selected>= 0) {
		menuText[selected].setFillColor(sf::Color::White);
		if (selected <= 0) selected = cnt_of_menu_Puncts - 1;
		else selected--;
		menuText[selected].setFillColor(sf::Color::Red);
	}
};

void Menu::moveDown() {
	if(selected<= cnt_of_menu_Puncts-1) {
		menuText[selected].setFillColor(sf::Color::White);
		if (selected >= cnt_of_menu_Puncts-1) selected = 0;
		else selected++;
		menuText[selected].setFillColor(sf::Color::Red);
	}
};

Menu::Menu(float width, float height) { //конструктор меню
	if (!menuFont.loadFromFile("resources/ldrTest.otf")) {

	}
	
	selected = 0;
	menuText[0].setFont(menuFont);
	menuText[0].setFillColor(sf::Color::Red);
	menuText[0].setString("Play");
	menuText[0].setPosition(sf::Vector2f(width / 2.5,height / (cnt_of_menu_Puncts +1) *2));
	
	menuText[1].setFont(menuFont);
	menuText[1].setFillColor(sf::Color::White);
	menuText[1].setString("INFO");
	menuText[1].setPosition(sf::Vector2f(width / 2.5, height / (cnt_of_menu_Puncts + 2) *3));

	menuText[2].setFont(menuFont);
	menuText[2].setFillColor(sf::Color::White);
	menuText[2].setString("About author");
	menuText[2].setPosition(sf::Vector2f(width / 2.5, height / (cnt_of_menu_Puncts + 2.5) * 4));

	menuText[3].setFont(menuFont);
	menuText[3].setFillColor(sf::Color::White);
	menuText[3].setString("TOP5");
	menuText[3].setPosition(sf::Vector2f(width / 2.5, height / (cnt_of_menu_Puncts + 3) * 5));

	menuText[4].setFont(menuFont);
	menuText[4].setFillColor(sf::Color::White);
	menuText[4].setString("Exit");
	menuText[4].setPosition(sf::Vector2f(width / 2.5, height / (cnt_of_menu_Puncts + 3.5) * 6));


}

Menu::~Menu() {};

void Menu::printSelected(sf::RenderWindow& window) { //обработка пунктов меню
	int selectedP = getSelected();

	sf::Text selectedMenuPunct;
	sf::Font forSelected;

	forSelected.loadFromFile("resources/ldrFONT.ttf");
	selectedMenuPunct.setFont(forSelected);
	selectedMenuPunct.setFillColor(sf::Color::White);
	selectedMenuPunct.setPosition(sf::Vector2f(widthM / 3, heightM/ 12));

	window.clear();

	sf::Text toContinue;
	toContinue.setFont(forSelected);
	toContinue.setFillColor(sf::Color::Cyan);
	toContinue.setString("To continue press BackSpace...");
	toContinue.setPosition(sf::Vector2f(300, 500));

	switch (selectedP) {
	case 0: {
		selectedMenuPunct.setString("Game Started!");
		break;
	}
	case 1: {
		selectedMenuPunct.setString("INFO!");

		sf::Texture info_t;
		info_t.loadFromFile("resources/images.png");
		sf::Sprite info_sprite(info_t);
		info_sprite.move(sf::Vector2f(widthM/2+50, heightM / 5.5));

		sf::Text info_txt2;
		info_txt2.setFont(forSelected);
		info_txt2.setFillColor(sf::Color::Yellow);
		info_txt2.setPosition(sf::Vector2f(widthM / 10 - 50, heightM -300));
		info_txt2.setString("You have score bar in right top corner\nIf you want to Exit press Esc.\nGood Luck!");

		sf::Text info_txt;
		info_txt.setFont(forSelected);
		info_txt.setFillColor(sf::Color::Magenta);
		info_txt.setPosition(sf::Vector2f(widthM / 10-50, heightM / 5));
		info_txt.setString("You can move\n your character\n by using\n the keyboard arrows->");

		window.draw(info_sprite);
		window.draw(info_txt2);
		window.draw(info_txt);
		break;
	}
	case 2: {
		sf::Texture logo;
		logo.loadFromFile("resources/stepLogo.png");
		sf::Sprite itStep(logo);
		itStep.move(sf::Vector2f(400,200));

		selectedMenuPunct.setFillColor(sf::Color::Green);
		selectedMenuPunct.setPosition(sf::Vector2f(300, 100));
		selectedMenuPunct.setString("DEV.KARPOV EVGENIY SDP/191!\n ALL RIGHTS RESERVED (C);");

		window.draw(itStep);
		break;
	}
	case 3: {
		selectedMenuPunct.setPosition(sf::Vector2f(widthM / 8, heightM / 8));
		PrintRaiting(window);
		selectedMenuPunct.setString("HERE SHOULD BE SOME GOOD PLAYERS...");
		break;
	}
	}
	
	window.draw(toContinue);
	window.draw(selectedMenuPunct);
	window.display();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace));

}



//запуск меню игры
void Menu::menuStart() {
	Game LODErunner;
	sf::Event event;
	sf::String nicknameSf;
	std::string nickname;
	Player pl1;

	sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "LODE RUNNER");
	window.setFramerateLimit(60);

	Menu LODE_RUNNER_MENU(window.getSize().x, window.getSize().y); //окно игры/меню


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (getIsEntered()) getNickname(window, event, nicknameSf);

            else {
				nickname = nicknameSf.toAnsiString();
				pl1.setNickname(nickname);

				if (event.type == sf::Event::Closed) { LODE_RUNNER_MENU.CompareRaiting(pl1); window.close(); }
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Space) while (!event.key.code == sf::Keyboard::Space) {}
					if (event.key.code == sf::Keyboard::Escape) {LODE_RUNNER_MENU.CompareRaiting(pl1); window.close(); }
					if (event.key.code == sf::Keyboard::Up)      LODE_RUNNER_MENU.moveUp();
					if (event.key.code == sf::Keyboard::Down)    LODE_RUNNER_MENU.moveDown();
					if (event.key.code == sf::Keyboard::Enter && LODE_RUNNER_MENU.getSelected() == 0) { LODErunner.Play(window,pl1); }
					if (event.key.code == sf::Keyboard::Enter && LODE_RUNNER_MENU.getSelected() == 1) { LODE_RUNNER_MENU.printSelected(window); }
					if (event.key.code == sf::Keyboard::Enter && LODE_RUNNER_MENU.getSelected() == 2) { LODE_RUNNER_MENU.printSelected(window); }
					if (event.key.code == sf::Keyboard::Enter && LODE_RUNNER_MENU.getSelected() == 3) { LODE_RUNNER_MENU.PrintRaiting(window); }
					if (event.key.code == sf::Keyboard::Enter && LODE_RUNNER_MENU.getSelected() == 4) { LODE_RUNNER_MENU.CompareRaiting(pl1); window.close();  }
				}

			window.clear();
			// Выполняем необходимые действия по отрисовке
			LODE_RUNNER_MENU.PrintMenu(window);
			window.display();
			}
		}
	}
	std:: cout << pl1.getNickName() << std::endl << pl1.getScore();
}


void Menu::getNickname(sf::RenderWindow&window,sf::Event&event,sf::String& nickname) {
	sf::Text text;
	sf::Font nick;
	nick.loadFromFile("resources/ldrFONT.ttf");
	text.setFont(nick);
	text.setFillColor(sf::Color::Cyan
	);
	text.setPosition(sf::Vector2f(250, 80));

	sf::Text output;
	output.setFont(nick);
	output.setPosition(sf::Vector2f(250, 50));
	output.setFillColor(sf::Color::White);
	output.setString("ENTER YOUR NICKNAME:");
	window.draw(output);
	window.display();
	
    if (event.type == sf::Event::TextEntered) {
			nickname += static_cast<char>(event.text.unicode);
			text.setString(nickname);
			Sleep(60);
	}
	window.draw(output);
	window.draw(text);
	window.display();
	if (event.key.code == sf::Keyboard::Enter) {	Sleep(300); isEntered(false); }

}

void Menu::CompareRaiting(Player& pl1) {
	//----------------------------------------------------LOAD
	std::ifstream saveList;
	saveList.open("RATE.txt");
	if (saveList.is_open()) {
		while (!saveList.eof()) {
			Player obj;
			std::string temp;
			int tempScore = 0;
			char buf[255];
			saveList.getline(buf, 255);
			temp = buf;
			saveList >> tempScore;
			saveList.ignore();
			if (temp == "") temp = "UKNOWN";
			obj.setNickname(temp);
			obj.setScore(tempScore);
			rateList.push_back(obj);
			//saveList >> tempScore >> tempScore;
		}
		saveList.close();
	}
	//----------------------------------------------------SORT/SAVE
	rateList.push_back(pl1);
	std::sort(std::begin(rateList), std::end(rateList));
	std::ofstream loadList;
	loadList.open("RATE.txt");
	if (loadList.is_open()) {
		std::vector<Player>::iterator loadIter = rateList.begin();
		for (int i = 0; i < rateList.size()&&i<5; i++) {
				Player toSave = *loadIter;
				loadIter++;
				loadList << toSave.getNickName() << std::endl << toSave.getScore() << std::endl;
			}
		loadList.close();
	}
}

void Menu::PrintRaiting(sf::RenderWindow&window) {
	window.clear();

	std::ifstream readFile;
	sf::Font raitingFont;
	sf::Text players;
    raitingFont.loadFromFile("resources/ldrFONT.ttf");

	sf::Text scoreTable;
	scoreTable.setFont(raitingFont);
	scoreTable.setFillColor(sf::Color::White);
	scoreTable.setPosition(300, 20);
	scoreTable.setString("PLAYERS:\t\tSCORE:");
	players.setFont(raitingFont);


	readFile.open("RATE.TXT");
	if (readFile.is_open()) {
		int i = 0;
		while (!readFile.eof()&&i<5) {
			if (i == 0) players.setFillColor(sf::Color::Magenta);
			else players.setFillColor(sf::Color::Cyan);

			char tempNick[255];
			std::string buffer;
			int tempScore=0;

			buffer += itoa(i+1, tempNick, 10);
			buffer += ".";
			readFile.getline(tempNick, 50);
			readFile >> tempScore;
			readFile.ignore();
			buffer += tempNick;
			buffer += "\t\t";
			buffer += _itoa(tempScore,tempNick,10);

			players.setString(buffer);
			players.setPosition(sf::Vector2f(300, i*50+60));
			i++;
			window.draw(players);
		}
		window.draw(scoreTable);
		window.display();
		readFile.close();
	}
	else {
		scoreTable.setString("HERE SHOULD BE GOOD PLAYERS...");
		scoreTable.setPosition(sf::Vector2f(300, 300));
		scoreTable.setFillColor(sf::Color::Blue);
		window.draw(scoreTable);
		window.display();
	}
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace));
}
//-------------------------------------game.h
void Game::Pause(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("resources/ldrTest.otf");
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(500, 400));
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { window.draw(text); }
}



void Game::Play(sf::RenderWindow& window, Player& pl1) {
	sf::Event event;
	static sf::Clock start;
	initGame(pl1);
	while (true) {
		window.pollEvent(event);
		gamep.PoleDraw(window);
		en1.Draw(window);
		en2.Draw(window);
		en3.Draw(window);
		en4.Draw(window);
		pl1.Draw(window);
		if (pl1.getLoss() == 0) {
			pl1.Move(gamep, pl1);
		}
		if (en1.getLoss() == 0) {
			en1.Move(gamep, pl1);
		}
		if (en2.getLoss() == 0) {
			en2.Move(gamep, pl1);
		}
		if (en3.getLoss() == 0) {
			en3.Move(gamep, pl1);
		}
		if (en4.getLoss() == 0) {
			en4.Move(gamep, pl1);
		}

		window.display();
		isGameEnded = pl1.checkGame(gamep, window);
		if (isGameEnded) break;
		if (event.key.code == sf::Keyboard::Escape) break;
		if (event.key.code == sf::Keyboard::Pause) { Pause(window); }
	}
	int time = start.getElapsedTime().asSeconds();
	std::cout << time << std::endl;
}

void Game::initGame(Player& pl1) {
	pl1.setDirection(1); pl1.setX(1); pl1.setY(15); pl1.setSpeed(1); pl1.setIsAlive(true);
	en1.setDirection(2); en1.setX(20); en1.setY(15); en1.setSpeed(1);
	en2.setDirection(2); en2.setX(23); en2.setY(9); en2.setSpeed(1);
	en3.setDirection(2); en3.setX(7); en3.setY(5); en3.setSpeed(1);
	en4.setDirection(2); en4.setX(25); en4.setY(3); en4.setSpeed(1);
}