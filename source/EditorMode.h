#ifndef EDITORMODE_H
#define EDITORMODE_H


#include "AbstractApplicationMode.h"
#include "ModeContext.h"

class ModeContext;

class  EditorMode: public AbstractApplicationMode  {


 public:
 

    EditorMode(ModeContext*);

    virtual ~EditorMode();

    inline virtual OIS::Mouse*      getMouse()         {return mc->mMouse;}
    inline virtual OIS::Keyboard*   getKeyboard()      {return mc->mKeyboard;}

    virtual bool mouseMoved     (const OIS::MouseEvent &arg);
    virtual bool mousePressed   (const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased  (const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool keyPressed     (const OIS::KeyEvent &arg);
    virtual bool keyReleased    (const OIS::KeyEvent &arg);
    virtual void handleHotkeys  (OIS::KeyCode keycode);
    virtual bool isInGame();
    virtual void giveFocus();

};

#endif // EDITORMODE_H
