#include "Blocks.h"
void Blocks::follow(Astro loc) {
	if (x < loc.x) {
		dx = 1;
	}

	if (x > loc.x) {
		dx = -1;
	}

	if (y < loc.y) {
		dy = 1;
	}

	if (y > loc.y) {
		dy = -1;
	}
}

void Blocks::create(){
	ofSetColor(255, 0, 0);
	ofDrawRectangle(x, y, width, height);
}

void Blocks::move() {
	x += dx;
	y += dy;
}

void Blocks::collide(Astro loc,ofSoundPlayer pain) {
	//bottom y of block above other top
	if ((y + height) < loc.y) {
		return;
	}
	// top  below others bottom
	if (y > (loc.y + loc.height)) {
		return;
	}
	// right side infront of other x
	if ((x + width) < loc.x) {
		return;
	}

	//left side infront of others x + width
	if (x > (loc.x + loc.width)) {
		return;
	}

	cout << "hit" << endl;
	x = ofRandom(0, ofGetWidth());
	y = -50;
	dx++;
	dy++;
	pain.play();
}

void Blocks::collideA(Attack attack) {
	//bottom y of block above other top
	if ((y + height) < attack.y) {
		return;
	}
	// top  below others bottom
	if (y > (attack.y + attack.height)) {
		return;
	}
	// right side infront of other x
	if ((x + width) < attack.x) {
		return;
	}

	//left side infront of others x + width
	if (x > (attack.x + attack.width)) {
		return;
	}

	cout << "hit from attack" << endl;
	x = ofRandom(0, ofGetWidth());
	y = -50;
}