#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	map<int,ofPoint>::iterator iter;
	for ( iter=touches.begin(); iter != touches.end(); ++iter ){
		ofCircle(iter->second, 30);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	touches.insert(pair<int,ofPoint>(touch.id,ofPoint(touch.x,touch.y)));
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
	touches[touch.id].set(touch.x,touch.y);
}
		
//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	touches.erase(touch.id);
}
		
//--------------------------------------------------------------
void testApp::twoFingerTap(){
}

//--------------------------------------------------------------
void testApp::twoFingerZoom(double dZoomFactor,const LONG lZx,const LONG lZy) {
}