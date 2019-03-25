/*
 *Chelsea Ip Tze Hwan
 *Program 2 Assignment
 *
 * This program finds the shortest path in the maze, searching from all the possible starting
 * positions to the goal position. Recursively check if N,S,E,W leads to the destination or not.
 * Backtracks if the path doesn't reach destination or we have explored all possible destinations.
 * To make sure the path is kept simple, and doesn't contain any cycles, we keep track of cells
 * involved in current in a matrix and before exploring any cell, we ignore the cell if it is already
 * covered in current path.
 */

#include "robot.h"
#include <cmath>
#include <vector>
using namespace std;

//Robot constructor that receives maxSteps,initial position (x,y) and target destination(x,y)
Robot::Robot(int maxStepsDir, int x, int y, int X, int Y)
{
  this->maxStepsDir = maxStepsDir;
  this->currentX = x;
  this->currentY = y;
  this->targetX = X;
  this->targetY = Y;
  //resets number of paths in all directions
  this->numberOfPaths = 0;
  this->numStepsN = 0;
  this->numStepsS = 0;
  this->numStepsE = 0;
  this->numStepsW = 0;
}

//Destructor
Robot::~Robot() 
{
    //cout<< "The following object has been destroyed: " <<  *this << endl;
}

//Empty constructor
Robot::Robot() 
{
  this->maxStepsDir = 0;
  this->currentX = 0;
  this->currentY = 0;
  this->targetX = 0;
  this->targetY = 0;
  this->numberOfPaths = 0;
  //resets number of paths in all directions
  this->numStepsN = 0;
  this->numStepsS = 0;
  this->numStepsE = 0;
  this->numStepsW = 0;
}


//Function checks to see if the robot is currently in the first
//quadrant, where M and N are input parameters.
bool Robot::isValid(int x, int y, int M, int N) 
{
    if (this->currentX >=0 && this->currentY >= 0)
    {
        cout << "Input parameters are VALID" <<endl;
        return true;
    }
    if(this->targetX >= 0 && this->targetY >= 0) {
        cout << "Input parameters are VALID" <<endl;
        return true;
    }
    cout << "Input parameters are INVALID" <<endl;
    return false;
}

//Checks if (x,y) is blocked in the board
bool Robot::isSafe(Board b, int x, int y) 
{
    if (b.getB(x, y) == -1) 
    {
         cout << "PATH IS BLOCKED" <<endl;
        return false;
    }
    cout << "PATH IS SAFE" <<endl;
    return true;
}


//Checks to see if input parameters are positive, before it calls helper method.
//Resets all steps in every direction to zero before calling the helper function
void Robot::FindPath(Board b)
{

  int stepsAtTime = 0;
  findPathHelper(this->currentX, this->currentY, b, stepsAtTime);
  cout << "Number of paths: " << numberOfPaths << endl;
}

//Checks if destination has been met, prints out path and resets number of steps in all directions.
//stepsAtTime is a local variable that helps to manage (numStepsN, numStepsS, numStepsE and numStepsW)
//If stepsAtTime == to maxStepsDir the it'll call the findPathHelper function to look for other paths
void Robot::findPathHelper(int x, int y, Board b, int stepsAtTime)
{
    if(x == this->targetX && y == this->targetY)
    {
      cout << this->path << endl;
      this->numberOfPaths++;
      this->numStepsN = 0;
      this->numStepsS = 0;
      this->numStepsE = 0;
      this->numStepsW = 0;
    }

    else if(stepsAtTime == maxStepsDir && maxStepsDir != 0)
    {
      findPathHelper(x, y, b, 0);
    }

    else
    {
      if((y - this->targetY) < 0)
      {
        this->path += "N";
        numStepsN++;
        if(b.getB(x, y + 1) == 0)//if (x,y) in board is clear
        {
          findPathHelper(x, y + 1, b, numStepsN);
        }
        this->path.pop_back();//backtracks one position, removes from path
        numStepsN--;
      }

      else if ((y - this->targetY) > 0)
      {
        this->path += "S";
        numStepsS++;
        if(b.getB(x, y - 1) == 0)
        {
          findPathHelper(x, y - 1, b, numStepsS);
        }
        this->path.pop_back();
        numStepsS--;
      }

      if((x - this->targetX) < 0)
      {
        this->path += "E";
        numStepsE++;
        if(b.getB(x + 1, y) == 0)
        {
          findPathHelper(x + 1, y, b, numStepsE);
        }
        this->path.pop_back();
        numStepsE--;
      }

      else if ((x - this->targetX) > 0)
      {
        this->path += "W";
        numStepsW++;
        if(b.getB(x - 1, y) == 0)
        {
          findPathHelper(x - 1, y, b, numStepsW);
        }
        this->path.pop_back();
        numStepsW--;
      }
    }
  }
  

