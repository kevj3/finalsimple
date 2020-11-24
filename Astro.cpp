#include "Astro.h"

void Astro::create(ofImage img) {
	ofSetColor(255);
	img.draw(x, y, width, height);
}

void Astro::Move() {
	x += dx;
	y += dy;
	
	if (x >= ofGetWidth() || x <= 0) {
		dx = dx * -1;
	}

	if (y >= ofGetHeight() || y <= 0) {
		dy = dy * -1;
	}
}

void Astro::MoveUp() {
	dx = 0;
	dy = -5;
}
void Astro::MoveRight() {
	dx = 5;
	dy = 0;
}
void Astro::MoveLeft() {
	dx = -5;
	dy = 0;
}
void Astro::MoveDown() {
	dx = 0;
	dy = 5;
}

void Astro::MoveUpRight() {
	dx = 5;
	dy = -5;
}
void Astro::MoveUpLeft() {
	dx = -5;
	dy = -5;
}
void Astro::MoveDownLeft() {
	dx = -5;
	dy = 5;
}
void Astro::MoveDownRight() {
	dx = 5;
	dy = 5;
}

void Astro::Stop() {
	dx = 0;
	dy = 0;
}

void Astro::scores() {
	ofSetColor(255);
	ofDrawBitmapString("Health:", 100, 600);
	ofDrawBitmapString(health, 170, 600);

	ofDrawBitmapString("Score: ", 300, 600);
	ofDrawBitmapString(score, 370, 600);

}