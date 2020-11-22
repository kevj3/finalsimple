#pragma once
#include "ofMain.h"
#include "Astro.h"
class Bars
{
public:

	bool bTimerReached = false;
	float startTime = ofGetElapsedTimeMillis();  // get the start time
	float endTime = (int)ofRandom(1000, 300000); // in milliseconds

	void timer();

};
