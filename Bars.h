#pragma once
#include "ofMain.h"
#include "Astro.h"
class Bars
{
public:

	bool bTimerReached = false;
	float startTime = ofGetElapsedTimeMillis();  // get the start time
	float endTime = (30000); // in milliseconds

	void timer();

};
