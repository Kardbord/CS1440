//
// Created by Stephen Clyde on 2/3/17.
//

#include "TriangleTester.h"

#include <iostream>
#include <cmath>

#include "../Triangle.h"
#include "../Utils.h"

void TriangleTester::testFirstConstructor() {
    std::cout << "Execute TriangleTester::testFirstConstructor with Point**" << std::endl;

    Point **points = new Point *[3];
    points[0] = new Point(1, 2, 8);
    points[1] = new Point(3, 1, 4);
    points[2] = new Point(6, 4, 3);

    Triangle t(points);
    if (!t.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType() != 'S') {
        std::cout << "Triangle: unexpected type of "
                  << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computeArea(), 9.35414, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t.computeArea() << std::endl;
        return;
    }

    const Point *p = t.getPoint(0);
    if (p == nullptr) {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 1 || p->getY() != 2 || p->getZ() != 8) {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p == nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 3 || p->getY() != 1 || p->getZ() != 4) {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p == nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 6 || p->getY() != 4 || p->getZ() != 3) {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testSecondConstructor() {
    std::cout << "Execute TriangleTester::testSecondConstructor with string" << std::endl;

    std::string triangleStr = "1,2,8|3,1,4|6,4,3";

    Triangle t(triangleStr);
    if (!t.isValid()) {
        std::cout << "Failure to construct a triangle from a string; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle()) {
        std::cout << "Failure to constructor a triangle from a string; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType() != 'S') {
        std::cout << "Triangle: unexpected type of "
                  << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computeArea(), 9.35414, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t.computeArea() << std::endl;
        return;
    }

    const Point *p = t.getPoint(0);
    if (p == nullptr) {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 1 || p->getY() != 2 || p->getZ() != 8) {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p == nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 3 || p->getY() != 1 || p->getZ() != 4) {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p == nullptr) {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX() != 6 || p->getY() != 4 || p->getZ() != 3) {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testEquilateralTriangles() {
    std::cout << "Execute TriangleTester::testEquilateralTriangles" << std::endl;

    std::string triangleStr = "-10,0,0|10,0,0|0,17.32050808,0";
    Triangle t1(triangleStr);
    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'E') {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 173.205, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    // TODO: Write additional representative test cases equilateral triangles
}

void TriangleTester::testIsoscelesTriangles() {
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;

    std::string triangleStr = "2,2,0|-1,0,0|2,0,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'I') {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 4.69, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    // TODO: Write additional representative test cases isosceles triangles
}

void TriangleTester::testScaleneTriangles() {
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;

    std::string triangleStr = "2.554,-4.2,0|-1,0,5.3|2,0,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'S') {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 9.595, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    // TODO: Write additional representative test cases scalene triangles
}

void TriangleTester::testNonTriangles() {
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;

    std::string triangleStr = "2,2,2|0,0,0|2,2,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure in constructing Triangle - should be valid" << std::endl;
        return;
    }

    if (t1.isTriangle()) {
        std::cout << "Failure in constructing Triangle; should not be a triangle" << std::endl;
        return;
    }

    // TODO: Write additional representative test cases non-triangles triangles
}

void TriangleTester::testInvalid() {
    std::cout << "Execute TriangleTester::testInvalid" << std::endl;

    Triangle t1(nullptr);
    if (t1.isValid()) {
        std::cout << "Failure in constructing Triangle with nullptr - should be invalid" << std::endl;
    }
    if (t1.isTriangle()) {
        std::cout << "Failure in constructing Triangle with nullptr - should not be a Triangle" << std::endl;
    }

    // TODO: Write additional representative test cases invalid triangles
}
