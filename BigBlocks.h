#pragma once
#include "Astro.h"
#include "ofMain.h"
#include "Attack.h"

class BigBlocks
{
public:
	BigBlocks() {
		int x;
		int y;
		int dx;
		int dy;

		int width;
		int height;
	}

	int x;
	int y;
	int dx;
	int dy;

	int width = 50;
	int height = 50;


	void move();
	void create();
	void collide(Astro loc);
	void collideA(Attack loc);
};

