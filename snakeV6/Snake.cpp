
#include "Snake.h"
#include<iostream>
#include<list>
#include<string>
#include<conio.h>
#include<Windows.h>
#include <ctime>
#include <chrono>
#include<string>
#include <thread>

using namespace std;
Snake::Snake()
{
	width = 20; height = 20;
	direction = "stop";
	press = false;
	score = 0;
	scorecheck = 0;
	check_small = false;

}
void Snake::initial() {
	snake.push_back(44);
	snake.push_back(43);
	foodpos = 100;
	badfoodpos = 150;
}
void Snake::draw()
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "                                                                                                   Snake Game                                                                                                      \n";




	if (gameOver(check_small))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Game Over\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Player Score:" << score << endl;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Good Food: $\n\n";
		if (choose == '2')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			cout << "Bad Food: X\n\n";
		}
		else if (choose == '3')
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
			cout << "Don't Touch Middle Walls \n\n";
		}

		for (int i = 0; i < height; i++)
		{

			for (int j = 0; j < width; j++)
			{

				bool print = false;
				list <int> ::iterator it;
				it = snake.begin();
				++it;
				for (it; it != snake.end(); ++it) {
					if ((j + (i * 20)) == *it) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "o";
						print = true;
					}
				}
				if ((j + (i * 20)) == *snake.begin()) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "@";
					print = true;
				}
				else if (j == 0 || j == 19 || i == 0 || i == 19 || (choose == '3' && ((i == 10 && (j < 25 || j>30)) || (i == 20 && (j < 10 || j>15)) || (i == 30 && (j < 15 || j>20))))) {


					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";

					print = true;

				}
				else if ((j + (i * 20)) == badfoodpos && choose == '2')
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "X";
					print = true;
				}
				else if ((j + (i * 20)) == foodpos) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "$";
					print = true;
				}

				if (print == false)
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Player Score:" << score << endl;
	}
}
void Snake::input()
{


	if (_kbhit())//1-if keyboard is pressed return pos num if pressed and if nothing is pressed will return zero
	{
		press = true;

		if (_getch() == 'a')//2-return ascci value of char that was pressed by user//left
		{
			if (direction == "right")
				direction = "right";
			else
				direction = "left";
		}
		else if (_getch() == 'w')//up
		{
			if (direction == "down")
				direction = "down";
			else
				direction = "up";
		}
		else if (_getch() == 's')//down
		{
			if (direction == "up")
				direction = "up";
			else
				direction = "down";
		}
		else if (_getch() == 'd')//right
		{
			if (direction == "left")
				direction = "left";
			else
				direction = "right";
		}
	}

}
void Snake::initialhard() {
	snake.push_back(41);
	snake.push_back(42);
	foodpos = 1352;
}
void Snake::drawhard()
{

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "                                                                                                   Snake Game                                                                                                      \n";


	if (gameOverhard())
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		cout << "Game Over\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Player Score:" << score << endl;
	}
	else

	{

		for (int i = 0; i < width; i++)
		{

			for (int j = 0; j < height; j++)
			{
				int u = j + (i * 20);
				bool print = false;
				bool print2 = false;
				list <int> ::iterator it;
				it = snake.begin();
				++it;
				for (it; it != snake.end(); ++it) {
					if ((j + (i * 20)) == *it) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "o";
						print = true;
						print2 = true;
					}
				}
				/*if (i == 40&&j==5)
				{
				for (int x = 0; x < 6; x++,i+=40)
				{


				cout << "#";
				print = true;
				print2 = true;

				}
				}*/
				if ((j + (i * 40)) == *snake.begin()) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "@";
					print = true;
					print2 = true;
				}
				else if (u % 40 == 8 && u < 328 && u>8)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";
					print = true;

				}
				else if (u > 320 && u < 329) {


					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					//	/*for (int x = 0; x < 8; x++)
					//	{*/
					cout << "#";
					print = true;


					//	//}

				}
				else if (u % 40 == 31 && u < 1552 && u>1270)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

					cout << "#";
					print = true;

				}
				else if (u > 1271 && u < 1279) {

					//	/*for (int x = 0; x < 8; x++)
					//	{*/
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "#";
					print = true;


					//	//}

				}
				else if (j == 0 || j == 39 || i == 0 || i == 39) {
					if (print2 == false) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "#";
						print = true;
					}
				}

				else if ((j + (i * 20)) == foodpos) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "$";
					print = true;
				}

				if (print == false)
					cout << " ";
			}
			cout << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Player Score:" << score << endl;
	}
}
void Snake::moveing()
{
	int prevPos = *snake.begin();
	string prevDirection = direction;
	list <int> ::reverse_iterator it;
	list <int> ::reverse_iterator it2;
	list<int> ::reverse_iterator it3 = snake.rend();
	it3--;
	it2 = snake.rbegin();
	for (it = snake.rbegin(); it != it3; ++it)
	{
		it2++;
		*it = *it2;
	}

	if (direction == "left") {
		*(snake.begin()) -= 1;


	}
	else if (direction == "right")
	{
		*(snake.begin()) += 1;


	}
	else if (direction == "up")
	{
		*(snake.begin()) -= 20;


	}
	else if (direction == "down")
	{
		*(snake.begin()) += 20;


	}
	bool whole = false;
	float x = ((*(snake.begin()) + 1) / 20.00);
	if (floor(x) == x)//to know if x is a whole num or not;
		whole = true;
	bool whole2 = false;
	float y = ((*snake.begin()) / 20.00);
	if (floor(y) == y)//same as x
		whole2 = true;
	if (openwall == 'c' || openwall == 'C')
	{
		if ((whole))//if it reaches end right 
			hit_wall = true;
		else if ((whole2))//if it reaches end left
			hit_wall = true;
		else if ((*(snake.begin()) <= 19))//if it reaches end up
			hit_wall = true;
		else if ((*(snake.begin()) >= (20 * 19)))//if it reaches end down
			hit_wall = true;
	}
	else
	{
		if (whole)//if it reaches end right 
			*(snake.begin()) -= 18;
		else if (whole2)//if it reaches end left
			*(snake.begin()) += 18;
		else if (*(snake.begin()) <= 19)//if it reaches end up
			*(snake.begin()) = (*snake.begin() - 10) + (10 * 10);
		else if ((*(snake.begin()) >= (20 * 19)))//if it reaches end down
			*(snake.begin()) = *(snake.begin()) - (20 * 20);
	}
}
bool Snake::eatfood()
{

	if (*(snake.begin()) == foodpos)
	{
		snake.push_back(*(snake.begin()) + 1);
		score++;
		scorecheck++;
		return true;
	}
	return false;
}
bool Snake::eatbadfood()
{
	if (*(snake.begin()) == badfoodpos)
	{
		if (snake.size() > 2)
		{
			snake.pop_back();
			score--;
		}
		else
			check_small = true;
		return true;
	}
	return false;
}
void Snake::generate_food()
{
	srand(time(NULL));
	int foodposx = 1 + (rand() % ((width)-2));
	int  foodposy = 1 + (rand() % ((width)-2));
	foodpos = foodposx + (width*foodposy);
	if (choose == '3')
	{
		if (foodposy == 10 || foodposy == 15 || foodposy == 5)
			generate_food();
	}
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generate_food();

		}
		it++;
	}
}
void Snake::generate_badfood()
{
	srand(time(NULL));
	int badfoodposx = 1 + (rand() % ((width)-2));
	int  badfoodposy = 1 + (rand() % ((width)-2));
	badfoodpos = badfoodposx + (width*badfoodposy);
	if (choose == '3')
	{
		if (badfoodposy == 10 || badfoodposy == 15 || badfoodposy == 5)
			generate_food();
	}
	auto it = snake.begin();
	if (badfoodpos == foodpos)
		generate_badfood();
	for (it; it != snake.end(); it++)
	{
		if (badfoodpos == (*it))
			generate_badfood();
	}
}
//check_small 3al4an lma yakol bad food f awl mara kan bay3mal run time f lw check_small true ya5sar
bool Snake::gameOver(bool check_small) {

	if (check_small)
		return true;
	if (choose == '3')
	{
		if ((*(snake.begin()) >= 400 && *(snake.begin()) <= 425) || (*(snake.begin()) >= 430 && *(snake.begin()) <= 440) || (*(snake.begin()) >= 800 && *(snake.begin()) <= 810) || (*(snake.begin()) >= 815 && *(snake.begin()) <= 840) || (*(snake.begin()) >= 1200 && *(snake.begin()) <= 1215) || (*(snake.begin()) >= 1220 && *(snake.begin()) <= 1240))
			return true;
	}

	if (openwall == 'c' || openwall == 'C')
	{
		if (hit_wall == true)
			return true;

	}
	list <int> ::iterator it;
	it = snake.begin();
	it++;
	it++;
	for (it; it != snake.end(); it++) {

		if (*it == *(snake.begin()) || snake.size() == 1)
			return true;
	}
	return false;
}
int  Snake::gameScore() {
	int x = 0;
	if (scorecheck == 5) {
		scorecheck = 0;
		x += 10;
	}
	return x;
}
void Snake::moveinghard()
{
	int prevPos = *snake.begin();
	string prevDirection = direction;

	list <int> ::reverse_iterator it;
	list <int> ::reverse_iterator it2;
	it2 = snake.rbegin();
	for (it = snake.rbegin(); it != snake.rend(); ++it)
	{
		it2++;
		*it = *it2;
	}

	if (direction == "left") {
		*(snake.begin()) -= 1;


	}
	else if (direction == "right")
	{
		*(snake.begin()) += 1;


	}
	else if (direction == "up")
	{
		*(snake.begin()) -= 40;


	}
	else if (direction == "down")
	{
		*(snake.begin()) += 40;


	}

	if (*(snake.begin()) > 0 && *(snake.begin()) < 9)
	{
		*(snake.begin()) = *(snake.begin()) + 1591;
	}
	else if (*(snake.begin()) > 1591 && *(snake.begin()) < 1599)
	{
		*(snake.begin()) = *(snake.begin()) - 1591;
	}
	else if (*(snake.begin()) > 0 && *(snake.begin()) < 320 && *(snake.begin()) % 40 == 0)
	{
		*(snake.begin()) = 1279 + *(snake.begin());
	}
	else if (*(snake.begin()) > 1279 && *(snake.begin()) < 1599 && *(snake.begin()) % 40 == 39)
	{
		*(snake.begin()) = *(snake.begin()) - 1279;

	}

}
bool Snake::gameOverhard() {
	list <int> ::iterator it;
	it = snake.begin();
	it++;
	for (it; it != snake.end(); it++) {
		if (*it == *(snake.begin()))
			return true; break;
	}
	for (int i = 8; i < 328; i += 20) {

		if (*(snake.begin()) == i)
		{
			return true;
			break;
		}
	}
	for (int i = 320; i < 328; i++)
	{
		if (*(snake.begin()) == i)
		{
			return true;
			break;
		}
	}
	for (int i = 1271; i < 1591; i += 20) {

		if (*(snake.begin()) == i)
		{
			return true;
			break;
		}
	}
	for (int i = 1271; i < 1279; i++)
	{
		if (*(snake.begin()) == i)
		{
			return true;
			break;
		}
	}



	return false;
}
void Snake::generatehardfoodupper()
{
	srand(time(NULL));
	int foodposx = 1 + rand() % 5;
	int  foodposy = 1 + rand() % 5;
	foodpos = foodposx + (40 * foodposy);
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generatehardfoodupper();
			break;
		}
		it++;
	}

}
void Snake::generatehardfoodlower()
{
	srand(time(NULL));
	int foodposx = 32 + rand() % 6;
	int  foodposy = 32 + rand() % 6;
	foodpos = foodposx + (40 * foodposy);
	auto it = snake.begin();
	while (it != snake.end())
	{
		if (foodpos == (*it))
		{
			generatehardfoodlower();
			break;
		}
		it++;
	}

}
void Snake::generatehardfood() {

	int x = rand() % 10;


	if (x % 2 == 0)
	{
		generatehardfoodupper();
	}
	else {
		generatehardfoodlower();

	}

}
void Snake::game()
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "Welcome To Snake Game ooo@\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Choose Level:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
	cout << "Enter 1 for Easy, Enter 2 for Medium, Enter 3 for Hard,Enter 4 for very Hard:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cin >> choose;
	while (choose != '1' && choose != '2' && choose != '3'&& choose != '4')
	{
		cout << "Please Enter correct Level\n";
		cin >> choose;
	}

	if (choose == '1' || choose == '2' || choose == '3')
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 245);
		cout << "Enter O For Open Wall And C for closed Wall\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cin >> openwall;
		while (openwall != 'o' &&openwall != 'O' && openwall != 'C' &&openwall != 'c')
		{
			cout << "Please Enter correct option\n";
			cin >> openwall;
		}
		initial();
		draw();

		while (!gameOver(check_small) && snake.size() < 10)
		{
			input();
			moveing();
			if (eatfood()) {
				generate_food();
			}
			if (eatbadfood()) {
				generate_badfood();
			}
			draw();
			int x = gameScore();
			std::this_thread::sleep_for(std::chrono::milliseconds(10 + x));

		}
		draw();
	}
	else if (choose == '4')
	{
		initialhard();
		drawhard();

		while (!gameOverhard() && snake.size() < 10)
		{
			input();
			moveinghard();
			if (eatfood()) {
				generatehardfood();
			}
			drawhard();
			int x = gameScore();
			std::this_thread::sleep_for(std::chrono::milliseconds(10 + x));
		}

	}
}
Snake::~Snake() {}