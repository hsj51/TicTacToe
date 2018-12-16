#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int playbox[5][5];	// board for storing turns and deciding winner
char showbox[9][18];	// board for display to user
int game_type = 0;	// vs computer or user

void Pause();	// to pause the system and wait for key press
void Clean();	// screen clearing


void SetGround( void );	// makes tic tac toe board
void CheckGround( void );	// developement function to see play ground
void Show( void );	// display the tic tac board
void UpdateShowBox( int row, int column, char update );	// update the board to be displayed to the user
int WinCase();	// select winner
void Menu();	// select game type
void ComputerMove();	// computer's turn
int* GetBestMove( int* best_move );	// calculate best move for a given case ( for computer )

int main() {
	char winner = ' ';
	int i = 1, j = 1, user_num = 1, input;
	SetGround();
	Menu();
	
	while( ( WinCase() == 0 ) && ( WinCase() != -1 ) ) {
		Clean();
		Show();
		
		// computers turn
		if( game_type == 2 && user_num == 2 ) {
			ComputerMove();
			user_num = 1;
			continue;
		}
		
		// twice to eliminate error encountered sometimes
		input = getch();
		if( input == 0 || input == 224 )	input = getch();
		
		switch( input ) {
			case UP:
				if( playbox[i-1][j] != 3 ) {
					// up motion
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, ' ' );
							break;
						case 1:
							UpdateShowBox( i, j, 'x' );
							break;
						case 2:
							UpdateShowBox( i, j, 'o' );
							break;
					}
					i--;
					// change in display
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, '_' );
							break;
						case 1:
							UpdateShowBox( i, j, 'X' );
							break;
						case 2:
							UpdateShowBox( i, j, 'O' );
							break;
					}
				}
				break;
			case DOWN:
				if( playbox[i+1][j] != 3 ) {
					// down motion
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, ' ' );
							break;
						case 1:
							UpdateShowBox( i, j, 'x' );
							break;
						case 2:
							UpdateShowBox( i, j, 'o' );
							break;
					}
					i++;
					// change in display
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, '_' );
							break;
						case 1:
							UpdateShowBox( i, j, 'X' );
							break;
						case 2:
							UpdateShowBox( i, j, 'O' );
							break;
					}
				}
				break;
			case LEFT:
				if( playbox[i][j-1] != 3 ) {
					// left motion
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, ' ' );
							break;
						case 1:
							UpdateShowBox( i, j, 'x' );
							break;
						case 2:
							UpdateShowBox( i, j, 'o' );
							break;
					}
					j--;
					// change in display
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, '_' );
							break;
						case 1:
							UpdateShowBox( i, j, 'X' );
							break;
						case 2:
							UpdateShowBox( i, j, 'O' );
							break;
					}
				}
				break;
			case RIGHT:
				if( playbox[i][j+1] != 3 ) {
					// right motion
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, ' ' );
							break;
						case 1:
							UpdateShowBox( i, j, 'x' );
							break;
						case 2:
							UpdateShowBox( i, j, 'o' );
							break;
					}
					j++;
					// chane in display
					switch( playbox[i][j] ) {
						case 0:
							UpdateShowBox( i, j, '_' );
							break;
						case 1:
							UpdateShowBox( i, j, 'X' );
							break;
						case 2:
							UpdateShowBox( i, j, 'O' );
							break;
					}
				}
				break;
			case ENTER:
				// users turn 
				if( !playbox[i][j] ) {
					if( user_num == 1 ) {
						UpdateShowBox( i, j, 'X' );
						playbox[i][j] = 1;
						user_num = 2;
					}
					else {
						UpdateShowBox( i, j, 'O' );
						playbox[i][j] = 2;
						user_num = 1;
					}
				}
				// entry in invalid place
				else {
					cout << "\n\n[System: Invalid Move! Try that again! Press any key to continue: ]";
					getch();
				}
				break;
			default:
				// invalid key press
				cout << "\n\n[System: Invalid Move! Try that again! Press any key to continue: ]";
				getch();
				break;
		}
	}
	
	Clean();
	Show();
	
	// selecting winner
	switch( WinCase() ) {
		case 1:
			cout << "\n\nPlayer 1 Wins!!";
			break;
		case 2:
			cout << "\n\nPlayer 2 Wins!!";
			break;
		case -1:
			cout << "\n\nIt's a draw!!";
			break;
		case 0:
			cout << "\n\n[System: Error!]";
			exit( 1 );
			break;
	}
	cout << endl << endl << endl;
	Pause();
	return 0;
}

void SetGround() {
	// 5 by 5 to add borders for movement restriction
	for( int i = 0; i < 5; i++ ) {
		for( int j = 0; j < 5; j++ ) {
			if( i == 0 || i == 4 || j == 4 || j == 0 )	playbox[i][j] = 3;
			else	playbox[i][j] = 0;
		}
	}
	strcpy( showbox[0], "     |     |     ");
	strcpy( showbox[1], "     |     |     ");
	strcpy( showbox[2], "_____|_____|_____");
	strcpy( showbox[3], "     |     |     ");
	strcpy( showbox[4], "     |     |     ");
	strcpy( showbox[5], "_____|_____|_____");
	strcpy( showbox[6], "     |     |     ");
	strcpy( showbox[7], "     |     |     ");
	strcpy( showbox[8], "     |     |     ");
	
	UpdateShowBox( 1, 1, '_' );
	return;
}

void CheckGround() {	// developement help
	cout << "playbox:\n";
	for( int i = 0; i < 5; i++ ) {
		for( int j = 0; j < 5; j++ ) {
			cout << playbox[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "showbox:\n";
	for( int i = 0; i < 9; i++ ) {
		cout << showbox[i] << endl;
	}
	return;
}

void Show() {
	cout << "\t\tTIC TAC TOE\n\n";
	for( int i = 0; i < 9; i++ ) {
		cout << "\t\t" << showbox[i] << endl;
	}
	cout << endl;
	cout << "This is a tic Tac Toe game. The current cursor position is shown by _\n";
	cout << "Use one of the folowing keys to move:\n[ X ] Press the Enter Key to Play respective turn\n[ X ] Arrow Keys to Move Position\n";
	return;
}

void UpdateShowBox( int row, int column, char update ) {
	showbox[ 1 + ( row - 1 )*3 ][ 2 + ( column - 1 )*6 ] = update;
	return;
}

int WinCase() {
	int counter = 1;
	
	// row check
	for( int i = 1; i <= 3; i++ ) {
		for( int j = 1; j + 1 <= 3; j++ ) {
			if( playbox[i][j] == playbox[i][j+1] )	counter++;
		}
		if( counter == 3 ) return playbox[i][1];
		else	counter = 1;
	}
	
	counter = 1;
	// column check
	for( int j = 1; j <= 3; j++ ) {
		for( int i = 1; i + 1 <= 3; i++ ) {
			if( playbox[i][j] == playbox[i+1][j] )	counter++;
		}
		if( counter == 3 ) return playbox[1][j];
		else	counter = 1;
	}
	
	// diagonal 1 check
	counter = 1;
	for( int i = 1; i + 1 <= 3; i++ ) {
		if( playbox[i][i] == playbox[i+1][i+1] )	counter++;
	}
	if( counter == 3 )	return playbox[1][1];
	
	// diagonal 2 check
	counter = 1;
	for( int i = 1, j = 3; i + 1 <=3; i++, j-- ) {
		if( playbox[i][j] == playbox[i+1][j-1] )	counter++;
	}
	if( counter == 3 )	return playbox[1][3];
	
	// draw check
	counter = 0;
	for( int i = 1; i <= 3; i++ ) {
		for( int j = 1; j <=3; j++ ) {
			if( playbox[i][j] )	counter++;
		}
	}
	if( counter == 3*3 )	return -1;
	
	return 0;
}

void Menu() {
	cout << "\t\tWelcome to the TicTacToe Game\n\n";
	cout << "Select game type:\n";
	cout << "1: User VS User\n";
	cout << "2: User VS Computer\n";
	cout << "::";
	char selection;
	do {
		selection = getch();
		if( selection == '1' ) {
			game_type = 1;
			break;
		}
		else if( selection == '2' ) {
			game_type = 2;
			break;
		}
	}while( 1 );
	Clean();
	return;
}

void ComputerMove() {
	int best_move[2];
	int* best_move_pointer;
	best_move_pointer = GetBestMove( best_move );
	UpdateShowBox( best_move_pointer[0], best_move_pointer[1], 'O' );
	playbox[best_move_pointer[0]][best_move_pointer[1]] = 2;
	return;
}

int* GetBestMove( int* best_move ) {
	best_move[0] = -1;
	best_move[1] = -1;
	int counter = 0;
	
	// last move check
	for( int player_number = 2; player_number > 0; player_number-- ) {
		// diagonal 1
		for( int i = 1; i <= 3; i++ ) {
			if( playbox[i][i] == player_number )	counter++;
		}
		if( counter == 2 ) {
			counter = 0;
			for( int i = 1; i <= 3; i++ ) {
				if( playbox[i][i] == 0 ) {
					best_move[0] = i;
					best_move[1] = i;
					return best_move;
				}
			}
		}
		counter = 0;
		
		// diagonal 2
		for( int i = 1, j = 3; i <= 3; i++, j-- ) {
			if( playbox[i][j] == player_number )	counter++;
		}
		if( counter == 2 ) {
			counter = 0;
			for( int i = 1, j = 3; i <= 3; i++, j-- ) {
				if( playbox[i][j] == 0 ) {
					best_move[0] = i;
					best_move[1] = j;
					return best_move;
				}
			}
		}
		counter = 0;
		
		// rows
		for( int i = 1; i <= 3; i++ ) {
			for( int j = 1; j <= 3; j++ ) {
				if( playbox[i][j] == player_number )	counter++;
			}
			if( counter == 2 ) {
				counter = 0;
				for( int j = 1; j <= 3; j++ ) {
					if( playbox[i][j] == 0 ) {
						best_move[0] = i;
						best_move[1] = j;
						return best_move;
					}
				}
			}
			counter = 0;
		}
		counter = 0;
		
		// columns
		for( int i = 1; i <= 3; i++ ) {
			for( int j = 1; j <= 3; j++ ) {
				if( playbox[j][i] == player_number )	counter++;
			}
			if( counter == 2 ) {
				counter = 0;
				for( int j = 1; j <= 3; j++ ) {
					if( playbox[j][i] == 0 ) {
						best_move[0] = j;
						best_move[1] = i;
						return best_move;
					}
				}
			}
			counter = 0;
		}
		counter = 0;
	}
	
	// single entry check
	for( int i = 1; i <= 3; i++ ) {
		for( int j = 1; j <= 3; j++ ) {
			if( playbox[i][j] == 1 )	counter++;
		}
	}
	if( counter == 1 ) {
		//corners check
		for( int i = 1; i <= 3; i = i + 2 ) {
			for( int j = 1; j <= 3; j = j + 2 ) {
				if( playbox[i][j] == 1 ) {
					best_move[0] = ( i == 1 ) ? 3 : 1;
					best_move[1] = ( j == 1 ) ? 3 : 1;
					return best_move;
				}
			}
		}
	}
	
	// center check
	if( playbox[1][1] == 0 ) {
		best_move[0] = 1;
		best_move[1] = 1;
		return best_move;
	}
	
	// corners check
	for( int i = 1; i <= 3; i = i + 2 ) {
		for( int j = 1; j <= 3; j = j + 2 ) {
			if( playbox[i][j] == 0 ) {
				best_move[0] = i;
				best_move[1] = j;
				return best_move;
			}
		}
	}
	
	// row and column middle check
	for( int i = 1; i <= 3; i++ ) {
		for( int j = ( i % 2 == 0 ) ? 1 : 2; j <= 3; j = j + 2 ) {
			if( playbox[i][j] == 0 ) {
				best_move[0] = i;
				best_move[1] = j;
				return best_move;
			}
		}
	}
}

void Pause() {
	cout << "Press any key to continue...\n";
	cin.get();
	return;
}

void Clean() {
	// Uncomment according to workstation
	
	// windows terminal
	system( "cls" );
	
	// linux terminal
	//system( "clear" );
	
	// old conio.h
	//clrscr();
	
	// extra lines to scroll the terminal
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 10 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 20 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 30 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 40 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 50 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 60 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 70 lines
	// cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;	// 80 lines
		
}