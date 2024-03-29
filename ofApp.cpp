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


	for (int i = 0; i < 10; i++) {
		Blocks* block = new Blocks;
		block->y = ofRandom(-65, -100);
		block->x = ofRandom(0, ofGetWidth());
		blocks.push_back(block);
	}

	for (int i = 0; i < 8; i++) {
		BigBlocks* bblock = new BigBlocks;
		bblock->x = ofRandom(0, ofGetWidth());
		bblock->y = ofRandom(-100,-200);
		bblocks.push_back(bblock);
	}

	astronaut.load("astro.png");
	gg.load("gameover.jpg");
	gun.load("laser.mp3");
	exp.load("exp.mp3");
	pain.load("Pain.mp3");
	blop.load("blop.mp3");

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
			}

			if (c == 'J') {
				attack.create(astro);
				attack.width = 25;
				attack.height = 5;
				attack.dy = 0;
				attack.dx = -10;
				attack.move();
				gun.play();
			}

			if (c == 'L') {
				attack.create(astro);
				attack.width = 25;
				attack.height = 5;
				attack.dy = 0;
				attack.dx = 10;
				attack.move();
				gun.play();
			}

			if (c == 'I') {
				attack.create(astro);
				attack.width = 75;
				attack.height = 75;
				attack.dy = -10;
				attack.dx = 0;
				attack.move();
				gun.play();
			}

	}

	astro.Move();
	attack.move();

	for (int i = 0; i < blocks.size(); i++) {
		blocks[i]->follow(astro);
		blocks[i]->move();
		blocks[i]->collide(astro,pain);
		blocks[i]->collideA(attack, blop,astro);
	}


	for (int i = 0; i < bblocks.size(); i++) {
		bblocks[i]->dy = 4;
		bblocks[i]->move();
		if (bblocks[i]->y > ofGetHeight()) {
			bblocks[i]->y = -69;
			bblocks[i]->x = ofRandom(0, ofGetWidth());
			bblocks[i]->dy = 10;
			bblocks[i]->move();
		}
		bblocks[i]->collide(astro,pain);
		bblocks[i]->collideA(attack,exp,astro);
	}

	if (astro.health <= 0) {
		gg.draw(0, 0);
		cout << "Gameover you have BLOCKED" << endl;
		cout << "You have reached Level : " << level << endl;
		cout << "Final Score: " << astro.allscore << endl;
		cout << "THANK YOU FOR PLAYING" << endl;
		ofSleepMillis(1000);
		OF_EXIT_APP(0)
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	astro.create(astronaut);
	attack.draw();
	bars.timer();
	astro.scores();
	
	
	ofDrawBitmapString("LEVEL:", 400, 600);
	ofDrawBitmapString(level, 490, 600);

	ofDrawBitmapString("GOAL = 100  SCORE :", 500, 100);
	ofDrawBitmapString(astro.score, 650, 100);

	if(bars.bTimerReached == true && astro.score < 100) {
		ofDrawBitmapString("GAMEOVER", 300, 400);
		cout << "Gameover you have BLOCKED" << endl;
		cout << "You have reached Level : " << level << endl;
		cout << "Final Score: " << astro.allscore << endl;
		cout << "THANK YOU FOR PLAYING" << endl;
		ofSleepMillis(1000);
		OF_EXIT_APP(0)
	}
	
	if (bars.bTimerReached == false && astro.score >= 100) {
		bool gotit = true;
		if (gotit = true) {
			ofDrawBitmapString("NEXT LEVEL", 300, 400);
			ofDrawBitmapString("CLICK SPACEBAR TO GO NEXT LEVEL", 300, 500);
			gotit = false;
		}
	}


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
		bars.bTimerReached = false;                 // reset the timer
		bars.startTime = ofGetElapsedTimeMillis();  // get the start time
		bars.endTime =(30000); // in milliseconds
		level++;
		astro.score = 0;
		
		for (int i = 0; i < blocks.size(); i++) {
			blocks[i]->reset();
			blocks[i]->dx += 1;
			blocks[i]->dy += 1;
		}

		for (int i = 0; i < bblocks.size(); i++) {
			bblocks[i]->reset();
			blocks[i]->dy += 1;
		}
	}
}

