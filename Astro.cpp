#include "Astro.h"

void Astro::create(ofImage img) {
	ofSetColor(255);
	img.draw(x, y, width, height);
}

void Astro::Move() {
	x += dx;
	y += dy;
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