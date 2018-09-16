#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//getPtr(0)->setFullscreen(true);
	imageTranslationWrapper.setup();
	imageTranslationWrapper.addImage(ofToDataPath("00.jpg"), ofVec2f(1800, 0), 1048, 1048);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	imageTranslationWrapper.draw(0);
}

void ofApp::drawAdditionalWindow(ofEventArgs & args)
{
	imageTranslationWrapper.draw(1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
