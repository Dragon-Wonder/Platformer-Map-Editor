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
    #define DEFINED_MESSAGE_FONT "C:\\Windows\\Fonts\\Arial.ttf"
#elif defined(__unix__) || defined(__linux__)
    #define DEFINED_DEFAULT_IMAGE_PATH "./Images/"
    #define DEFINED_MESSAGE_FONT "/usr/share/fonts/truetype/freefont/FreeMono.ttf"
#elif defined(__CYGWIN__)
    #define DEFINED_DEFAULT_IMAGE_PATH "./Images/"
    #define DEFINED_MESSAGE_FONT "C:/Windows/Fonts/Arial.ttf"
#else
    #define DEFINED_DEFAULT_IMAGE_PATH "OS NOT SUPPORTED!"
    #define DEFINED_MESSAGE_FONT "OS NOT SUPPORTED!"
#endif // defined OS
/**********************************************************************************************************************************************/
//Ahh laziness at its finest
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
/**********************************************************************************************************************************************/
struct stcLoaded { //Holds bools for if stuff is loaded or not
    bool blnWindow;
    bool blnRenderer;
    bool blnTiles;
    bool blnMessage;
    bool blnMessageFont;
    bool blnToolboxFrame;
};

struct stcColors {
    SDL_Color Black;
    SDL_Color White;
};

struct stcWindowAtt { //Window attributes
    SDL_Window *win;
    SDL_Renderer *ren;
    TTF_Font *MessageFont;
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

typedef struct stcLoaded Loaded;
typedef struct stcColors clrs;
typedef struct stcWindowAtt WINDATT;
typedef struct stcPaintBrush BRUSH;
typedef struct stcButton BTTN;
/**********************************************************************************************************************************************/
enum tile {
	tileSpace = 0,
	tileWall, //1
	tilePlayer, //2
	tilePole, //3
	tileMonster, //4
	tileCoin, //5
	tileFrame, //6
	tileError //7
};

enum tools {
    toolPencil = 0,
    toolBucket,
    toolLine,
};
/**********************************************************************************************************************************************/
namespace Global {
	extern const bool blnDebugMode; //Holds if in debug mode or not. Causes more messages to appear in the console-
	extern const uint pic_size;
	extern uchar map[14][217];
};
/**********************************************************************************************************************************************/
//Functions related to the screen
namespace Screen {
    void start(void);
    void show(void);
    void cleanup(void);
    void error(void);

    Loaded blnload;
    clrs colors;
    bool bln_SDL_Started;
    WINDATT window;
};

//Functions related to the toolbar
namespace Toolbar {
    void draw(void);
    void check_events(SDL_Event*);
    void make_buttons(void);

    uint button_xplaces[6];
    BRUSH paintbrush;
    BTTN tilebuttons[6];
};

//Stuff related to the textures
namespace Textures {
    void load(void);
    void set_clips(void);

    SDL_Texture *tilemap;
    SDL_Texture *texmessage;
    SDL_Texture *toolboxframe;
    SDL_Rect clips[8];
};

//Functions related to the map
namespace Map {
    void write_map(void);
};
/**********************************************************************************************************************************************/
#endif
