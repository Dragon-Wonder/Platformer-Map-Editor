/**********************************************************************************************************************************************/
//The main function, most of the actual program is found in Entity.cpp under start.
//So see there for most of the functions.
/**********************************************************************************************************************************************/
#include "main.h"
#include "version.h"
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

};
/**********************************************************************************************************************************************/
int main(int argc, char *argv[]) {
    bool quit = false;
    SDL_Event event;
	//TODO allow setting of map size
    /* TODO (GamerMan7799#1#): Add menu buttons (such as save, close, and reset, maybe others too) */

	//Initiate everything that needs it
    Textures::set_clips();
    Screen::start();
    //quits the program if there was an error starting SDL, its components or in getting the textures we need.
    if (Screen::bln_SDL_Started == false) {return 1;}
    //Make all the buttons for the toolbar
    Toolbar::make_buttons();

    while ( quit == false) {
		//TODO scrolling with arrows keys.
        Screen::show();
        if (SDL_PollEvent( &event ) ) {
            Toolbar::check_events( &event );
            if (event.type == SDL_QUIT) {quit = true;}
        }
    }

    //Clean up the screen
    Screen::cleanup();
	//TODO ask if should save
    Map::write_map();
	return 0;
}
/**********************************************************************************************************************************************/
void Textures::set_clips() {
    //Sets all the location of tiles in the main tile.png

    Textures::clips[tileCoin].x = 0 * Global::pic_size;
    Textures::clips[tileCoin].y = 0 * Global::pic_size;
    Textures::clips[tileCoin].h = Global::pic_size;
    Textures::clips[tileCoin].w = Global::pic_size;

    Textures::clips[tileMonster].x = 1 * Global::pic_size;
    Textures::clips[tileMonster].y = 0 * Global::pic_size;
    Textures::clips[tileMonster].h = Global::pic_size;
    Textures::clips[tileMonster].w = Global::pic_size;

    Textures::clips[tilePlayer].x = 2 * Global::pic_size;
    Textures::clips[tilePlayer].y = 0 * Global::pic_size;
    Textures::clips[tilePlayer].h = Global::pic_size;
    Textures::clips[tilePlayer].w = Global::pic_size;

    Textures::clips[tileWall].x = 0 * Global::pic_size;
    Textures::clips[tileWall].y = 1 * Global::pic_size;
    Textures::clips[tileWall].h = Global::pic_size;
    Textures::clips[tileWall].w = Global::pic_size;

    Textures::clips[tileSpace].x = 1 * Global::pic_size;
    Textures::clips[tileSpace].y = 1 *Global::pic_size;
    Textures::clips[tileSpace].h = Global::pic_size;
    Textures::clips[tileSpace].w = Global::pic_size;

    Textures::clips[tilePole].x = 2 * Global::pic_size;
    Textures::clips[tilePole].y = 1 * Global::pic_size;
    Textures::clips[tilePole].h = Global::pic_size;
    Textures::clips[tilePole].w = Global::pic_size;

    Textures::clips[tileFrame].x = 3 * Global::pic_size;
    Textures::clips[tileFrame].y = 0 *Global::pic_size;
    Textures::clips[tileFrame].h = Global::pic_size;
    Textures::clips[tileFrame].w = Global::pic_size;

    Textures::clips[tileError].x = 3 * Global::pic_size;
    Textures::clips[tileError].y = 1 * Global::pic_size;
    Textures::clips[tileError].h = Global::pic_size;
    Textures::clips[tileError].w = Global::pic_size;

    if (Global::blnDebugMode) {printf("Clips made.\n");}
}
/**********************************************************************************************************************************************/
void Textures::load() {
    //Load tiles
    SDL_Surface* temp = IMG_ReadXPMFromArray(image_tiles_xpm);

    if (temp == nullptr) {
        printf("Failed to load embedded images.\n");
        Screen::error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Error surface created.\n");}
    }

	Textures::tilemap = SDL_CreateTextureFromSurface(Screen::window.ren,temp);
	if (Textures::tilemap == nullptr) {
        printf("Failed to create texture.\n");
        Screen::error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Surface to texture successful\n");}
	    Screen::blnload.blnTiles = true;
    }

    //Load toolbox frame
    temp = IMG_ReadXPMFromArray(image_toolbox_frame_xpm);

    if (temp == nullptr) {
        printf("Failed to load embedded images.\n");
        Screen::error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Error surface created.\n");}
    }

	Textures::toolboxframe = SDL_CreateTextureFromSurface(Screen::window.ren,temp);
	if (Textures::toolboxframe == nullptr) {
        printf("Failed to create texture.\n");
        Screen::error();
        return;
	} else {
	    if (Global::blnDebugMode) {printf("Surface to texture successful\n");}
	    Screen::blnload.blnToolboxFrame = true;
    }

    SDL_FreeSurface(temp);
}
/**********************************************************************************************************************************************/
void Screen::start() {
    Screen::window.width = 35*Global::pic_size;
    Screen::window.height = 14*Global::pic_size;
    Screen::blnload.blnMessage = Screen::blnload.blnMessageFont = Screen::blnload.blnTiles = Screen::blnload.blnToolboxFrame = false;
    Screen::blnload.blnWindow = Screen::blnload.blnRenderer = Screen::bln_SDL_Started = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Screen::error();
        return;
    } else {
        Screen::bln_SDL_Started = true;
        if (Global::blnDebugMode) {printf("SDL init successful\n");}
    }

    //Start TTF
    if (TTF_Init() != 0) {
        Screen::error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("TTF init successful\n");}
    }

    //Start Image (with only png)
    if (!(IMG_Init( IMG_INIT_PNG )) & IMG_INIT_PNG) {
        Screen::error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("IMG init successful\n");}
    }

    Screen::window.MessageFont = TTF_OpenFont(DEFINED_MESSAGE_FONT,16); //Opens font and sets size
    if ( Screen::window.MessageFont == nullptr) {
        printf("Font failed to load, messages will not appear.");
        Screen::blnload.blnMessageFont = false;
    } else {
        if(Global::blnDebugMode) {printf("Message font created\n");}
       Screen::blnload.blnMessageFont = true;
    }

    Screen::window.win = SDL_CreateWindow("Map Maker", 100, 100, Screen::window.width, Screen::window.height, SDL_WINDOW_SHOWN);
    if (Screen::window.win == nullptr) {
        printf("SDL Failed to create Screen::window.\n");
        Screen::error();
        return;
    } else {
        Screen::blnload.blnWindow = true;
        if (Global::blnDebugMode) {printf("Screen::window creation successful\n");}
    }

    Screen::window.ren = SDL_CreateRenderer(Screen::window.win, -1, SDL_RENDERER_ACCELERATED);
    if (Screen::window.ren == nullptr) {
        printf("SDL Failed to create renderer.\n");
        Screen::error();
        return;
    } else {
        Screen::blnload.blnRenderer = true;
        if (Global::blnDebugMode) {printf("Renderer creation successful\n");}
    }

    Textures::load();
    if (Screen::bln_SDL_Started == false) {return;}

    Screen::colors.Black = {0, 0, 0, 0};
    //Screen::colors.White = (255, 255, 255, 0);
    //Screen::show();
}
/**********************************************************************************************************************************************/
void Screen::cleanup() {
    if (Screen::blnload.blnMessage) {
        SDL_DestroyTexture(Textures::texmessage);
        Screen::blnload.blnMessage = false;
        if(Global::blnDebugMode) {printf("Message texture destroyed.\n");}
    }

    if (Screen::blnload.blnTiles) {
        SDL_DestroyTexture(Textures::tilemap);
        Screen::blnload.blnTiles = false;
        if(Global::blnDebugMode) {printf("Map tile texture destroyed.\n");}
    }

    if (Screen::blnload.blnToolboxFrame) {
        SDL_DestroyTexture(Textures::toolboxframe);
        Screen::blnload.blnToolboxFrame = false;
        if(Global::blnDebugMode) {printf("Map tile texture destroyed.\n");}
    }

    if (Screen::blnload.blnMessageFont) {
        TTF_CloseFont(Screen::window.MessageFont);
        Screen::blnload.blnMessageFont = false;
        if(Global::blnDebugMode) {printf("Message font destroyed.\n");}
    }

    if (Screen::blnload.blnRenderer) {
        SDL_DestroyRenderer(Screen::window.ren);
        Screen::blnload.blnRenderer = false;
        if (Global::blnDebugMode) {printf("Renderer destroyed\n");}
    }

	if (Screen::blnload.blnWindow) {
        SDL_DestroyWindow(Screen::window.win);
        Screen::blnload.blnWindow = false;
        if (Global::blnDebugMode) {printf("Window destroyed\n");}
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    if (Global::blnDebugMode) {printf("SDL quit\n");}
}
/**********************************************************************************************************************************************/
void Screen::error() {
    Screen::bln_SDL_Started = false;
    printf("SDL error: %s\n", SDL_GetError());
    printf("TTF error: %s\n", TTF_GetError());
    printf("IMG error: %s\n", IMG_GetError());
    getchar();
    Screen::cleanup();
}
/**********************************************************************************************************************************************/
void Screen::show() {
    //Clear renderer
    SDL_RenderClear(Screen::window.ren);
    //copy sky to cover entire screen.
    SDL_RenderCopy(Screen::window.ren, Textures::tilemap, &Textures::clips[tileSpace], NULL);
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
                SDL_RenderCopy(Screen::window.ren, Textures::tilemap, &Textures::clips[Global::map[y][x]], &dst);
                break;
            default:
                SDL_RenderCopy(Screen::window.ren, Textures::tilemap, &Textures::clips[tileError], &dst);
                break;
            }
        } //end for x
    } //end for y

    Toolbar::draw();
    SDL_RenderPresent(Screen::window.ren);
}
/**********************************************************************************************************************************************/
void Toolbar::make_buttons() {
    uint centerx; //center of the toolbox
    centerx = (uint)(Screen::window.width / 2);
	//FIXME weird space in toolbar
    //Calculate all the places, the tool box frame has a 2 px wide border all the way around.
    for (uchar i = 0; i < 6; i++) {
        Toolbar::button_xplaces[i] = centerx - ( ( 2 - i ) * 4 ) - ( ( 2 - i ) * Global::pic_size );
        //if (i <= 2 ) {xplaces[i] -= 2;}
        //else {xplaces[i] += 2;}
    }

    for (uchar i = 0; i < 6; i++) {
        Toolbar::tilebuttons[i].buttontype = i;
        Toolbar::tilebuttons[i].clip = &Textures::clips[i];
        Toolbar::tilebuttons[i].box.w = Toolbar::tilebuttons[i].box.h = Global::pic_size;
        Toolbar::tilebuttons[i].box.y = 2;
        Toolbar::tilebuttons[i].box.x = Toolbar::button_xplaces[i];
    }
}
/**********************************************************************************************************************************************/
void Toolbar::draw() {

    //draw toolbox frame
    SDL_Rect dst;
    dst.w = dst.h = Global::pic_size + 4;
    dst.y = 0;
    for (uchar i = 0; i < 6; i++) {
        dst.x = Toolbar::button_xplaces[i] - 2;
        SDL_RenderCopy(Screen::window.ren, Textures::toolboxframe, NULL, &dst);
    }

    //Show all the buttons
    for (uchar i = 0; i < 6; i++) {
        SDL_RenderCopy(Screen::window.ren, Textures::tilemap, Toolbar::tilebuttons[i].clip, &Toolbar::tilebuttons[i].box);
        if (Toolbar::tilebuttons[i].buttontype == paintbrush.CurrentTile) {
            SDL_RenderCopy(Screen::window.ren, Textures::toolboxframe, NULL , &Toolbar::tilebuttons[i].box);
        }
    }
}
/**********************************************************************************************************************************************/
void Toolbar::check_events(SDL_Event* e) {
    if ( e->type == SDL_MOUSEBUTTONDOWN) {
        //get Mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //check all of the buttons to see if we are on that one.

        for (uchar i = 0; i < 6; i++) {
            if ( x >= Toolbar::tilebuttons[i].box.x && x <= Toolbar::tilebuttons[i].box.x + Toolbar::tilebuttons[i].box.w ) { //In the x range
                if ( y >= Toolbar::tilebuttons[i].box.y && y <= Toolbar::tilebuttons[i].box.y + Toolbar::tilebuttons[i].box.h) { //in the y range
                    paintbrush.CurrentTile = Toolbar::tilebuttons[i].buttontype;
                } //end if in y
            } // end if in x
        } // end for buttons


        //user did not click on any buttons therefore change the map tile.
        //convert to map coordinates
        uint mapx, mapy;

        mapx = (uint) (x / Global::pic_size);
        mapy = (uint) (y / Global::pic_size);

        Global::map[mapy][mapx] = paintbrush.CurrentTile;
    }
}
/**********************************************************************************************************************************************/
void Map::write_map() {
    FILE* savemap = fopen("map.sav","w");
    for (uint y = 0; y < 14; y++) {
        for (uint x = 0; x < 217; x++) {
            fprintf(savemap,"%u ", Global::map[y][x]);
        }
        fprintf(savemap, "\n");
    }
}
/**********************************************************************************************************************************************/

