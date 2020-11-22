#pragma once
#include "Astro.h"
#include "ofMain.h"

class Attack
{
public:
	Attack() {
		int x;
		int y;
		int dx;
		int dy;

		int width;
		int height;
	}

	int x = -500;
	int y = 500;
	int dx;
	int dy;

	int width = 25;
	int height = 5;

	void move();
	void draw();
	void create(Astro loc);
};
