#ifndef ABSTRACTAPPLICATIONMODE_H
#define ABSTRACTAPPLICATIONMODE_H
#include <OIS.h>

#include "Tile.h"
#include "ModeManager.h"
#include "ModeContext.h"


class ODFrameListener;
class GameMap;
class MiniMap;
class Player;

using std::endl; using std::cout;

class AbstractApplicationMode :
public OIS::MouseListener,
    public OIS::KeyListener
{

  protected:
    ModeContext* mc;


  public:
    AbstractApplicationMode(ModeContext *modeContext):mc(modeContext){};
    virtual ~AbstractApplicationMode(){};

    virtual bool mouseMoved     (const OIS::MouseEvent &arg)=0;
    virtual bool mousePressed   (const OIS::MouseEvent &arg, OIS::MouseButtonID id)=0;
    virtual bool mouseReleased  (const OIS::MouseEvent &arg, OIS::MouseButtonID id)=0;
    virtual bool keyPressed     (const OIS::KeyEvent &arg)=0;
    virtual bool keyReleased    (const OIS::KeyEvent &arg)=0;
    virtual void handleHotkeys  (OIS::KeyCode keycode)=0;
    inline void progressMode (ModeManager::ModeType mm){mc->changed=true; mc->nextMode= mm ;}; 
    inline void regressMode(){mc->changed=true; mc->nextMode= ModeManager::PREV ;};


    
    inline virtual OIS::Mouse*      getMouse() =0;
    inline virtual OIS::Keyboard*   getKeyboard() =0;

    enum DragType
    {
	creature,
	mapLight,
	tileSelection,
	tileBrushSelection,
	addNewRoom,
	addNewTrap,
	rotateAxisX,
	rotateAxisY,
	nullDragType
    };
	
    virtual void giveFocus()=0 ; 
    virtual bool isInGame()=0  ;
	


};

/* #endif /\* INPUTMANAGER_H_ *\/ */




#endif // ABSTRACTAPPLICATIONMODE_H
