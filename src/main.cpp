#include <vector>
using namespace std;

#include "Defines.h"
#include "MapEditor.h"
#include "GameMap.h"

SceneManager* mSceneMgr;
GameMap gameMap;
string MOTD = (string)"Welcome to Open Dungeons\tVersion:  " + VERSION;
int MAX_FRAMES_PER_SECOND = 15;

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char **argv)
#endif
{
	// Create application object
	MapEditor app;

	try {
	app.go();
	} catch( Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 
	MessageBox( NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
	fprintf(stderr, "An exception has occurred: %s\n",
	e.what());
#endif
	}

	return 0;
}

