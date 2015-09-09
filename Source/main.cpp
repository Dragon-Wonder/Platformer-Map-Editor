/**********************************************************************************************************************************************/
//The main function, most of the actual program is found in Entity.cpp under start.
//So see there for most of the functions.
/**********************************************************************************************************************************************/
#include "main.h"
#include "version.h"
#include "button.h"
/**********************************************************************************************************************************************/
#include "image_tiles.xpm"
#include "image_toolbox_frame.xpm"
/**********************************************************************************************************************************************/
//Globals (in all files)
namespace Global {
    //Holds if in debug mode or not. Causes more messages to appear in the console.
    //Defined in version.h
    #ifndef DEFINED_BUILD_MODE_PRIVATE
        const bool blnDebugMode = false;
    #else
        const bool blnDebugMode = true;
    #endif // DEFINED_BUILD_MODE_PRIVATE
    SDL_Rect clips[8];
    const uint pic_size = 24;
    uchar map[14][217] = {{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,5,5,5,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,5,5,5,5,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,0,0,0,0},
                        {0,0,0,0,0,0,5,5,5,5,5,5,5,0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,1,1,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,3,0,0,0,0,1,1,1,1,1,0,0,0},
                        {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,3,0,0,0,0,1,1,1,1,1,0,0,0},
                        {1,1,1,1,1,2,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,4,0,0,1,1,1,1,0,0,0,0,0,0,0,4,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,3,0,0,0,1,1,1,1,1,1,0,0,0},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    BRUSH paintbrush;
    WINDATT window;
    TEX textures;
};
/**********************************************************************************************************************************************/
//Globals in this file.
Loaded blnload;
clrs colors;
bool bln_SDL_Started;
/**********************************************************************************************************************************************/
int main(int argc, char *argv[]) {
    bool quit = false;
    SDL_Event event;

    set_clips();
    start_screen();
    if (bln_SDL_Started == false) {return 1;}

    while ( quit == false) {
        show_screen();
        if (SDL_PollEvent( &event ) ) {
            check_events();
            if (event.type == SDL_QUIT) {quit = true;}
        }
    }

    cleanup();
    write_map();
	return 0;
}
/**********************************************************************************************************************************************/
void set_clips() {
    //Sets all the location of tiles in the main tile.png

    Global::clips[tileCoin].x = 0 * Global::pic_size;
    Global::clips[tileCoin].y = 0 * Global::pic_size;
    Global::clips[tileCoin].h = Global::pic_size;
    Global::clips[tileCoin].w = Global::pic_size;

    Global::clips[tileMonster].x = 1 * Global::pic_size;
    Global::clips[tileMonster].y = 0 * Global::pic_size;
    Global::clips[tileMonster].h = Global::pic_size;
    Global::clips[tileMonster].w = Global::pic_size;

    Global::clips[tilePlayer].x = 2 * Global::pic_size;
    Global::clips[tilePlayer].y = 0 * Global::pic_size;
    Global::clips[tilePlayer].h = Global::pic_size;
    Global::clips[tilePlayer].w = Global::pic_size;

    Global::clips[tileWall].x = 0 * Global::pic_size;
    Global::clips[tileWall].y = 1 * Global::pic_size;
    Global::clips[tileWall].h = Global::pic_size;
    Global::clips[tileWall].w = Global::pic_size;

    Global::clips[tileSpace].x = 1 * Global::pic_size;
    Global::clips[tileSpace].y = 1 *Global::pic_size;
    Global::clips[tileSpace].h = Global::pic_size;
    Global::clips[tileSpace].w = Global::pic_size;

    Global::clips[tilePole].x = 2 * Global::pic_size;
    Global::clips[tilePole].y = 1 * Global::pic_size;
    Global::clips[tilePole].h = Global::pic_size;
    Global::clips[tilePole].w = Global::pic_size;

    Global::clips[tileFrame].x = 3 * Global::pic_size;
    Global::clips[tileFrame].y = 0 *Global::pic_size;
    Global::clips[tileFrame].h = Global::pic_size;
    Global::clips[tileFrame].w = Global::pic_size;

    Global::clips[tileError].x = 3 * Global::pic_size;
    Global::clips[tileError].y = 1 * Global::pic_size;
    Global::clips[tileError].h = Global::pic_size;
    Global::clips[tileError].w = Global::pic_size;

    if (Global::blnDebugMode) {printf("Global::clips made.\n");}
}
/**********************************************************************************************************************************************/
void load_textures() {
    //Load tiles
    SDL_Surface* temp = IMG_ReadXPMFromArray(image_tiles_xpm);

    if (temp == nullptr) {
        printf("Failed to load embedded images.\n");
        error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Error surface created.\n");}
    }

	Global::textures.tilemap = SDL_CreateTextureFromSurface(Global::window.ren,temp);
	if (Global::textures.tilemap == nullptr) {
        printf("Failed to create texture.\n");
        error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Surface to texture successful\n");}
	    blnload.blnTiles = true;
    }


    //Load toolbox frame
    temp = IMG_ReadXPMFromArray(image_toolbox_frame_xpm);

    if (temp == nullptr) {
        printf("Failed to load embedded images.\n");
        error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Error surface created.\n");}
    }

	Global::textures.toolboxframe = SDL_CreateTextureFromSurface(Global::window.ren,temp);
	if (Global::textures.toolboxframe == nullptr) {
        printf("Failed to create texture.\n");
        error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Surface to texture successful\n");}
	    blnload.blnToolboxFrame = true;
    }

    SDL_FreeSurface(temp);
}
/**********************************************************************************************************************************************/
void start_screen() {
    Global::window.width = 35*Global::pic_size;
    Global::window.height = 14*Global::pic_size;
    blnload.blnMessage = blnload.blnMessageFont = blnload.blnTiles = blnload.blnToolboxFrame = false;
    blnload.blnWindow = blnload.blnRenderer = bln_SDL_Started = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        error();
        return;
    } else {
        bln_SDL_Started = true;
        if (Global::blnDebugMode) {printf("SDL init successful\n");}
    }

    //Start TTF
    if (TTF_Init() != 0) {
        error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("TTF init successful\n");}
    }

    //Start Image (with only png)
    if (!(IMG_Init( IMG_INIT_PNG )) & IMG_INIT_PNG) {
        error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("IMG init successful\n");}
    }

    Global::window.MessageFont = TTF_OpenFont(DEFINED_MESSAGE_FONT,16); //Opens font and sets size
    if ( Global::window.MessageFont == nullptr) {
        printf("Font failed to load, messages will not appear.");
        blnload.blnMessageFont = false;
    } else {
        if(Global::blnDebugMode) {printf("Message font created\n");}
       blnload.blnMessageFont = true;
    }

    Global::window.win = SDL_CreateWindow("Map Maker", 100, 100, Global::window.width, Global::window.height, SDL_WINDOW_SHOWN);
    if (Global::window.win == nullptr) {
        printf("SDL Failed to create Global::window.\n");
        error();
        return;
    } else {
        blnload.blnWindow = true;
        if (Global::blnDebugMode) {printf("Window creation successful\n");}
    }

    Global::window.ren = SDL_CreateRenderer(Global::window.win, -1, SDL_RENDERER_ACCELERATED);
    if (Global::window.ren == nullptr) {
        printf("SDL Failed to create renderer.\n");
        error();
        return;
    } else {
        blnload.blnRenderer = true;
        if (Global::blnDebugMode) {printf("Renderer creation successful\n");}
    }

    load_textures();
    if (bln_SDL_Started == false) {return;}

    colors.Black = {0, 0, 0, 0};
    //colors.White = (255, 255, 255, 0);
    show_screen();
}
/**********************************************************************************************************************************************/
void cleanup() {
    if (blnload.blnMessage) {
        SDL_DestroyTexture(Global::textures.texmessage);
        blnload.blnMessage = false;
        if(Global::blnDebugMode) {printf("Message texture destroyed.\n");}
    }

    if (blnload.blnTiles) {
        SDL_DestroyTexture(Global::textures.tilemap);
        blnload.blnTiles = false;
        if(Global::blnDebugMode) {printf("Map tile texture destroyed.\n");}
    }

    if (blnload.blnToolboxFrame) {
        SDL_DestroyTexture(Global::textures.toolboxframe);
        blnload.blnToolboxFrame = false;
        if(Global::blnDebugMode) {printf("Map tile texture destroyed.\n");}
    }

    if (blnload.blnMessageFont) {
        TTF_CloseFont(Global::window.MessageFont);
        blnload.blnMessageFont = false;
        if(Global::blnDebugMode) {printf("Message font destroyed.\n");}
    }

    if (blnload.blnRenderer) {
        SDL_DestroyRenderer(Global::window.ren);
        blnload.blnRenderer = false;
        if (Global::blnDebugMode) {printf("Renderer destroyed\n");}
    }

	if (blnload.blnWindow) {
        SDL_DestroyWindow(Global::window.win);
        blnload.blnWindow = false;
        if (Global::blnDebugMode) {printf("Window destroyed\n");}
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    if (Global::blnDebugMode) {printf("SDL quit\n");}
}
/**********************************************************************************************************************************************/
void error() {
    bln_SDL_Started = false;
    printf("SDL error: %s\n", SDL_GetError());
    printf("TTF error: %s\n", TTF_GetError());
    printf("IMG error: %s\n", IMG_GetError());
    getchar();
    cleanup();
}
/**********************************************************************************************************************************************/
void show_screen() {
    //Clear renderer
    SDL_RenderClear(Global::window.ren);
    //copy sky to cover entire screen.
    SDL_RenderCopy(Global::window.ren, Global::textures.tilemap, &Global::clips[tileSpace], NULL);
    SDL_Rect dst;
    for (uint y = 0; (y < 14); y++) {
        for (uint x = 0; (x < 217); x++) {
            //update where we're trying to put the texture.
            dst.x = x * Global::pic_size;
            dst.y = y * Global::pic_size;
            dst.h = Global::pic_size;
            dst.w = Global::pic_size;

            switch (Global::map[y][x]) { //Use this to make sure we aren't try to load a non-existing part
            case tileCoin:
            case tileMonster:
            case tilePlayer:
            case tilePole:
            case tileSpace:
            case tileWall:
                SDL_RenderCopy(Global::window.ren, Global::textures.tilemap, &Global::clips[Global::map[y][x]], &dst);
                break;
            default:
                SDL_RenderCopy(Global::window.ren, Global::textures.tilemap, &Global::clips[tileError], &dst);
                break;
            }
        } //end for x
    } //end for y

    draw_toolbox();
    SDL_RenderPresent(Global::window.ren);
}
/**********************************************************************************************************************************************/
void draw_toolbox() {



}
/**********************************************************************************************************************************************/
void check_events() {

}
/**********************************************************************************************************************************************/
void write_map() {
    FILE* savemap = fopen("map.sav","w");
    for (uint y = 0; y < 14; y++) {
        for (uint x = 0; x < 217; x++) {
            fprintf(savemap,"%u ", Global::map[y][x]);
        }
        fprintf(savemap, "\n");
    }
}
/**********************************************************************************************************************************************/
