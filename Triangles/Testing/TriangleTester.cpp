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
        std::cout << "Failure to constructor t1 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor t1 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'E') {
        std::cout << "Triangle t1: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 173.205, 0.001)) {
        std::cout << "Triangle t1: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    triangleStr = "10,0,0|-10,0,0|0,17.32050808,0";
    Triangle t2(triangleStr);
    if (!t2.isValid()) {
        std::cout << "Failure to constructor t2 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle()) {
        std::cout << "Failure to constructor t2 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType() != 'E') {
        std::cout << "Triangle t2: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computeArea(), 173.205, 0.001)) {
        std::cout << "Triangle t2: unexpected area of "
                  << t2.computeArea() << std::endl;
        return;
    }

    triangleStr = "10,0,0|-10,0,0|0,-17.32050808,0";
    Triangle t3(triangleStr);
    if (!t3.isValid()) {
        std::cout << "Failure to constructor t3 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t3.isTriangle()) {
        std::cout << "Failure to constructor t3 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t3.getTriangleType() != 'E') {
        std::cout << "Triangle: unexpected type of "
                  << t3.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t3.computeArea(), 173.205, 0.001)) {
        std::cout << "Triangle: unexpected area of "
                  << t3.computeArea() << std::endl;
        return;
    }
}

void TriangleTester::testIsoscelesTriangles() {
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;

    std::string triangleStr = "2,2,0|-1,0,0|2,0,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle t1 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle t1 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'I') {
        std::cout << "Triangle t1: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 4.69, 0.001)) {
        std::cout << "Triangle t1: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    triangleStr = "-2,2,0|1,0,0|-2,0,2";
    Triangle t2(triangleStr);

    if (!t2.isValid()) {
        std::cout << "Failure to constructor a triangle t2 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle()) {
        std::cout << "Failure to constructor a triangle t2 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType() != 'I') {
        std::cout << "Triangle t2: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computeArea(), 4.69, 0.001)) {
        std::cout << "Triangle t2: unexpected area of "
                  << t2.computeArea() << std::endl;
        return;
    }
}

void TriangleTester::testScaleneTriangles() {
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;

    std::string triangleStr = "2.554,-4.2,0|-1,0,5.3|2,0,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure to constructor a triangle t1 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle()) {
        std::cout << "Failure to constructor a triangle t1 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType() != 'S') {
        std::cout << "Triangle t1: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computeArea(), 9.595, 0.001)) {
        std::cout << "Triangle t1: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    triangleStr = "-2.554,-4.2,0|1,0,5.3|-2,0,2";
    Triangle t2(triangleStr);

    if (!t2.isValid()) {
        std::cout << "Failure to constructor a triangle t2 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle()) {
        std::cout << "Failure to constructor a triangle t2 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType() != 'S') {
        std::cout << "Triangle t2: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computeArea(), 9.595, 0.001)) {
        std::cout << "Triangle t2: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }

    triangleStr = "-2.554,4.2,0|1,0,5.3|-2,0,2";
    Triangle t3(triangleStr);

    if (!t3.isValid()) {
        std::cout << "Failure to constructor a triangle t3 from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t3.isTriangle()) {
        std::cout << "Failure to constructor a triangle t3 from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t3.getTriangleType() != 'S') {
        std::cout << "Triangle t3: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t3.computeArea(), 9.595, 0.001)) {
        std::cout << "Triangle t3: unexpected area of "
                  << t1.computeArea() << std::endl;
        return;
    }
}

void TriangleTester::testNonTriangles() {
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;

    std::string triangleStr = "2,2,2|0,0,0|2,2,2";
    Triangle t1(triangleStr);

    if (!t1.isValid()) {
        std::cout << "Failure in constructing Triangle t1 - should be valid" << std::endl;
        return;
    }

    if (t1.isTriangle()) {
        std::cout << "Failure in constructing Triangle t1; should not be a triangle" << std::endl;
        return;
    }

    triangleStr = "2,2,2|2,2,2|2,2,2";
    Triangle t2(triangleStr);

    if (!t2.isValid()) {
        std::cout << "Failure in constructing Triangle t2 - should be valid" << std::endl;
        return;
    }

    if (t2.isTriangle()) {
        std::cout << "Failure in constructing Triangle t2; should not be a triangle" << std::endl;
        return;
    }

    triangleStr = "0,0,0|1,0,0|2,0,0";
    Triangle t3(triangleStr);

    if (!t3.isValid()) {
        std::cout << "Failure in constructing Triangle t3 - should be valid" << std::endl;
        return;
    }

    if (t3.isTriangle()) {
        std::cout << "Failure in constructing Triangle t3; should not be a triangle" << std::endl;
        return;
    }
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

    std::string triangleStr = "nullptr|-6,1,2|0,0,0";
    Triangle t2(triangleStr);

    if (t2.isValid()) {
        std::cout << "Failure in constructing Triangle t2 with bad string - should be invalid" << std::endl;
    }
    if (t2.isTriangle()) {
        std::cout << "Failure in constructing Triangle t2 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "INFINITY,0,0|1,1,1|2,2,5";
    Triangle t3(triangleStr);

    if (t3.isValid()) {
        std::cout << "Failure in constructing Triangle t3 with bad string - should be invalid" << std::endl;
    }
    if (t3.isTriangle()) {
        std::cout << "Failure in constructing Triangle t3 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "INFINITY|1,1,1|2,2,5";
    Triangle t4(triangleStr);

    if (t4.isValid()) {
        std::cout << "Failure in constructing Triangle t4 with bad string - should be invalid" << std::endl;
    }
    if (t4.isTriangle()) {
        std::cout << "Failure in constructing Triangle t4 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "NAN,0,0|1,1,1|2,2,5";
    Triangle t5(triangleStr);

    if (t5.isValid()) {
        std::cout << "Failure in constructing Triangle t5 with bad string - should be invalid" << std::endl;
    }
    if (t5.isTriangle()) {
        std::cout << "Failure in constructing Triangle t5 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "NAN|1,1,1|2,2,5";
    Triangle t6(triangleStr);

    if (t6.isValid()) {
        std::cout << "Failure in constructing Triangle t6 with bad string - should be invalid" << std::endl;
    }
    if (t6.isTriangle()) {
        std::cout << "Failure in constructing Triangle t6 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "badString";
    Triangle t7(triangleStr);

    if (t7.isValid()) {
        std::cout << "Failure in constructing Triangle t7 with bad string - should be invalid" << std::endl;
    }
    if (t7.isTriangle()) {
        std::cout << "Failure in constructing Triangle t7 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "badString|badstring|badStrINg";
    Triangle t8(triangleStr);

    if (t8.isValid()) {
        std::cout << "Failure in constructing Triangle t8 with bad string - should be invalid" << std::endl;
    }
    if (t8.isTriangle()) {
        std::cout << "Failure in constructing Triangle t8 with bad string - should not be a Triangle" << std::endl;
    }

    triangleStr = "a,b,c|d,e,f|g,h,i";
    Triangle t9(triangleStr);

    if (t9.isValid()) {
        std::cout << "Failure in constructing Triangle t9 with letter string - should be invalid" << std::endl;
    }
    if (t9.isTriangle()) {
        std::cout << "Failure in constructing Triangle t9 with letter string - should not be a Triangle" << std::endl;
    }


    // TODO: Write additional representative test cases invalid triangles
}
