/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Circle();
    test_Color();
    test_Line();
    test_Rectangle();
    test_Triangle();
    // call other test functions here

    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;

    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "( " << p1.getX()
        << ", " << p1.getY()
        << " )" << endl;

    return;
}

void test_Circle() {
    
    Point z(9, 8);
    Point a(2, 3);
    Color x(255, 0, 0);
    Color y(0, 0, 255);
    Circle c1(z, 4, x);

    cout << "Expected Center (9,8), actual " << c1.getCenter() << endl;
    cout << "Expected Radius 4, actual " << c1.getRadius() << endl;
    cout << "Expected color 255, 0, 0, actual " << c1.getColor() << endl;
    
    c1.setCenter(a);
    cout << "Expected Center (2,3), actual " << c1.getCenter() << endl;

    c1.setColor(y);
    cout << "Expected color 0, 0, 255, actual " << c1.getColor() << endl;
    
    c1.setRadius(27);
    cout << "Expected Radius 27, actual " << c1.getRadius() << endl;
}

void test_Color() {
    Color c(0,0,255);
    
    cout << "Expected value for blue is 255, actual: " << c.getBlue() << endl;

    cout << "Expected value for green is 0, actual: " << c.getGreen() << endl;

    c.setBlue(55);
    cout << "Expected value for blue is 55, actual: " << c.getBlue() << endl;

    c.setGreen(10000);
    cout << "Expected value for green is 255, actual: " << c.getGreen() << endl;
}

void test_Line() {
    
    Point a(2, 5);
    Point b(5, 10);
    Point c(7, 6);

    Color x(0, 0, 255);

    Line l(a, b, x);

    cout << "Expected Start (2,5), actual " << l.getStart() << endl;
    cout << "Expected End (5,10), actual " << l.getEnd() << endl;
    cout << "Expected color 0, 0, 255, actual " << l.getColor() << endl;

    l.setEnd(c);
    cout << "Expected End (7,6), actual " << l.getEnd() << endl;

    ofstream file;

    file.open("data1");

    file << l.getStart() << l.getEnd() << l.getColor();
        
}

void test_Rectangle() {
   
    Point p1(27, 36);
    Point p2(88, 72);
    Point p3(20, 30);
    Color a(255, 0, 0);
    Color b(0, 255, 0);
    Color c(0, 0, 255);
    Color d(37, 45, 0);
    Rectangle r1(p1, p2, a);
    Rectangle r2(p1, p2, a, b, c, d);
    
    cout << "Expected Start (27,36), actual " << r1.getStart() << endl;
    cout << "Expected End (88,72), actual " << r1.getEnd() << endl;
    cout << "Expected Start (27,36), actual " << r2.getStart() << endl;
    cout << "Expected End (88,72), actual " << r2.getEnd() << endl;
    cout << "Expected color 255, 0, 0, actual " << r1.getColorTopLeft() << endl;
    cout << "Expected color 255, 0, 0, actual " << r1.getColorTopRight() << endl;
    cout << "Expected color 255, 0, 0, actual " << r1.getColorBottomLeft() << endl;
    cout << "Expected color 255, 0, 0, actual " << r1.getColorBottomRight() << endl;
    cout << "Expected color 255, 0, 0, actual " << r2.getColorTopLeft() << endl;
    cout << "Expected color 0, 255, 0, actual " << r2.getColorTopRight() << endl;
    cout << "Expected color 0, 0, 255, actual " << r2.getColorBottomLeft() << endl;
    cout << "Expected color 37, 45, 0, actual " << r2.getColorBottomRight() << endl;

    r1.setColor(d);
    cout << "Expected color 37, 45, 0, actual " << r1.getColorTopLeft() << endl;
    cout << "Expected color 37, 45, 0, actual " << r1.getColorTopRight() << endl;
    cout << "Expected color 37, 45, 0, actual " << r1.getColorBottomLeft() << endl;
    cout << "Expected color 37, 45, 0, actual " << r1.getColorBottomRight() << endl;

    r1.setStart(p3);
    cout << "Expected Start (20,30), actual " << r1.getStart() << endl;
}

void test_Triangle() {
    Point p1(27, 3);
    Point p2(50, 80);
    Point p3(32, 60);
    Point p4(20, 9);
    Point p5(42, 80);
    Point p6(36, 92);
    Color c1(0, 0, 255);
    Color c2(255, 0, 0);
    Color c3(0, 255, 0);

    Triangle t1(p1, p2, p3, c1);
    Triangle t2 (p1, c1, p2, c2, p3, c3);

    cout << "Expected value for VertexOne (27, 3), actual: " << t1.getVertexOne() << endl;
    cout << "Expected value for VertexTwo (50, 80), actual: " << t1.getVertexTwo() << endl;
    cout << "Expected value for VertexThree (32, 60), actual: " << t1.getVertexThree() << endl;
    cout << "Expected value for VertexOne (27, 3), actual: " << t2.getVertexOne() << endl;
    cout << "Expected value for VertexTwo (50, 80), actual: " << t2.getVertexTwo() << endl;
    cout << "Expected value for VertexThree (32, 60), actual: " << t2.getVertexThree() << endl;
   
    cout << "Expected color 0, 0, 255, actual: " << t1.getVertexOneColor() << endl;
    cout << "Expected color 255, 0, 0, actual: " << t1.getVertexTwoColor() << endl;
    cout << "Expected color 0, 255, 0, actual: " << t1.getVertexThreeColor() << endl;
    cout << "Expected color 0, 0, 255, actual: " << t2.getVertexOneColor() << endl;
    cout << "Expected color 255, 0, 0, actual: " << t2.getVertexTwoColor() << endl;
    cout << "Expected color 0, 255, 0, actual: " << t2.getVertexThreeColor() << endl;

    t1.setVertexOne(p4);
    t1.setVertexTwo(p5);
    t1.setVertexThree(p6);
    cout << "Expected value for VertexOne (20, 9), actual: " << t1.getVertexOne() << endl;
    cout << "Expected value for VertexOne (42, 80), actual: " << t1.getVertexTwo() << endl;
    cout << "Expected value for VertexOne (36, 92), actual: " << t1.getVertexThree() << endl;

    ofstream file;

    file.open("data1");

    file << t1.getVertexOne() << t1.getVertexOneColor() << t1.getVertexTwo()
        << t2.getVertexTwoColor() << t1.getVertexThree() << t1.getVertexThreeColor();

}
