
/*
 Main Board constructor uses a 2-dimensional vector which is simply a vector of vectors.
 Each row is a sub-vector, and elements are added into it by using for loops in the builtGrid
 function. BuiltGrid function loops through the list of integers in the vector,
 and checks to see if it is blocked. If it is, then a '-1' will be pushed onto the row.
 */
#include "board.h"
#include <vector>
using namespace std;

//General constructor
Board::Board() 
{
}

//Destructor
Board::~Board() 
{
    //cout<< "Object is deleted<<endl;
}

//Created a getter function mostly to peek value at x and y, to see if it is -1 or 0.
int Board::getB(int x, int y) 
{
    //cout << " x is = " << x << endl;
    //cout << " y is = " << y << endl;
    return (int) wholeBoard->at(x)->at(y);
}

//Making a vector of vectors, each row is made a vector (sub-vector) and
//pushed into pBoard(the larger vector). Throws an invalid argument, when input parameters
//are entered.
Board::Board(int ROW, int COL, vector<int> boardHolder) 
{
    this->wholeBoard = new vector<vector<int> *>;//building the main vector to store rows and columns
    for (int i = 0; i < ROW; i++) 
    { //creates sub-vector for rows
        vector<int> * rowPointer = new vector<int>; //create a pointer that points to row 
        builtGrid(rowPointer, i, COL, boardHolder);
        wholeBoard->push_back(rowPointer);//adds each row into the main vector
    }
      if(ROW && COL < 0) //error-handling message
      {
            throw invalid_argument("POSITIVE INTEGERS AS INPUT PARAMETERS ONLY");
      }
}

//Traverses through list by 2 elements each to check if it is blocked
void Board::builtGrid(vector<int> * rowPointer, int ROW, int COL, vector<int> boardHolder) 
{
    for (int j = 0; j < COL; j++) //builds columns depending on input parameter
    {
        bool checkblocked = false;
        //checks value of every index in vector, increments 2 each time to check
        for (int k = 0; k < (int) boardHolder.size(); k += 2) 
        {
            if (ROW == boardHolder.at(k) && j == boardHolder.at(k + 1))
                checkblocked = true;
        }
        if (checkblocked) //if blocked, -1 will be displayed on the board
        {
            rowPointer->push_back(-1);
        }
        else 
        {
            rowPointer->push_back(0);
        }
    }
      //throw invalid_argument("POSITIVE INTEGERS AS INPUT PARAMETERS ONLY");
   
}

