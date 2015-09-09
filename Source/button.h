#ifndef CLSBUTTON_H
#define CLSBUTTON_H
/**********************************************************************************************************************************************/
#include "main.h"
/**********************************************************************************************************************************************/
class clsButton {
    public:
        clsButton(uchar, uint, uint);
        ~clsButton();

        void show(void);
        void handle_events();
        SDL_Rect getPlacement(void);

    private:
        SDL_Rect box;
        SDL_Rect* clip;
        uchar buttontype;

};
/**********************************************************************************************************************************************/
#endif // CLSBUTTON_H
