#pragma once
#include "Astro.h"
#include "ofMain.h"
#include "Attack.h"
#include "Bars.h"
class Blocks
{
public:
	Blocks() {
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

	int width = 20;
	int height = 20;


	void follow(Astro loc);
	void move();
	void stop();
	void create();
	void collide(Astro &loc,ofSoundPlayer pain);
	void collideA(Attack attack, ofSoundPlayer blop,Astro &a);
	
};

