# Change Log

All notable changes to this project will be documented here.
This project adheres to [Semantic Versioning](http://semver.org/)

## [1.1.0] - 2015-11-28
### Added
* Doxygen Support

### Changed
* All line seprators from 170 charaters long to 80 to allow me to see if I am breaking Google's recommended 80 charaters length 
	see [here] (https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Line_Length)


## [1.0.0] - 2015-09-22
### Added
* More Brick Textures (5 in total now) to add more variety to the map, and to allow easier transition into a different tile set in the future.
* Map loading
* Wno-write-strings to debug build to stop annoying messages about the xpm files.

### Changed
* Map tiles now saved in hexadecimal (no change to save yet as there are only 10 tiles but when we add more we don't have to worry about this.)
* Map tiles to be switched with Keys 0 - 9
* Made Save function simpler
* Program tells you save was successful

### Removed
* Sky tile being placed as the sky, now uses SDL_SetRenderDrawColor (really doesn't change anything but whatever)

### Fixed
* Tried to fix certain Textures not being properly transparent (doesn't appear to be working at the moment)

### Cleaned
* Code to make things simpler


## [0.9.0] - 2015-09-14
### Added 
* Menu Buttons (Save and close)

### Removed
* Lots of unneeded code

## Fixed
* Offset going off of map


## [0.8.0] / Version Clown - 2015-09-12
### Fixed
* Several Copy Paste mistakes that weren't removed before.

### Removed
* Cleaned up some code that didn't make that much sense
* Some unneeded comments

### Added
* Additional Todos

### Notes
* I was going through the code with xPUREx to bring him up to speed on this project and this version is mostly
 the mistakes we found while going through it.


## [0.7.0] - 2015-09-10
### Added
* Dragging for editing map
* Prompt for getting new map
* Prompt for quitting if hitting 'Q' or ESC

### Changed
* Windows Font from Arial to Garamond


## [0.6.0] - 2015-09-10
### Added
* Restarting of map
* Switching tile by num keys 1 - 6
* Prompt to replace a map save

### Fixed
* Drawing map on being messed being I forgot to factor in offset


## [0.5.0] - 2015-09-10
### Added
* Save icon, Close icon, left and right arrows to tile map (not implemented yet)
* Moving camera with arrow keys
* Defines
* Saving Map with key press ('v')
* Quiting with Key press ('q' or ESC)


## [0.4.0] - 2015-09-10
### Updated
* Makefile

### Fixed
* Some buttons not working because of a copy paste error

### Changed
* Buttons are now a structure so I can put them into an array to check them.
* Buttons are now an array so it is easier to loop through them all

### Added
* Namespaces

### Removed
* Button Class (really doesn't need to be a class yet)


## [0.3.0] - 2015-09-09
### Changed
* How buttons are made.

### Added
* You can now change the map
* You can now change your tile


## [0.2.0] - 2015-09-09
### Added
* Toolbox rendering
* Quick event handling


## [0.1.0] - 2015-09-08
### Notes
* Initial
