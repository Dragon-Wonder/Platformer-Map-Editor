#ifndef CLSBUTTON_H
#define CLSBUTTON_H
/**********************************************************************************************************************************************/
#include "main.h"
/**********************************************************************************************************************************************/
class clsButton {
    public:
        clsButton();
        ~clsButton();

        void show(void);
        void handle_events();
        SDL_Rect getPlacement(void);
        void setbutton(uchar, uint, uint);

    private:
        SDL_Rect box;
        SDL_Rect* clip;
        uchar buttontype;

};
/**********************************************************************************************************************************************/
#endif // CLSBUTTON_H
