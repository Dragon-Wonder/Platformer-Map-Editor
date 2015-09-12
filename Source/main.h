#ifndef __MAIN__HEADER__
#define __MAIN__HEADER__
/**********************************************************************************************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <cstdio>
/**********************************************************************************************************************************************/
#if defined(_WIN32) ||defined(_WIN64)
    #define DEFINED_DEFAULT_IMAGE_PATH ".\\Images\\"
    #define DEFINED_MESSAGE_FONT "C:\\Windows\\Fonts\\GARA.ttf"
#elif defined(__unix__) || defined(__linux__)
    #define DEFINED_DEFAULT_IMAGE_PATH "./Images/"
    #define DEFINED_MESSAGE_FONT "/usr/share/fonts/truetype/freefont/FreeMono.ttf"
#elif defined(__CYGWIN__)
    #define DEFINED_DEFAULT_IMAGE_PATH "./Images/"
    #define DEFINED_MESSAGE_FONT "C:/Windows/Fonts/GARA.ttf"
#else
    #define DEFINED_DEFAULT_IMAGE_PATH "OS NOT SUPPORTED!"
    #define DEFINED_MESSAGE_FONT "OS NOT SUPPORTED! *murloc Sound"
#endif // defined OS
/**********************************************************************************************************************************************/
#define DEFINED_MAP_HEIGHT 14
#define DEFINED_MAP_WIDTH 217
#define DEFINED_NUM_OF_TILES 12
#define DEFINED_NUM_BUTN_TILES 6
/**********************************************************************************************************************************************/
//Ahh laziness at its finest
//This is why Patrick, we can't have nice things
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
/**********************************************************************************************************************************************/
struct stcLoaded { //Holds boolEANs for if stuff is loaded or not
    bool blnWindow;
    bool blnRenderer;
    bool blnTiles;
    bool blnMessage;
    bool blnMessageFont;
    bool blnToolboxFrame;
};

struct stcColors {
    SDL_Color Black;
    SDL_Color White; //Stupid code, you make me look bad
};

struct stcWindowAtt { //Window attributes
    SDL_Window *win;
    SDL_Renderer *ren;
    TTF_Font *MessageFont; //You must build additional pylons
    uint width;
    uint height;
};

struct stcPaintBrush {
    uchar CurrentTile;
    uchar ToolMode;
};

struct stcButton {
    SDL_Rect box;
    SDL_Rect *clip;
    uchar buttontype;
};

struct stcOffset {
    int x;
    int y;
};

typedef struct stcLoaded Loaded; //Abbreviations are OVER 9000!
typedef struct stcColors clrs;
typedef struct stcWindowAtt WINDATT;
typedef struct stcPaintBrush BRUSH;
typedef struct stcButton BTTN;
typedef struct stcOffset OFFST;
/**********************************************************************************************************************************************/
enum tile {
	tileSpace = 0,
	tileWall, //1
	tilePlayer, //2
	tilePole, //3
	tileMonster, //4
	tileCoin, //5
	menuFrame, //6
	menuError, //7
	menuSave, //8
	menuClose, //9
	menuLeft, //10
	menuRight //11
};

enum tools {
    toolPencil = 0,
    toolBucket,
    toolLine,
};

enum prompttype {
    promptYesNo = 0,
    promptOkay
};
/**********************************************************************************************************************************************/
namespace Global {
	extern const bool blnDebugMode; //Holds if in debug mode or not. Causes more messages to appear in the console-
	extern const uint pic_size;
	extern uchar map[DEFINED_MAP_HEIGHT][DEFINED_MAP_WIDTH];
};
/**********************************************************************************************************************************************/
//Functions related to the screen
/* TODO (xPUREx#7#): You must build additional classes */
namespace Screen {
    void start(void);
    void show(void);
    void cleanup(void);
    void error(void);
    char promptuser(uchar, std::string);

    Loaded blnload;
    clrs colors;
    bool bln_SDL_Started;
    WINDATT window;
    OFFST offset;
    OFFST modoffset; //offset that has been modded slightly (is this even needed?)
};

//Functions related to the toolbar
namespace Toolbar {
    void draw(void);
    void check_events(SDL_Event*);
    void make_buttons(void);

    uint button_xplaces[DEFINED_NUM_BUTN_TILES];
    BRUSH paintbrush;
    BTTN tilebuttons[DEFINED_NUM_BUTN_TILES];
};

//Stuff related to the textures
namespace Textures {
    void load(void);
    void set_clips(void);

    SDL_Texture *tilemap;
    SDL_Texture *texmessage;
    SDL_Texture *toolboxframe;
    SDL_Rect clips[DEFINED_NUM_OF_TILES];
};

//Functions related to the map
namespace Map {
    void save(void);
    void load(void);
    void newmap(void);
};
/**********************************************************************************************************************************************/
#endif
