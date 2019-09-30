#include <iostream>
#include <string.h>

using namespace std;

//functions
void drawBoard();
void clearBoard();
int readInputRow(char in[2]);
int readInputColumn(char in[2]);
void checkWin();
void checkTie();

//variables
char board[3][3];
char input[2];
bool end = false;
char winner;
char oplay = 'O';
char xplay = 'X';
bool xturn = true;

//main
int main() {
  char stillPlaying = 'y';
  int xwins = 0;
  int owins = 0;
  int ties = 0;
  
  //game
  while(stillPlaying == 'y') {
    //reset board
    clearBoard();
    drawBoard();
    while(end == false) {
      //if x turn
      if (xturn) {
        cout << "X Move: " << endl;
        cin >> input;
	bool move = true;
	while (move) {
	  if (board[readInputRow(input)][readInputColumn(input)] == ' ') {
	    board[readInputRow(input)][readInputColumn(input)] = xplay;
	    drawBoard();
	    move = false;
	  } else {
	    cout << "Move not possible. Try again: " << endl;
	    cin >> input;
	    move = true;
	  }
	}
	//switch to O move and check for wins/ties
	xturn = false;
	checkWin();
	checkTie();
	//if O move
      } else {
        cout << "O Move: " << endl;
        cin >> input;
        bool move = true;
	while(move) {
	  if (board[readInputRow(input)][readInputColumn(input)] == ' ') {
	    board[readInputRow(input)][readInputColumn(input)] = oplay;
	    drawBoard();
	    move = false;
	  } else {
	    cout << "Move not possible. Try again: " << endl;
	    cin >> input;
	    move = true;
	  }
	}
	//switch to X move and check for wins/ties
	xturn = true;
	checkWin();
      } 
    }
    //if game is done (board is full)
    if(end == true) {
      //if X won
      if (winner == xplay) {
	xwins++;
	cout << "X won " << xwins << " times!" << endl;
      }
      //if O won
      else if (winner == oplay) {
	owins++;
	cout << "O won " << owins << " times!" << endl;
      }
      //if nobody won (tie)
      else {
	ties++;
	cout << "Tied for the " << ties << " time! Nobody wins." << endl;
      }
    }
    //ask user if they want to play again
    cout << "Still wanna play? y or n: " << endl;
    char i;
    cin >> i;
    bool ask = true;
    while (ask) {
      if(i == 'y') {
	stillPlaying = 'y';
	ask = false;
      } else if (i == 'n') {
	stillPlaying = 'n';
	ask = false;
      }
      //if wrong input (not y or n)
      else {
	cout << "Not a y or a n. Input again: " << endl;
	ask = true;
      }
    }
  }
}

//draw board function
void drawBoard() {
  cout << "  1 2 3" << endl;
  cout << "a ";
  //write a row
  for (int i = 0; i < 3; i++) {
    cout <<  board[i][0] << " ";
  }
  cout << endl;
  cout << "b ";
  //write b row
  for (int i = 0; i < 3; i++) {
    cout << board[i][1] << " ";
  }
  cout << endl;
  cout << "c ";
  //write c row
  for (int i = 0; i < 3; i++) {
    cout << board[i][2] << " ";
  }
  cout << endl;
}

//clear board function
void clearBoard() {
  //set whole board to empty
  for (int column = 0; column < 3; column++) {
    for (int row = 0; row < 3; row++) {
      board[row][column] = ' ';
    }
  }
  //reset win conditions
  winner = ' ';
  end = false;
  xturn = true;
}

//read second char of input (for column position)
int readInputRow(char in[2]) {
  if (in[1] == '1') {
    return 0;
  } else if (in[1] == '2') {
    return 1;
  } else if (in[1] == '3') {
    return 2;
  }
}

//read first char of input (for row position)
int readInputColumn(char in[2]) {
  if (in[0] == 'a') {
    return 0;
  } else if (in[0] == 'b') {
    return 1;
  } else if (in[0] == 'c') {
    return 2;
  }
}

void checkWin() {
  //begin X check wins
  if (board[0][0] == xplay && board[0][1] == xplay && board[0][2] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[1][0] == xplay && board[1][1] == xplay && board[1][2] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[2][0] == xplay && board[2][1] == xplay && board[2][2] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[0][0] == xplay && board[1][0] == xplay && board[2][0] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[0][1] == xplay && board[1][1] == xplay && board[2][1] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[0][2] == xplay && board[1][2] == xplay && board[2][2] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[0][0] == xplay && board[1][1] == xplay && board[2][2] == xplay) {
    end = true;
    winner = xplay;
  } else if (board[0][2] == xplay && board[1][1] == xplay && board[2][0] == xplay) {
    end = true;
    winner = xplay;
  }
  //begin O check wins
  else if (board[0][0] == oplay && board[0][1] == oplay && board[0][2] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[1][0] == oplay && board[1][1] == oplay && board[1][2] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[2][0] == oplay && board[2][1] == oplay && board[2][2] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[0][0] == oplay && board[1][0] == oplay && board[2][0] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[0][1] == oplay && board[1][1] == oplay && board[2][1] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[0][2] == oplay && board[1][2] == oplay && board[2][2] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[0][0] == oplay && board[1][1] == oplay && board[2][2] == oplay) {
    end = true;
    winner = oplay;
  } else if (board[0][2] == oplay && board[1][1] == oplay && board[2][0] == oplay) {
    end = true;
    winner = oplay;
  } else {
    checkTie();
  }
}

//check for tie function
void checkTie() {
  //if whole board is full
  if (end == false && board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' '
       && board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' '
      && board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
    end = true;
    winner = 't';
  }
}
