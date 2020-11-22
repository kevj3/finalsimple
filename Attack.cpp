#include "Attack.h"
void Attack::create(Astro loc) {
	x = loc.x;
	y = loc.y;
	ofDrawRectangle(loc.x, loc.y, width, height);
}

void Attack::draw() {
	ofSetColor(0,0,255);
	ofDrawRectangle(x, y, width, height);
}

void Attack::move() {
	x += dx;
	y += dy;
}