#include "button.h"
/**********************************************************************************************************************************************/
clsButton::clsButton() {
    //ctor
    box.x = 0;
    box.y = 0;
    box.h = box.w = Global::pic_size;
    buttontype = 0;
    clip = &Global::clips[0];
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
void clsButton::setbutton(uchar buttontile, uint x, uint y) {
    box.x = x;
    box.y = y;
    buttontype = buttontile;
    clip = &Global::clips[buttontile];
}
/**********************************************************************************************************************************************/
