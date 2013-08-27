#include "ofWinTouchEngine.h"
#include "ofEvents.h"
#include "ofAppRunner.h"

ofWinTouchEngine::ofWinTouchEngine(ofBaseTouchApp * ofAppPtr){}

ofWinTouchEngine::~ofWinTouchEngine(void) {}


LRESULT ofWinTouchEngine::processTouch(HWND hWnd, WPARAM wParam, LPARAM lParam) {

	BOOL bHandled = FALSE;
    UINT cInputs = LOWORD(wParam);
    PTOUCHINPUT pInputs = new TOUCHINPUT[cInputs];
    if (pInputs){
        if (GetTouchInputInfo((HTOUCHINPUT)lParam, cInputs, pInputs, sizeof(TOUCHINPUT))){
            for (UINT i=0; i < cInputs; i++){
                TOUCHINPUT ti = pInputs[i];
                //do something with each touch input entry
				if (ti.dwFlags & TOUCHEVENTF_DOWN){
					
					OnTouchDown(ti.dwID, TOUCH_COORD_TO_PIXEL(ti.x)-ofGetWindowPositionX(), TOUCH_COORD_TO_PIXEL(ti.y)-ofGetWindowPositionY());
				}
				else if (ti.dwFlags & TOUCHEVENTF_MOVE){
					
					OnTouchMove(ti.dwID, TOUCH_COORD_TO_PIXEL(ti.x)-ofGetWindowPositionX(), TOUCH_COORD_TO_PIXEL(ti.y)-ofGetWindowPositionY());
				}
				if (ti.dwFlags & TOUCHEVENTF_UP){
					
					OnTouchUp(ti.dwID, TOUCH_COORD_TO_PIXEL(ti.x)-ofGetWindowPositionX(), TOUCH_COORD_TO_PIXEL(ti.y)-ofGetWindowPositionY());
				}
                }
            bHandled = TRUE;
            }else{
				/* handle the error here */
			}
        delete [] pInputs;
        }else{
            /* handle the error here, probably out of memory */
            }
    if (bHandled){
        // if you handled the message, close the touch input handle and return
        CloseTouchInputHandle((HTOUCHINPUT)lParam);
        return 0;
        }else{
            // if you didn't handle the message, let DefWindowProc handle it
            return DefWindowProc(hWnd, WM_TOUCH, wParam, lParam);
            }
    
}

void ofWinTouchEngine::OnTouchDown(int id, int x, int y) {
	static ofTouchEventArgs touchEventArgs;
	
	if(_ofAppPtr) {
        touchEventArgs.x = x;
        touchEventArgs.y = y;
        touchEventArgs.id = id;
        ofNotifyEvent( ofEvents().touchDown, touchEventArgs );
        }
}

void ofWinTouchEngine::OnTouchMove(int id, int x, int y) {
    
	static ofTouchEventArgs touchEventArgs;
    
	if(_ofAppPtr) {
        touchEventArgs.x = x;
        touchEventArgs.y = y;
        touchEventArgs.id = id;
        ofNotifyEvent( ofEvents().touchMoved, touchEventArgs );
        }
}

void ofWinTouchEngine::OnTouchUp(int id, int x, int y) {
    
	static ofTouchEventArgs touchEventArgs;
    
	if(_ofAppPtr) {
		touchEventArgs.x = x;
        touchEventArgs.y = y;
        touchEventArgs.id = id;
        ofNotifyEvent( ofEvents().touchUp, touchEventArgs );
        }
}

void ofWinTouchEngine::setAppPointer(ofBaseTouchApp * ofAppPtr){
	_ofAppPtr = ofAppPtr;
}