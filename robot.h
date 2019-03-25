/*
 * File:   robot.h
 *
 * Created on 29 January 2019, 12:57
 */

#ifndef ROBOT_H
#define ROBOT_H
#include "board.h"
#include <vector>
#include <iostream>
using namespace std;

class Robot
{
    public:

      Robot(); //Make a point at (0,0)
      Robot(int maxSteps, int x, int y, int X, int Y);
      ~Robot(); //destructor                                                                                                                                                             int y, int M, int N); //Make a point at (x,y)
      
      bool isValid(int x, int y, int X, int Y);
      bool isSafe(Board b, int x, int y);

      void FindPath(Board b);
      void findPathHelper(int x, int y, Board b, int stepsAtTime);
    

    private:
      string path;
      Board b;
      int numberOfPaths;
      int numStepsN;
      int numStepsS;
      int numStepsE;
      int numStepsW;
      int maxStepsDir;//max no. of steps
      int currentX;//start position row
      int currentY;//start ppsition column
      int targetX;//goal destination row
      int targetY;//goal destination column
};


#endif /* ROBOT_H */
