#include "Character.h"

void Character::create(ofImage img) {
	img.draw(x, y, width, height);
}

void Character::Move() {
	x += dx;
	y += dy;
}

void Character::MoveUp() {
	dx = 0;
	dy = -5;
}
void Character::MoveRight() {
	dx = 5;
	dy = 0;
}
void Character::MoveLeft() {
	dx = -5;
	dy = 0;
}
void Character::MoveDown() {
	dx = 0;
	dy = 5;
}

void Character::MoveUpRight() {
	dx = 5;
	dy = -5;
}
void Character::MoveUpLeft() {
	dx = -5;
	dy = -5;
}
void Character::MoveDownLeft() {
	dx = -5;
	dy = 5;
}
void Character::MoveDownRight() {
	dx = 5;
	dy = 5;
}

void Character::Stop() {
	dx = 0;
	dy = 0;
}

