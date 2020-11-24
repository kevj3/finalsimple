#include "Bars.h"

void Bars::timer() {

    float barWidth = 500;

    // update the timer this frame
    float timer = ofGetElapsedTimeMillis() - startTime;

    if (timer >= endTime && !bTimerReached) {
        bTimerReached = true;
        ofMessage msg("Timer Reached");
        ofSendMessage(msg);
    }

    // the background to the progress bar
    ofSetColor(255);
    ofDrawRectangle((ofGetWidth() - barWidth) / 2, 120, barWidth, 30);

    // get the percentage of the timer
    float pct = ofMap(timer, 0.0, endTime, 0.0, 1.0, true);
    ofSetHexColor(0xf02589);
    ofDrawRectangle((ofGetWidth() - barWidth) / 2, 120, barWidth * pct, 30);

    // draw the percentage
    ofSetColor(255);
    ofDrawBitmapString(ofToString(pct * 100, 0) + "%", ((ofGetWidth() - barWidth) / 2) + barWidth + 10, 100 + 20);

    // the timer was reached :)
    if (bTimerReached) {
        ofSetColor(255);
        ofDrawBitmapString("Timer Reached!", (ofGetWidth() - 120) / 2, 120 + 70);
    }

    // some information about the timer
    string  info = "FPS:        " + ofToString(ofGetFrameRate(), 0) + "\n"; 
    info += "Start Time: " + ofToString(startTime, 1) + "\n";
    info += "End Time:   " + ofToString(endTime / 1000.0, 1) + " seconds\n";
    info += "Timer:      " + ofToString(timer / 1000.0, 1) + " seconds\n";
    info += "Percentage: " + ofToString(pct * 100, 1) + "%\n";
    info += "\nPress ' ' to get a new random end time\n";
    ofSetColor(255);
    ofDrawBitmapString(info, 20, 20);
}
