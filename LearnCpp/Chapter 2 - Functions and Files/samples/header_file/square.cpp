#include "square.h"
 
// actual definition for getSquareSides
int getSquareSides() {
    return 4;
}
 
int getSquarePerimeter(int sideLength) {
    return sideLength * getSquareSides();
}