
#pragma once
#include<iostream>
#include<list>
#include<string>

using namespace std;
class Snake
{

	string direction;
	int position;//on board
	 int  width , height ;
	bool press;
	int foodpos;
	bool check;
	int score;
	int scorecheck;
	int badfoodpos;
	bool hit_wall = false;

public:
	list<int> snake;
	Snake();
	char choose;
	char openwall;
	bool check_small;
	void initial();
	void draw();
	void input();
	void moveing();
	bool gameOver(bool check_small);
	bool eatfood();
	void generate_food();
	int gameScore();
	void generate_badfood();
	bool eatbadfood();
	void initialhard();
	void drawhard();
	void moveinghard();
	bool gameOverhard();
	void generatehardfoodupper();
	void generatehardfoodlower();
	void generatehardfood();
	void game();
	~Snake();
};