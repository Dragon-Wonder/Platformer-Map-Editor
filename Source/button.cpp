#include "button.h"
/**********************************************************************************************************************************************/
clsButton::clsButton(uchar tile, uint x, uint y) {
    //ctor
    box.x = x;
    box.y = y;
    box.h = box.w = Global::pic_size;
    buttontype = tile;
    clip = &Global::clips[tile];
}
/**********************************************************************************************************************************************/
clsButton::~clsButton() {
    //dtor
}
/**********************************************************************************************************************************************/
void clsButton::show() {
    //Put button where it belongs
    SDL_RenderCopy(Global::window.ren, Global::textures.tilemap, clip, &box);
    //If this button repents the current paintbrush draw an extra frame around it.
    if (Global::paintbrush.CurrentTile == buttontype) {
        SDL_RenderCopy(Global::window.ren, Global::textures.tilemap, &Global::clips[tileFrame], &box);
    }
}
/**********************************************************************************************************************************************/
void clsButton::handle_events() {



    Global::paintbrush.CurrentTile = buttontype;
}
/**********************************************************************************************************************************************/
SDL_Rect clsButton::getPlacement() {
    return box;
}
/**********************************************************************************************************************************************/
