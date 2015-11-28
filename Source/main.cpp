/*****************************************************************************/
#include "main.h"
#include "version.h"
/*****************************************************************************/
/////////////////////////////////////////////////
/// @file main.cpp
/// @brief  This is the main file that holds all of the code.
/////////////////////////////////////////////////
/*****************************************************************************/
#include "image_tiles.xpm"
#include "image_toolbox_frame.xpm"
/*****************************************************************************/
namespace Global {
    //Holds if in debug mode or not. Causes more messages to appear in the console.
    //Defined in version.h
    #ifndef DEFINED_BUILD_MODE_PRIVATE
        const bool blnDebugMode = false;
    #else
        const bool blnDebugMode = true;
    #endif // DEFINED_BUILD_MODE_PRIVATE
    const uint pic_size = 24;
    uchar map[DEFINED_MAP_HEIGHT][DEFINED_MAP_WIDTH] = {{1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
/*****************************************************************************/
int main(int argc, char *argv[]) {
    /////////////////////////////////////////////////
    /// @brief The main function. Holds the loop that keeps SDL running.
    ///
    /// @param argc = something required by SDL.
    /// @param argv = something required by SDL.
    /// @return 1 for error during run, 0 for run successful.
    ///
    /////////////////////////////////////////////////

    bool quit = false;
    SDL_Event event;
	//TODO allow setting of map size

	//Initiate everything that needs it
    Textures::set_clips();
    Screen::start();
    //quits the program if there was an error starting SDL, its components or in getting the textures we need.
    if ( !Screen::bln_SDL_Started ) {return 1;}
    //Make all the buttons for the toolbar
    Toolbar::make_buttons();

    while ( !quit ) {
        Screen::show();
        if (SDL_PollEvent( &event ) != 0 ) {
            Toolbar::check_events( &event );
            if (event.type == SDL_QUIT) {quit = true;}
        } //end if event
    } //end while not quit

    //Clean up the screen
    Screen::cleanup();
	return 0;
}
/*****************************************************************************/
void Textures::set_clips() {
    /////////////////////////////////////////////////
    /// @brief Sets all the clip locations of the different tiles.
    ///    The Picture Coordinates (x,y)
    ///    we multiply this by the pic size to get the clip
    ///    +-----+-----+-----+-----+
    ///    |(0,0)|(1,0)|(2,0)|(3,0)|
    ///    +-----+-----+-----+-----+
    ///    |(0,1)|(1,1)|(2,1)|(3,1)|
    ///    +-----+-----+-----+-----+
    ///    |(0,2)|(1,2)|(2,2)|(3,2)|
    ///    +-----+-----+-----+-----+
    ///    |(0,3)|(1,3)|(2,3)|(3,3)|
    ///    +-----+-----+-----+-----+
    ///
    /// @return void
    ///
    /////////////////////////////////////////////////

    //Sets all the location of tiles in the main tile.png

    //since all of the sizes are the same size we will do this all together to save space
    for (uchar i = 0; i < DEFINED_NUM_OF_TILES; i++) {
        Textures::clips[i].w = Textures::clips[i].h = Global::pic_size;
    }

    //First row, Coin, Monster, Player, Frame
    Textures::clips[tileCoin].x = 0 * Global::pic_size;
    Textures::clips[tileCoin].y = 0 * Global::pic_size;

    Textures::clips[tileMonster].x = 1 * Global::pic_size;
    Textures::clips[tileMonster].y = 0 * Global::pic_size;

    Textures::clips[tilePlayer].x = 2 * Global::pic_size;
    Textures::clips[tilePlayer].y = 0 * Global::pic_size;

    Textures::clips[menuFrame].x = 3 * Global::pic_size;
    Textures::clips[menuFrame].y = 0 * Global::pic_size;

    //Second Row, Large Bricks, sky, pole, error
    Textures::clips[tileBricksLarge].x = 0 * Global::pic_size;
    Textures::clips[tileBricksLarge].y = 1 * Global::pic_size;

    Textures::clips[tileSpace].x = 1 * Global::pic_size;
    Textures::clips[tileSpace].y = 1 * Global::pic_size;

    Textures::clips[tilePole].x = 2 * Global::pic_size;
    Textures::clips[tilePole].y = 1 * Global::pic_size;

    Textures::clips[menuError].x = 3 * Global::pic_size;
    Textures::clips[menuError].y = 1 * Global::pic_size;

    //Third Row, Save, Close, Left and Right
    Textures::clips[menuSave].x = 0 * Global::pic_size;
    Textures::clips[menuSave].y = 2 * Global::pic_size;

    Textures::clips[menuClose].x = 1 * Global::pic_size;
    Textures::clips[menuClose].y = 2 * Global::pic_size;

    Textures::clips[menuLeft].x = 2 * Global::pic_size;
    Textures::clips[menuLeft].y = 2 * Global::pic_size;

    Textures::clips[menuRight].x = 3 * Global::pic_size;
    Textures::clips[menuRight].y = 2 * Global::pic_size;

    //Forth Row, Small Bricks, Gray Bricks, Green Bricks, Orange Bricks
    //that almost sounds like a Dr. Seuss Rhyme
    Textures::clips[tileBricksSmall].x = 0 * Global::pic_size;
    Textures::clips[tileBricksSmall].y = 3 * Global::pic_size;

    Textures::clips[tileBricksGray].x = 1 * Global::pic_size;
    Textures::clips[tileBricksGray].y = 3 * Global::pic_size;

    Textures::clips[tileBricksGreen].x = 2 * Global::pic_size;
    Textures::clips[tileBricksGreen].y = 3 * Global::pic_size;

    Textures::clips[tileBricksOrange].x = 3 * Global::pic_size;
    Textures::clips[tileBricksOrange].y = 3 * Global::pic_size;

    if (Global::blnDebugMode) {printf("Clips made.\n");}
}
/*****************************************************************************/
void Textures::load() {
    /////////////////////////////////////////////////
    /// @brief Loads all of the different textures needed into memory.
    /////////////////////////////////////////////////

    //Load tiles

    SDL_Surface* temp = IMG_ReadXPMFromArray(image_tiles_xpm); //load array
    //Color to be replaced with transparent
    Uint32 colorKey = SDL_MapRGB( SDL_GetWindowSurface( Screen::window.win )->
                                                    format, 0x00, 0xFF, 0x00);

    //For the maptiles we have to do some additional work to convert all the whitespace into transparent pixels
	Textures::tilemap = temp == nullptr ? nullptr : Textures::makeTransparent(temp, colorKey);

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
	Textures::toolboxframe =  (temp == nullptr) ? nullptr :
                    SDL_CreateTextureFromSurface(Screen::window.ren,temp);
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
/*****************************************************************************/
SDL_Texture* Textures::makeTransparent(SDL_Surface* surface, Uint32 colorKey) {
    /////////////////////////////////////////////////
    /// @brief Was an attempt to try to fix an error with the toolbox frame texture.
    ///        The frame was not appearing transparent as it is supposed to be.
    ///        Used a tutorial found [here](http://lazyfoo.net/tutorials/SDL/40_texture_manipulation/index.php)
    ///        Doesn't work as of right now.
    ///
    /// @param surface = Pointer to the surface we want to make transparent.
    /// @param colorKey = The color we want to make transparent.
    /// @return Pointer to the texture.
    ///
    /////////////////////////////////////////////////

    int mPitch = 0;
    void* mPixels = nullptr;

    if ( surface == nullptr ) {return nullptr;}

    SDL_Texture* tex;
    //Convert the surface to a formatted one.
    SDL_Surface* formattedSurface = SDL_ConvertSurface( surface,
                                    SDL_GetWindowSurface( Screen::window.win )->format, NULL );
    if (formattedSurface == nullptr) {return nullptr;}
    //Create texture from formatted Surface
    tex = SDL_CreateTexture( Screen::window.ren, SDL_GetWindowPixelFormat( Screen::window.win ),
                             SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );

    //now start editing the texture
    // Lock the texture for manipulation
    SDL_LockTexture( tex, NULL, &mPixels, &mPitch );

    //Copy loaded/formatted surface pixels
    std::memcpy( mPixels, formattedSurface->pixels,
                            formattedSurface->pitch * formattedSurface->h);

    Uint32* pixels = (Uint32*)mPixels;
    int pixelCount = ( mPitch / 4 ) * formattedSurface->h;

    // Transparent / what will replace color above
    Uint32 transparent = SDL_MapRGBA( SDL_GetWindowSurface( Screen::window.win )->
                                     format, 0xFF, 0xFF, 0xFF, 0x00 );

    //change pixel if it is the same as color key
    for (int i = 0; i < pixelCount; i++) {
        if ( pixels[i] == colorKey ) {
            pixels[i] = transparent;
        } //end if equals color key
    } //end for pixelcount

    //Unlock texture to update
    SDL_UnlockTexture( tex );
    return tex;
}
/*****************************************************************************/
void Screen::start() {
    /////////////////////////////////////////////////
    /// @brief Starts the screen, SDL and all of the components we need it to.
    /////////////////////////////////////////////////

    Screen::window.width = 35 * Global::pic_size;
    Screen::window.height = 14 * Global::pic_size;
    Screen::blnload.blnMessage = Screen::blnload.blnMessageFont =
            Screen::blnload.blnTiles = Screen::blnload.blnToolboxFrame = false;
    Screen::blnload.blnWindow = Screen::blnload.blnRenderer = Screen::bln_SDL_Started = false;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Screen::error();
        return;
    } else {
        Screen::bln_SDL_Started = true;
        if (Global::blnDebugMode) {printf("SDL init successful\n");}
    }

    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

    if ( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ) {
        Screen::error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("TTF init successful\n");}
    }


    //Start TTF
    if (TTF_Init() != 0) {
        Screen::error();
        return;
    } else {
        if (Global::blnDebugMode) {printf("TTF init successful\n");}
    }

    Screen::window.MessageFont = TTF_OpenFont(DEFINED_MESSAGE_FONT,16); //Opens font and sets size
    if ( Screen::window.MessageFont == nullptr) {
        printf("Font failed to load, messages will not appear.");
        Screen::blnload.blnMessageFont = false;
    } else {
        if(Global::blnDebugMode) {printf("Message font created\n");}
       Screen::blnload.blnMessageFont = true;
    }

    Screen::window.win = SDL_CreateWindow("Map Maker", 100, 100,
                                    Screen::window.width, Screen::window.height, SDL_WINDOW_SHOWN);
    if (Screen::window.win == nullptr) {
        printf("SDL Failed to create window.\n");
        Screen::error();
        return;
    } else {
        Screen::blnload.blnWindow = true;
        if (Global::blnDebugMode) {printf("Window creation successful\n");}
    }

    Screen::window.ren = SDL_CreateRenderer(Screen::window.win, -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Screen::window.ren == nullptr) {
        printf("SDL Failed to create renderer.\n");
        Screen::error();
        return;
    } else {
        Screen::blnload.blnRenderer = true;
        if (Global::blnDebugMode) {printf("Renderer creation successful\n");}
    }

    //Set the renderer background color to white
    SDL_SetRenderDrawColor(Screen::window.ren, 0xFF, 0xFF, 0xFF, 0xFF);

    Textures::load();
    if (!Screen::bln_SDL_Started) {return;}

    Screen::colors.Black = {0x0, 0x0, 0x0, 0xFF};
    Screen::colors.White = {0xFF, 0xFF, 0xFF, 0xFF};
}
/*****************************************************************************/
void Screen::cleanup() {
    /////////////////////////////////////////////////
    /// @brief Cleans up all the items in memory by first checking if it exists
    ///        and deleting it if it does.
    /////////////////////////////////////////////////

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
        if(Global::blnDebugMode) {printf("Toolbox frame destroyed.\n");}
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
    SDL_Quit();
    IMG_Quit();
    if (Global::blnDebugMode) {printf("SDL quit\n");}
}
/*****************************************************************************/
void Screen::error() {
    /////////////////////////////////////////////////
    /// @brief Is called when there is an error. Sets Screen::bln_SDL_Started to false,
    ///        prints the error to the screen and then calls cleanup.
    /////////////////////////////////////////////////

    Screen::bln_SDL_Started = false;
    printf("SDL error: %s\n", SDL_GetError());
    printf("TTF error: %s\n", TTF_GetError());
    getchar();
    Screen::cleanup();
}
/*****************************************************************************/
void Screen::show() {
    /////////////////////////////////////////////////
    /// @brief Updates the renderer with new tile placements.
    /////////////////////////////////////////////////

    //Clear renderer
    SDL_RenderClear(Screen::window.ren);
    //copy sky to cover entire screen.
    SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                   &Textures::clips[tileSpace], NULL);
    SDL_Rect dst;
    dst.h = dst.w = Global::pic_size;

    for (uint y = 0; (y < DEFINED_MAP_HEIGHT); y++) {
        for (uint x = 0; (x < DEFINED_MAP_WIDTH); x++) {
            //update where we're trying to put the texture.
            dst.x = (x * Global::pic_size) - Screen::offset.x;
            dst.y = (y * Global::pic_size) - Screen::offset.y;

            switch (Global::map[y][x]) { //Use this to make sure we aren't try to load a non-existing part
            case tileCoin:
            case tileMonster:
            case tilePlayer:
            case tilePole:
            case tileSpace:
            case tileBricksLarge:
            case tileBricksGray:
            case tileBricksGreen:
            case tileBricksOrange:
            case tileBricksSmall:
                SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                               &Textures::clips[Global::map[y][x]], &dst);
                break;
            default:
                SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                               &Textures::clips[menuError], &dst);
                break;
            } //end switch
        } //end for x
    } //end for y

    Toolbar::draw();
    SDL_RenderPresent(Screen::window.ren);
}
/*****************************************************************************/
char Screen::promptuser(uchar prompttype, std::string message) {
    /////////////////////////////////////////////////
    /// @brief Prompts the user for some information.
    ///
    /// @param propmttype = What prompt to the user, Yes/No or an Okay.
    /// @param message = The message that appears above the prompt.
    /// @return What key is pressed by the user.
    ///
    /////////////////////////////////////////////////

    //Prompt the user for something, prompt the user for something.
    //returns what they say.

    //Clear the Renderer
    SDL_RenderClear(Screen::window.ren);

    SDL_Surface* surmessage = TTF_RenderText_Solid(Screen::window.MessageFont,
                                        message.c_str(), Screen::colors.Black);
    if (surmessage == nullptr) {
            Screen::error();
            return 'F';
    }

    SDL_Rect dst;

    Textures::texmessage = SDL_CreateTextureFromSurface(Screen::window.ren, surmessage);
    if (Textures::texmessage == nullptr) {
        Screen::error();
        return 'F';
    } else {Screen::blnload.blnMessage = true;}

    SDL_QueryTexture(Textures::texmessage, NULL, NULL, &dst.w, &dst.h);
    //figure out x and y so that message is in the middle

    dst.x = (uint) ((Screen::window.width / 2) - (dst.w / 2));
    dst.y = (uint) ((Screen::window.height / 2) - (dst.h / 2));

    SDL_RenderCopy(Screen::window.ren, Textures::texmessage, NULL, &dst);

    std::string message2;

    switch (prompttype) {
    case promptYesNo:
        message2 = "Please hit Y for yes, or N for no.";
        break;
    case promptOkay:
        message2 = "Please hit any button to close.";
        break;
    default :
        message2 = " ";
        break;
    }

    surmessage = TTF_RenderText_Solid(Screen::window.MessageFont,
                                message2.c_str(), Screen::colors.Black);
    if (surmessage == nullptr) {
            Screen::error();
            return 'F';
    }

    Textures::texmessage = SDL_CreateTextureFromSurface(Screen::window.ren, surmessage);
    if (Textures::texmessage == nullptr) {
        Screen::error();
        return 'F';
    } else {Screen::blnload.blnMessage = true;}

    SDL_QueryTexture(Textures::texmessage, NULL, NULL, &dst.w, &dst.h);
    //figure out x and y so that message is in the middle, but below the first message
    dst.x = (uint) ((Screen::window.width / 2) - (dst.w / 2));
    dst.y = (uint) ((Screen::window.height / 2) + (dst.h / 2));

    SDL_RenderCopy(Screen::window.ren, Textures::texmessage, NULL, &dst);

    bool blnStopLoop = false;
    char keyPress;
    SDL_Event event;

    //Start looping while wait for a response.
    do {
        SDL_RenderPresent(Screen::window.ren);
        if (SDL_PollEvent( &event ) ) {
            if (event.type == SDL_QUIT) {
                //player wants to quit leave the loop
                keyPress = 'N';
                blnStopLoop = true;
            } else if (event.type == SDL_KEYDOWN) {
                switch (prompttype) {
                case promptOkay:
                    keyPress = 'O';
                    blnStopLoop = true;
                    break;
                case promptYesNo:
                    switch (event.key.keysym.sym) {
                    case SDLK_y:
                        keyPress = 'Y';
                        blnStopLoop = true;
                        break;
                    case SDLK_n:
                        keyPress = 'N';
                        blnStopLoop = true;
                        break;
                    } //end switch key
                }//end switch prompt type
            } // end if event type
        } //end if poll event
    } while (blnStopLoop == false);
    return keyPress;
}
/*****************************************************************************/
void Toolbar::make_buttons() {
    /////////////////////////////////////////////////
    /// @brief Makes all the buttons for the toolbar.
    /////////////////////////////////////////////////

    uint centerx; //center of the toolbox
    centerx = (uint)(Screen::window.width / 2);
    //Calculate all the places, the tool box frame has a 2 px wide border all the way around.
    //Make tile buttons
    for (uchar i = 0; i < DEFINED_NUM_BUTN_TILES; i++) {
        Toolbar::button_xplaces[i] = centerx - ( ( (DEFINED_NUM_BUTN_TILES / 2)- i ) * 4 )
                                    - ( ( (DEFINED_NUM_BUTN_TILES / 2) - i ) * Global::pic_size );
    }

    for (uchar i = 0; i < DEFINED_NUM_BUTN_TILES; i++) {
        Toolbar::tilebuttons[i].buttontype = i;
        Toolbar::tilebuttons[i].clip = &Textures::clips[i];
        Toolbar::tilebuttons[i].box.w = Toolbar::tilebuttons[i].box.h = Global::pic_size;
        Toolbar::tilebuttons[i].box.y = 2;
        Toolbar::tilebuttons[i].box.x = Toolbar::button_xplaces[i];
    }

    //Make menu buttons
    for (uchar i = 0; i < DEFINED_NUM_BUTN_MENU; i++) {
        Toolbar::menubuttons[i].buttontype = menuClose + i;
        Toolbar::menubuttons[i].clip = &Textures::clips[menuClose + i];
        Toolbar::menubuttons[i].box.w = Toolbar::menubuttons[i].box.h = Global::pic_size;
        Toolbar::menubuttons[i].box.y = 2;
        Toolbar::menubuttons[i].box.x = (Screen::window.width - 2) - ( (i+1) * Global::pic_size);
    }
}
/*****************************************************************************/
void Toolbar::draw() {
    /////////////////////////////////////////////////
    /// @brief Draws the toolbar.
    /////////////////////////////////////////////////


    //draw toolbox frame
    SDL_Rect dst;
    dst.w = dst.h = Global::pic_size + 4;
    dst.y = 0;
    for (uchar i = 0; i < DEFINED_NUM_BUTN_TILES; i++) {
        dst.x = Toolbar::button_xplaces[i] - 2;
        SDL_RenderCopy(Screen::window.ren, Textures::toolboxframe, NULL, &dst);
    }

    //Show all the tile buttons
    for (uchar i = 0; i < DEFINED_NUM_BUTN_TILES; i++) {
        SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                       Toolbar::tilebuttons[i].clip, &Toolbar::tilebuttons[i].box);
        if (Toolbar::tilebuttons[i].buttontype == paintbrush.CurrentTile) {
            SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                           &Textures::clips[menuFrame] , &Toolbar::tilebuttons[i].box);
        }
    }

    //show all the menu buttons
    for (uchar i = 0; i < DEFINED_NUM_BUTN_MENU; i++) {
        SDL_RenderCopy(Screen::window.ren, Textures::tilemap,
                       Toolbar::menubuttons[i].clip, &Toolbar::menubuttons[i].box);
    }
}
/*****************************************************************************/
void Toolbar::check_events(SDL_Event* e) {
    /////////////////////////////////////////////////
    /// @brief Checks an SDL event to see what the program should do.
    /// @param e = Pointer to the event that happened.
    /////////////////////////////////////////////////

    static bool blnButtonDown;
    if (e->type == SDL_MOUSEBUTTONUP) {blnButtonDown = false;}
    if ( e->type == SDL_MOUSEBUTTONDOWN || blnButtonDown) {
        blnButtonDown = true;
        //get Mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //check all of the tile buttons to see if we are on that one.
        for (uchar i = 0; i < DEFINED_NUM_BUTN_TILES; i++) {
            if ( x >= Toolbar::tilebuttons[i].box.x && x <=
                            Toolbar::tilebuttons[i].box.x + Toolbar::tilebuttons[i].box.w ) { //In the x range
                if ( y >= Toolbar::tilebuttons[i].box.y && y <=
                            Toolbar::tilebuttons[i].box.y + Toolbar::tilebuttons[i].box.h) { //in the y range
                    paintbrush.CurrentTile = Toolbar::tilebuttons[i].buttontype;
                } //end if in y
            } // end if in x
        } // end for buttons

        //check all of the menu buttons
        for (uchar i = 0; i < DEFINED_NUM_BUTN_MENU; i++) {
            if ( x >= Toolbar::menubuttons[i].box.x && x <=
                        Toolbar::menubuttons[i].box.x + Toolbar::menubuttons[i].box.w ) { //In the x range
                if ( y >= Toolbar::menubuttons[i].box.y && y <=
                        Toolbar::menubuttons[i].box.y + Toolbar::menubuttons[i].box.h) { //in the y range
                    blnButtonDown = false;
                    switch (Toolbar::menubuttons[i].buttontype) {
                    case menuSave:
                        Map::save();
                        break;
                    case menuClose:
                        if (Screen::promptuser(promptYesNo, "Do you really want to quit?") == 'Y') {
                            e->type = SDL_QUIT;
                        } //end if yes
                        break;
                    } //end switch
                } //end if in y
            } // end if in x
        } //end for menu buttons


        //user did not click on any buttons therefore change the map tile.
        //convert to map coordinates
        uint mapx, mapy;
        mapx = (uint) ( (x + Screen::offset.x) / Global::pic_size);
        mapy = (uint) ( (y + Screen::offset.y) / Global::pic_size);

        Global::map[mapy][mapx] = paintbrush.CurrentTile;
    } else if (e->type == SDL_KEYDOWN) {

        switch( e->key.keysym.sym) {
        //All of the directional cases
        case SDLK_UP:
        case SDLK_w:
            Screen::offset.y -= Global::pic_size;
            if (Screen::offset.y < 0) {Screen::offset.y = 0;}
            break;
        case SDLK_DOWN:
        case SDLK_s:
            Screen::offset.y += Global::pic_size;
            if (Screen::offset.y > (DEFINED_MAP_HEIGHT * Global::pic_size) - Screen::window.height)
                {Screen::offset.y = (DEFINED_MAP_HEIGHT * Global::pic_size) - Screen::window.height;}
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            Screen::offset.x += Global::pic_size;
            if (Screen::offset.x > (DEFINED_MAP_WIDTH * Global::pic_size) - Screen::window.width)
                {Screen::offset.x = (DEFINED_MAP_WIDTH * Global::pic_size) - Screen::window.width;}
            break;
        case SDLK_LEFT:
        case SDLK_a:
            Screen::offset.x -= Global::pic_size;
            if (Screen::offset.x < 0) {Screen::offset.x = 0;}
            break;
        case SDLK_HOME:
            Screen::offset.x = Screen::offset.y = 0;
            break;
        case SDLK_END:
            Screen::offset.x = (DEFINED_MAP_WIDTH * Global::pic_size) - Screen::window.width;
            break;
        case SDLK_PAGEDOWN:
            Screen::offset.x -= Screen::window.width;
            break;
        case SDLK_PAGEUP:
            Screen::offset.x += Screen::window.width;
            break;

        //Quiting cases
        case SDLK_q:
        case SDLK_ESCAPE:
            //change the event type to be a quit.
            if (Screen::promptuser(promptYesNo, "Do you really want to quit?") == 'Y') {
                e->type = SDL_QUIT;
                return;
            }
            break;

        //Menu cases
        case SDLK_v:
            Map::save();
            break;
        case SDLK_n:
            Map::newmap();
            break;
        case SDLK_l:
            Map::load();
            break;

        //Switch tile
        case SDLK_1:
            Toolbar::paintbrush.CurrentTile = tileSpace;
            break;
        case SDLK_2:
            Toolbar::paintbrush.CurrentTile = tileBricksLarge;
            break;
        case SDLK_3:
            Toolbar::paintbrush.CurrentTile = tilePlayer;
            break;
        case SDLK_4:
            Toolbar::paintbrush.CurrentTile = tilePole;
            break;
        case SDLK_5:
            Toolbar::paintbrush.CurrentTile = tileMonster;
            break;
        case SDLK_6:
            Toolbar::paintbrush.CurrentTile = tileCoin;
            break;
        case SDLK_7:
            Toolbar::paintbrush.CurrentTile = tileBricksSmall;
            break;
        case SDLK_8:
            Toolbar::paintbrush.CurrentTile = tileBricksGray;
            break;
        case SDLK_9:
            Toolbar::paintbrush.CurrentTile = tileBricksGreen;
            break;
        case SDLK_0:
            Toolbar::paintbrush.CurrentTile = tileBricksOrange;
            break;
        } //end switch
    } //end if event type
}
/*****************************************************************************/
void Map::save() {
    /////////////////////////////////////////////////
    /// @brief Saves the map to map.sav.
    /////////////////////////////////////////////////

    FILE* savemap;
    savemap = fopen("map.sav", "r");
    char Answer;
    if (savemap != NULL) {
        if (Global::blnDebugMode) {printf("Save found.\n");}
        Answer = Screen::promptuser(promptYesNo, "Save already exists, would you like to overwrite?");
    } else { if (Global::blnDebugMode) {printf("No save found.\n");} }//end if savemap = null

    if (Answer == 'Y' || savemap == NULL) {
        fclose(savemap);
        savemap = fopen("map.sav", "w");
        if (Global::blnDebugMode) {printf("Make save.\n");}
        for (uint y = 0; y < DEFINED_MAP_HEIGHT; y++) {
            for (uint x = 0; x < DEFINED_MAP_WIDTH; x++) {
                fprintf(savemap,"%2x", Global::map[y][x]);
            } //end for x
            fprintf(savemap, "\n");
        } //end for y
        Screen::promptuser(promptOkay, "Save successful.");
    } //end if map save
    fclose(savemap);
}
/*****************************************************************************/
void Map::load() {
    /////////////////////////////////////////////////
    /// @brief Loads the map from map.sav.
    /////////////////////////////////////////////////

    if (Screen::promptuser(promptYesNo, "Do you want to load old map? All progress will be lost.") == 'Y' ){
        FILE* mapload = fopen("map.sav", "r");
        if (mapload == NULL) {Screen::promptuser(promptOkay, "Saved map could not be found!"); return;}
        for (uint y = 0; y < DEFINED_MAP_HEIGHT; y++) {
            for (uint x = 0; x < DEFINED_MAP_WIDTH; x++) {
                fscanf(mapload, "%2x", &Global::map[y][x] );
            } //end for x
        } //end for y
    } //end if yes
}
/*****************************************************************************/
void Map::newmap() {
    /////////////////////////////////////////////////
    /// @brief Fills all of the map with spaces.
    /////////////////////////////////////////////////

    //New map; completely blank
    if (Screen::promptuser(promptYesNo, "Do you really want to completely blank the map?") == 'Y') {
        for (uint y = 0; y < DEFINED_MAP_HEIGHT; y++) {
            for (uint x = 0; x < DEFINED_MAP_WIDTH; x++) {
                Global::map[y][x] = tileSpace;
            } //end for x
        } //end for y
    } //end if yes
}
/*****************************************************************************/
