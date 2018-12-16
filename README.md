# TIC TAC TOE
###### by: x-XLVII-x ( 47 )

Simple Tic Tac Toe game written on C++.
Nothing too fancy, just meant as a high school project.

Users can use the arrow keys to move arround and enter key to select their input.
User can play against another user or try to beat the computer.

Developer tested on: `g++ version 6.3.0 ( MinGW )` on Windows 10
The code is not system dependant and should compile with any C++ compiler/IDE.

*The code uses console clearing to work. Check the `Clean()` function in the cpp file and use the appropriate function for your system*

### IDEs
* should compile with most IDEs which support gcc/g++
* If using dosbox on windows, use `clrscr()` in 'Clean()' function


### Windows CMD Terminal
* To install MinGW: [Click Here](https://sourceforge.net/projects/mingw/files/Installer/)
* install gcc and g++ using the setup
* Simple google search should help
* If you are using MinGW g++, compile using: `g++ <file-location\TicTacToe.cpp> -o <file-location\TicTacToe.exe>`
* Run using the the executable file generated or: `<file-location\TicTacToe.exe>`
* Use `system( "cls" )` in `Clean()` function


### Debian/Ubuntu Linux Terminal
* To install gcc/g++ compiler: `sudo apt-get install build-essential`
* To complie: `sudo g++ -o <file-loaction/TicTacToe.out> <file-loaction/TicTacToe>`
* To run: `<file-location/TicTacToe.out>`


