

/* Builds one class for the grid*/

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
using namespace std;

//Board Constructor(Size of board, vector of integers)
//Build one class that sets blocked positions on the grid
//Builds one class for the grid

class Board
{
    public: //thinking of how to make the board
        
        Board();
        ~Board();
        int getB(int x, int y);
        Board(int ROW, int COL, vector<int> boardHolder); 
        void builtGrid(vector<int> *p, int ROW, int COL, vector<int> boardHolder);
        //isValid(int x, int y, int X, int Y);
        
private:
 
        vector<vector<int> *>* wholeBoard; //vector container to hold matrix
  


};
#endif
