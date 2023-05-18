/**

*File Name: proj3.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

*Assisted by and Assisted line numbers:


*Your Name: Cory Drangel

*Your PSU user ID:  cjd209

*Course title: CMPSC465 Summer 2022

*Due Time: 11:59 pm, Sunday, June 19, 2022

*Time of Last Modification: 9:51 am, Sunday, June 19, 2022

*Description: Takes in a file that has a number that lists the dimensions of a board that contains X's and O's.
Any group of O's that is surrounded by X's gets converted to an X. If an O or group of O's is not surrounded by an X's on all sides (i.e. an O that lies along an edge), than it stays as an O.

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

void changeLetter(int n, char *board, int i, int j, char oldLetter, char newLetter);

int main() {
  ifstream inFile;    //variable to open the file and take in the data
  int n;              //variable to contain the number of the n X n board

  //opening the file
  inFile.open("input.txt");

  //if statement to ensure the file opens correctly
  if(inFile){
    //assigning the first value in the file to the n
    inFile >> n;
    
    char board[n][n];  //variable for the board
    string str;        //variable for the string of chars in the file
    char c;            //variable to separate the chars of the string
    int x = 0;        //variable that represents the rows of the board

    //while statement for as long as the file has data
    while(inFile >> str){
      //for loop to input the data into the board
      for (int i = 0; i< n; i++){
        c = str.at(i);
        board[x][i] = c;
      }

      //increasing the row count for the next line
      x++;
    }

    //changing all of the O's to an intermediate value I
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(board[i][j] == 'O'){
          board[i][j] = 'I';
        }
      }
    }

    //changing any I along the left edge back to an O
    for(int i = 0; i < n; i++){
      if(board[i][0] == 'I'){
        changeLetter(n, (char *)board, i, 0, 'I', 'O');
      }
    }
    //changing any I along the right edge back to an O
    for(int i = 0; i < n; i++){
      if(board[i][n-1] == 'I'){
        changeLetter(n, (char *)board, i, n-1, 'I', 'O');
      }
    }
    //changing any I along the top edge back an O
    for(int i = 0; i < n; i++){
      if(board[0][i] == 'I'){
        changeLetter(n, (char *)board, 0, i, 'I', 'O');
      }
    }
    //changing any I along the bottom edge back to an O
    for(int i = 0; i < n; i++){
      if(board[n-1][i] == 'I'){
        changeLetter(n, (char *)board, n-1, i, 'I', 'O');
      }
    }

    //changing any remaing I's to an X
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(board[i][j] == 'I'){
          board[i][j] = 'X';
        }
      }
    }

    //displaying the board
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << board[i][j];
      }
      cout << endl;
    }
  }
  else{
    cout << "File did not open properly.";
  }

  inFile.close();
  
}

void changeLetter(int n, char *board, int i, int j, char oldLetter, char newLetter){
  //base case for if the values for i and j are out of bounds
  if (i < 0 || i > n || j < 0 || j > n){
    return;
  }
  //base case for if the value on the board is not equal to the old letter
  //i.e. if you get an X while trying to change the O's, it stops
  if (*((board+i*n) + j) != oldLetter){
    return;
  }

  //changing the value on the board to the new letter
  *((board + i*n) + j) = newLetter;

  //recursive cases for seeing if the adjacent values are the same letter and
  //therefore need to be changed as well
  changeLetter(n, board, i + 1, j, oldLetter, newLetter);
  changeLetter(n, board, i - 1, j, oldLetter, newLetter);
  changeLetter(n, board, i, j + 1, oldLetter, newLetter);
  changeLetter(n, board, i, j - 1, oldLetter, newLetter);
}
