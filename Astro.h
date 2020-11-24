#pragma once
#include "ofMain.h"

class Astro
{
public:
	Astro() {
		int x;
		int y;
		int dx;
		int dy;

		int width;
		int height;
		int health;
	}
	int health = 10;
	int score = 0;

	int x = 500;
	int y = 500;

	int dx = 0;
	int dy = 0;


	int width = 100;
	int height = 130;
	

	void create(ofImage img);
	void Move();
	void scores();

	void MoveUp();
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveUpRight();
	void MoveUpLeft();
	void MoveDownLeft();
	void MoveDownRight();
	void Stop();
};
