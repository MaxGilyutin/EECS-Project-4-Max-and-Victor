/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.
Point::Point() {
    x = 0;
    y = 0;
}
    
Point::Point(int xVal, int yVal) {
    // TODO: Implement
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
    return;
}

int Point::getX() {

    return x;
}

void Point::setY(int yVal) {

    y = checkRange(yVal);
    return;
}
    
int Point::getY() {

    return y;
}

void Point::read(istream& ins) {
    char character;
    ins >> character >> x >> character >> y >> character;
    return;
}

void Point::write(ostream& outs) {

    outs << "(" << checkRange(x) << "," << checkRange(y) << ")";
    return;
}

int Point::checkRange(int val) {
    // TODO: Implement
    // FIXME: returning arbitrary value of 0 to avoid compile error
    if (val >= 0 && val < DIMENSION){
        return val;
    }
        else if(val < 0){
            return 0;
        }
        
        else{
            return DIMENSION - 1;
        }
    return 0;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
