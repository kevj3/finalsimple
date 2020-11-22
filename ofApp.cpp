#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bool ok = serial.setup("COM3", 9600); //replace COM3 with your arduino name
	if (ok) {
		std::cout << "SERIAL OK \n";
	}
	else {
		std::cout << "UNABLE TO OPEN SERIAL PORT\n";
		std::exit;
	}
	space.load("stargazing.mp3");
	space.play();
	ofBackground(0);
	ofSetFrameRate(120);


	for (int i = 0; i < 5; i++) {
		Blocks* block = new Blocks;
		block->y = ofRandom(-15, -65);
		block->x = ofRandom(0, ofGetWidth());
		blocks.push_back(block);
	}

	for (int i = 0; i < 5; i++) {
		BigBlocks* bblock = new BigBlocks;
		bblock->x = ofRandom(0, ofGetWidth());
		bblock->y = -50;
		bblocks.push_back(bblock);
	}

	astronaut.load("astro.png");
	gun.load("laser.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (serial.available()) {
			char c = serial.readByte();
			if (c == 'W') {
				astro.MoveUp();
			}

			if (c == 'D') {
				astro.MoveRight();
			}
			if (c == 'A') {
				astro.MoveLeft();
			}

			if (c == 'X') {
				astro.MoveDown();
			}
			if (c == 'Q') {
				astro.MoveUpLeft();
			}

			if (c == 'E') {
				astro.MoveUpRight();
			}
			if (c == 'Z') {
				astro.MoveDownLeft();
			}

			if (c == 'C') {
				astro.MoveDownRight();
			}

			if (c == 'S') {
				astro.Stop();
			}

			if (c == 'K') {
				attack.create(astro);
				attack.width = 5;
				attack.height = 25;
				attack.dy = -10;
				attack.dx = 0;
				attack.move();
				gun.play();
				cout << "Attack up" << endl;
			}

			if (c == 'J') {
				attack.create(astro);
				attack.width = 25;
				attack.height = 5;
				attack.dy = 0;
				attack.dx = -10;
				attack.move();
				gun.play();
				cout << "Attack Left" << endl;
			}

			if (c == 'L') {
				attack.create(astro);
				attack.width = 25;
				attack.height = 5;
				attack.dy = 0;
				attack.dx = 10;
				attack.move();
				gun.play();
				cout << "Attack Right" << endl;
			}

			if (c == 'I') {
				attack.create(astro);
				attack.width = 75;
				attack.height = 75;
				attack.dy = 0;
				attack.dx = 0;
				attack.move();
				gun.play();
				cout << "Attack " << endl;
			}

	}

	astro.Move();
	attack.move();

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i]->follow(astro);
		blocks[i]->move();
		blocks[i]->collide(astro);
		blocks[i]->collideA(attack);
	}


	for (int i = 0; i < bblocks.size(); i++) {
		bblocks[i]->dy = 5;
		bblocks[i]->move();
		if (bblocks[i]->y > ofGetHeight()) {
			bblocks[i]->y = -69;
			bblocks[i]->x = ofRandom(0, ofGetWidth());
			bblocks[i]->dy = 11;
			bblocks[i]->move();
		}
		bblocks[i]->collide(astro);
		bblocks[i]->collideA(attack);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	astro.create(astronaut);
	attack.draw();
	bars.timer();
	
	
	for (int i = 0; i < blocks.size(); i++) {
		blocks[i]->create();
	}

	for (int i = 0; i < bblocks.size(); i++) {
		bblocks[i]->create();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		bars.bTimerReached = false;                     // reset the timer
		bars.startTime = ofGetElapsedTimeMillis();  // get the start time
		bars.endTime = (int)ofRandom(1000, 5000); // in milliseconds
	}
}

