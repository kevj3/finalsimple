#pragma once

#include "ofMain.h"
#include "Astro.h"
#include "Attack.h"
#include "Blocks.h"
#include "BigBlocks.h"
#include "Bars.h"

#include <vector>

class ofApp :public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);


	Astro astro;
	Blocks block;
	Attack attack;
	Bars bars;
	vector<Blocks*> blocks;
	vector<BigBlocks*> bblocks;
private:
	ofSerial serial;
	ofImage meteor;
	ofImage astronaut;
	ofSoundPlayer space;
	ofSoundPlayer gun;

};