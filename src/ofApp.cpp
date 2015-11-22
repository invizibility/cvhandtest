#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    bLearnBackground = false;
    
    vidGrabber.setVerbose(true);
    
    vidGrabber.initGrabber(320,240);
    vidPlayer.loadMovie("hand2.mov");
    
    int w = vidPlayer.getWidth();
    int h = vidPlayer.getHeight();
    
    colorImg.allocate(w,h);
    grayImage.allocate(w,h);
    grayBg.allocate(w,h);
    grayDiff.allocate(w,h);
    
    //imageload = testimage.loadImage("rsz_back.png");
    //colorImg.setFromPixels(testimage);
    
    //colorImg.setFromPixels(loadImage("rsz_front.png"));
    vidPlayer.play();
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //vidGrabber.update();
    vidPlayer.update();
    //do we have a new frame?
    if (vidPlayer.isFrameNew()){
        colorImg.setFromPixels(vidPlayer.getPixels(), vidPlayer.getWidth(), vidPlayer.getHeight());
        grayImage = colorImg; // convert our color image to a grayscale image
        if (bLearnBackground == true) {
            grayBg = grayImage; // update the background image
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.adaptiveThreshold(50,0,false,true);
        contourFinder.findContours(grayDiff, 5, (340*240), 1, false, true);
    }
    
    //colorImg.setFromPixels(<#const unsigned char *_pixels#>, <#int w#>, <#int h#>)
//            grayImage = colorImg; // convert our color image to a grayscale image
//            if (bLearnBackground == true) {
//                grayBg = grayImage; // update the background image
//                bLearnBackground = false;
//            }
//            grayDiff.absDiff(grayBg, grayImage);
//            grayDiff.threshold(100);
//            contourFinder.findContours(grayDiff, 5, (340*240)-400, 1, false, true);
//    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    colorImg.draw(0, 0, 320, 240);
    grayDiff.draw(0, 240, 320, 240);
    ofRect(320, 0, 320, 240);
    contourFinder.draw(320, 0, 320, 240);
    ofColor c(255, 255, 255);
    for(int i = 0; i < contourFinder.nBlobs; i++) {
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
        r.x += 320; r.y += 240;
        c.setHsb(i * 64, 255, 255);
        ofSetColor(c);
        ofRect(r);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
