//TicTacToe, hardcoded by Stefan Ene, Finished on 9/30/2019
#include <iostream>

using namespace std;

//functions
void drawBoard(char bd[3][3]);
int readInputRow(char in[2]);
int readInputColumn(char in[2]);
char checkWin(char bd[3][3]);
char checkTie(char bd[3][3]);


//main
int main() {
  char board[3][3];
  char input[2];
  char winner;
  bool xturn = true;
  bool end = false;
 
  char stillPlaying = 'y';
  int xwins = 0;
  int owins = 0;
  int ties = 0;

  char xplay = 'X';
  char oplay = 'O';
  
  //game
  while(stillPlaying == 'y') {
    //reset board
    for (int c = 0; c < 3; c++) {
      for (int r = 0; r < 3; r++) {
	board[r][c] = ' ';
      }
    }
    winner = ' ';
    end = false;
    xturn = true;
    drawBoard(board);
    while(end == false) {
      //if x turn
      if (xturn) {
        cout << "X Move: " << endl;
        cin >> input;
	bool move = true;
	while (move) {
	  if (board[readInputRow(input)][readInputColumn(input)] == ' ') {
	    board[readInputRow(input)][readInputColumn(input)] = xplay;
	    drawBoard(board);
	    move = false;
	  } else {
	    cout << "Move not possible. Try again: " << endl;
	    cin >> input;
	    move = true;
	  }
	}
	//switch to O move and check for wins/ties
	xturn = false;
	winner = checkWin(board);
	char wintie = checkTie(board);
	if (winner == xplay || winner == oplay) {
	  end = true;
	}
	if (wintie == 't') {
	  end = true;
	}
	//if O move
      } else {
        cout << "O Move: " << endl;
        cin >> input;
        bool move = true;
	while(move) {
	  if (board[readInputRow(input)][readInputColumn(input)] == ' ') {
	    board[readInputRow(input)][readInputColumn(input)] = oplay;
	    drawBoard(board);
	    move = false;
	  } else {
	    cout << "Move not possible. Try again: " << endl;
	    cin >> input;
	    move = true;
	  }
	}
	//switch to X move and check for wins/ties
	xturn = true;
	winner = checkWin(board);
	char wintie = checkTie(board);
	if (winner == xplay || winner == oplay){
	  end = true;
	}
	if (wintie == 't') {
	  end = true;
	}
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
void drawBoard(char bd[3][3]) {
  cout << "  1 2 3" << endl;
  cout << "a ";
  //write a row
  for (int i = 0; i < 3; i++) {
    cout <<  bd[i][0] << " ";
  }
  cout << endl;
  cout << "b ";
  //write b row
  for (int i = 0; i < 3; i++) {
    cout << bd[i][1] << " ";
  }
  cout << endl;
  cout << "c ";
  //write c row
  for (int i = 0; i < 3; i++) {
    cout << bd[i][2] << " ";
  }
  cout << endl;
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

char checkWin(char bd[3][3]) {
  char xplay = 'X';
  char oplay = 'O';
  //begin X check wins
  if (bd[0][0] == xplay && bd[0][1] == xplay && bd[0][2] == xplay) {
    
    return xplay;
  } else if (bd[1][0] == xplay && bd[1][1] == xplay && bd[1][2] == xplay) {
    
    return xplay;
  } else if (bd[2][0] == xplay && bd[2][1] == xplay && bd[2][2] == xplay) {
    
    return xplay;
  } else if (bd[0][0] == xplay && bd[1][0] == xplay && bd[2][0] == xplay) {
    
    return xplay;
  } else if (bd[0][1] == xplay && bd[1][1] == xplay && bd[2][1] == xplay) {
    
    return xplay;
  } else if (bd[0][2] == xplay && bd[1][2] == xplay && bd[2][2] == xplay) {
    
    return xplay; 
  } else if (bd[0][0] == xplay && bd[1][1] == xplay && bd[2][2] == xplay) {
    
    return xplay; 
  } else if (bd[0][2] == xplay && bd[1][1] == xplay && bd[2][0] == xplay) {
    
    return xplay;
  }
  //begin O check wins
  else if (bd[0][0] == oplay && bd[0][1] == oplay && bd[0][2] == oplay) {
    
    return oplay;
  } else if (bd[1][0] == oplay && bd[1][1] == oplay && bd[1][2] == oplay) {
    
    return oplay;
  } else if (bd[2][0] == oplay && bd[2][1] == oplay && bd[2][2] == oplay) {
    
    return oplay;
  } else if (bd[0][0] == oplay && bd[1][0] == oplay && bd[2][0] == oplay) {
    
    return oplay;
  } else if (bd[0][1] == oplay && bd[1][1] == oplay && bd[2][1] == oplay) {
    
    return oplay;
  } else if (bd[0][2] == oplay && bd[1][2] == oplay && bd[2][2] == oplay) {
    
    return oplay;
  } else if (bd[0][0] == oplay && bd[1][1] == oplay && bd[2][2] == oplay) {
    
    return oplay;
  } else if (bd[0][2] == oplay && bd[1][1] == oplay && bd[2][0] == oplay) {
    
    return oplay;
  } else {
    return ' ';
  }
}

//check for tie function
char checkTie(char bd[3][3]) {
  //if whole board is full
  if (bd[0][0] != ' ' && bd[0][1] != ' ' && bd[0][2] != ' '
       && bd[1][0] != ' ' && bd[1][1] != ' ' && bd[1][2] != ' '
      && bd[2][0] != ' ' && bd[2][1] != ' ' && bd[2][2] != ' ') {
    
    return 't';
  } else {
    return ' ';
  }
}
