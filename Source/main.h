#ifndef __MAIN__HEADER__
#define __MAIN__HEADER__
/*****************************************************************************/
/////////////////////////////////////////////////
/// @file main.h
/// @brief  This is the header which holds all of the defines related to
/// main.cpp
/////////////////////////////////////////////////
/*****************************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstring>
#include <string>
#include <cstdio>
/*****************************************************************************/
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
/*****************************************************************************/
/////////////////////////////////////////////////
/// @defgroup MapStats Map Defines
/// @brief These are defines hold the map values.
/// @{
/////////////////////////////////////////////////
#define DEFINED_MAP_HEIGHT 14 /**< Number of tiles the map is high, default is 14.**/
#define DEFINED_MAP_WIDTH 217 /**< Number of tiles the map is width, default is 217.**/
/// @}
/*****************************************************************************/
/////////////////////////////////////////////////
/// @defgroup ButtonStats Button Defines
/// @brief These are defines to hold tile and button related things.
/// @{
/////////////////////////////////////////////////
#define DEFINED_NUM_OF_TILES 16 /**< Number of different tiles, default is 16. **/
#define DEFINED_NUM_BUTN_TILES 10 /**< Number of the tiles which are buttons. Default is 10. **/
#define DEFINED_NUM_BUTN_MENU 2 /**< Number of tiles that are to be used as menu buttons. Defaults is 2.**/
/// @}
/*****************************************************************************/
/////////////////////////////////////////////////
/// @defgroup TypeDefs Type Definitions
/// @brief These are defines are just to change type defs.
/// @{
/////////////////////////////////////////////////
typedef unsigned char uchar; /**< I'm lazy so define unsigned char as uchar */
typedef unsigned int uint; /**< I'm lazy so define unsigned int as uint */
typedef unsigned long ulong; /**< I'm lazy so define unsigned long as ulong */
/// @}
/*****************************************************************************/
/////////////////////////////////////////////////
/// @defgroup Structs Structures
/// @brief These are all the different structures that are used throughout the code.
/// @{
/////////////////////////////////////////////////

/** This structure holds booleans for if certain items are loaded in memory or not.
    This is used to ensure only stuff that is load is going to be attempted to be deleted
    during cleanup to avoid crashes. The values are held together to make them easier to
    reference. */
struct stcLoaded {
    bool blnWindow;         /**< Boolean for if the SDL window is loaded. */
    bool blnRenderer;       /**< Boolean for if the SDL renderer is loaded. */
    bool blnTiles;          /**< Boolean for if the tiles is loaded. */
    bool blnMessage;        /**< Boolean for if the message is loaded. */
    bool blnMessageFont;    /**< Boolean for if the message font is loaded. */
    bool blnToolboxFrame;   /**< Boolean for if the toolbox frame is loaded. */
};

/** Holds values for different colors. */
struct stcColors {
    SDL_Color Black; /**< Holds the color black. */
    SDL_Color White; /**< Holds the color white. */
};

/** Holds different pointers for attributes of the window.
    Held together in a structure for easier reference. */
struct stcWindowAtt {
    SDL_Window *win;        /**< Pointer to the SDL window. */
    SDL_Renderer *ren;      /**< Pointer to the SDL renderer. */
    TTF_Font *MessageFont;  /**< Pointer to the font for the messages. */
    uint width;             /**< Holds the width of the window in pixels. */
    uint height;            /**< Holds the height of the window in pixels. */
};


/** Holds values that is used for the paint brush. */
struct stcPaintBrush {
    uchar CurrentTile;  /**< Holds current tile that is selected. */
    uchar ToolMode;     /**< Holds the tool that is selected. Currently does
                             nothing, but will later have tools like bucket, line, etc... */
};

/** Holds values for the buttons. */
struct stcButton {
    SDL_Rect box;       /**< Holds the "box" which is where the button appears on screen. */
    SDL_Rect *clip;     /**< Holds the "clip" which is where the button appears on tile.png. */
    uchar buttontype;   /**< Holds what type of button it is, aka the tile. */
};

/** Holds the offset that the screen currently is at */
struct stcOffset {
    int x; /**< X direction. */
    int y; /**< Y Direction. */
};
/// @}

/// @addtogroup TypeDefs
/// @{
typedef struct stcLoaded Loaded;
typedef struct stcColors clrs;
typedef struct stcWindowAtt WINDATT;
typedef struct stcPaintBrush BRUSH;
typedef struct stcButton BTTN;
typedef struct stcOffset OFFST;
/// @}
/*****************************************************************************/
/** Holds all the different tiles that are in tiles.png. */
enum tile {
	tileSpace = 0x0,
	tileBricksLarge = 0x1,
	tilePlayer = 0x2,
	tilePole = 0x3,
	tileMonster = 0x4,
	tileCoin = 0x5,
	tileBricksSmall = 0x6,
	tileBricksGray = 0x7,
	tileBricksGreen = 0x8,
	tileBricksOrange = 0x9,
	menuFrame = 0xA,
	menuError = 0xB,
	menuClose = 0xC,
	menuSave = 0xD,
	menuLeft = 0xE,
	menuRight = 0xF
};

/** Holds the different tools available. Currently only pencil works. */
enum tools {
    toolPencil = 0,
    toolBucket,
    toolLine,
};

/** Holds the different prompts types to the user. */
enum prompttype {
    promptYesNo = 0,
    promptOkay
};
/*****************************************************************************/
/** This namespace is used to hold things that need to be referenced globally. */
namespace Global {
	extern const bool blnDebugMode; /**< Holds if in debug mode or not.
                                        Causes more messages to appear in the console. */
	extern const uint pic_size; /**< Size of each picture in pixels. */
	extern uchar map[DEFINED_MAP_HEIGHT][DEFINED_MAP_WIDTH]; /**< The map. */
};
/*****************************************************************************/
/** Functions related to the screen. */
/* TODO (xPUREx#7#): You must build additional classes */
namespace Screen {
    void start(void);
    void show(void);
    void cleanup(void);
    void error(void);
    char promptuser(uchar, std::string);

    Loaded blnload;         /**< Loaded values structure. */
    clrs colors;            /**< Colors. */
    bool bln_SDL_Started;   /**< Boolean to see if SDL is started. This value
                                 is checked every so often by the code and if it
                                 is false, the program will begin to run shutdown code
                                 and report an error. */
    WINDATT window;         /**< Window attributes */
    OFFST offset;           /**< Window offset */
};

/** Functions related to the toolbar */
namespace Toolbar {
    void draw(void);
    void check_events(SDL_Event*);
    void make_buttons(void);

    uint button_xplaces[DEFINED_NUM_BUTN_TILES]; /**< Value for the x coordinate for all the buttons */
    BRUSH paintbrush;                            /**< Paintbrush */
    BTTN tilebuttons[DEFINED_NUM_BUTN_TILES];    /**< Array for all of the buttons that change paintbrush tile. */
    BTTN menubuttons[DEFINED_NUM_BUTN_MENU];     /**< Array for all of the buttons which do menu stuff (close, save, etc..). */
};

/** Stuff related to the textures */
namespace Textures {
    void load(void);
    void set_clips(void);
    SDL_Texture* makeTransparent(SDL_Surface* , Uint32 );

    SDL_Texture *tilemap; /**< Pointer to the tile map in memory */
    SDL_Texture *texmessage; /**< Pointer to the message text in memory */
    SDL_Texture *toolboxframe; /**< Pointer to the toolbox frame in memory */
    SDL_Rect clips[DEFINED_NUM_OF_TILES]; /**< Array of all the placements of the tiles. */
};

/** Functions related to the map. */
namespace Map {
    void save(void);
    void load(void);
    void newmap(void);
};
/*****************************************************************************/
#endif
