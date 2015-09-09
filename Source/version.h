#ifndef __VERSION_HEADER__
#define __VERSION_HEADER__

//Initially was created using Code::Blocks' auto-versifying. However
//it kept really messing up the system I was using so I turned it off

//Date Version Types
#define DEFINED_VER_DATE "09"
#define DEFINED_VER_MONTH "09"
#define DEFINED_VER_YEAR "2015"
//I don't know what this is for, but I'll leave it for now.
#define DEFINED_VER_UBUNTU_VERSION_STYLE  "15.09"

//Standard Version Type
#define DEFINED_VER_MAJOR  0
#define DEFINED_VER_MINOR  1
#define DEFINED_VER_PATCH  0

//Miscellaneous Version Types
//Don't forget to increment the build number before each build
#define DEFINED_VER_RC_FILEVERSION 0,1,0,1
#define DEFINED_VER_RC_FILEVERSION_STRING "0,1,0,1\0"
#define DEFINED_VER_FULLVERSION_STRING  "0.1.0-alpha.1"

//Software Status
#define DEFINED_VER_STATUS 	"Alpha"
#define DEFINED_VER_STATUS_SHORT  "A"

/*
Software Status can be the following:
|===================|========|====================================================|
| Status            | Short  | Description                                        |
|===================|========|====================================================|
| Release           | r      | The supported release of the program               |
|===================|========|====================================================|
| Release Candidate | rc     | The next likely release version;                   |
|					|	     | usually only a few bugs / todos separate this from |
|					|		 | a release. It is pretty safe to use.               |
|===================|========|====================================================|
| Beta				| b      | This version will compile and / or run but does not|
|                   |        | work as expected (or crashes often)                |
|===================|========|====================================================|
| Alpha				| a		 | This version does not work at all; it usually won't|
|                   |        | compile at all or crashes more times than it works |
|                   |        | best not to use versions in this state             |
|===================|========|====================================================|
*/

#endif //__VERSION_HEADER__