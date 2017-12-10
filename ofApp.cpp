#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() { 
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	float radius = 250;
	float x, y;
	ofColor color;

	this->cam.begin();
	ofRotate(ofGetFrameNum() * 2);

	for(int deg = 0; deg < 360; deg += 8) {
		color.setHsb(deg / 360.f * 255.f, 255, 255);
		//color = ofColor(255, 2555, 0);
		ofSetColor(color);

		x = radius * cos(deg * DEG_TO_RAD);
		y = radius * sin(deg * DEG_TO_RAD);
	
		ofPushMatrix();
		ofTranslate(x, y);
		ofRotate(deg - 125);
		for (int i = 0; i < 255; i += 15) {
			ofSetColor(color, 255 - i);
			ofDrawLine(i, i, i + 15, i + 15);
		}
		ofPopMatrix();
	}

	this->cam.end();
	
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}