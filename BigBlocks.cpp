#include "BigBlocks.h"
void BigBlocks::create() {
	ofSetColor(255,0,0);
	ofDrawRectangle(x, y, width, height);
}

void BigBlocks::move() {
	y += dy;
}

void BigBlocks::stop() {
	dy = 0;
}

void BigBlocks::collide(Astro &loc,ofSoundPlayer pain) {
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
	
	loc.health = loc.health - 1;
	x = ofRandom(0, ofGetWidth());
	y = -50;
	pain.play();
}

void BigBlocks::collideA(Attack attack,ofSoundPlayer exp,Astro &a) {
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

	a.score = a.score + 20;
	cout << "hit from attack" << endl;
	x = ofRandom(0, ofGetWidth());
	y = -50;
	exp.play();
}