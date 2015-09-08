/**********************************************************************************************************************************************/
//The main function, most of the actual program is found in Entity.cpp under start.
//So see there for most of the functions.
/**********************************************************************************************************************************************/
#include "version.h"
#include "screen.h"
/**********************************************************************************************************************************************/
//Globals
namespace Global {
    //Holds if in debug mode or not. Causes more messages to appear in the console.
    //Defined in version.h
    #ifndef DEFINED_BUILD_MODE_PRIVATE
        const bool blnDebugMode = false;
    #else
        const bool blnDebugMode = true;
    #endif // DEFINED_BUILD_MODE_PRIVATE

	bool blnError = false; //if there was an error; then the program will exit when it checks this.
};
/**********************************************************************************************************************************************/
int main(int argc, char *argv[]) {
    clsScreen Screen; //create the screen, here so it is always called

    Screen.~clsScreen();
	printf("\nDone\n");
	getchar();
	return 0;
}
/**********************************************************************************************************************************************/
