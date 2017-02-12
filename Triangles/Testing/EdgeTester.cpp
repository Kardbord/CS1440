//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01() {
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0, 0, 0);
    Point p1(1, 0, 0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2() != &p1) {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength() != 1) {
        std::cout << "Failure in e.getLength(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX() != INFINITY) {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY() != 0) {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ() != 0) {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02() {
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1, 0, 0);
    Point p1(3, 4, 5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2() != &p1) {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001) {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001) {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001) {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001) {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges() {
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;

    // Integer points with positive slope tests:

    Point p0(0, 0, 0);
    Point p1(1, 1, 1);
    Edge e1(&p0, &p1);

    Point p2(4, 4, 4);
    Point p3(5, 5, 5);
    Edge e2(&p2, &p3);

    Point p4(0, 0, 0);
    Point p5(-1, -1, -1);
    Edge e3(&p4, &p5);

    Point p6(-4, -4, -4);
    Point p7(-5, -5, -5);
    Edge e4(&p6, &p7);

    Point p8(1, 0, 0);
    Point p9(2, 1, 1);
    Edge e5(&p8, &p9);

    if (!e1.isParallelTo(e2)) {
        std::cout << "Failure in e1.isParallelTo(e2) - should be parallel" << std::endl;
    }

    if (!e3.isParallelTo(e4)) {
        std::cout << "Failure in e3.isParallelTo(e4) - should be parallel" << std::endl;
    }

    if (!e1.isParallelTo(e3)) {
        std::cout << "Failure in e1.isParallelTo(e3) - should be parallel" << std::endl;
    }

    if (!e1.isParallelTo(e4)) {
        std::cout << "Failure in e1.isParallelTo(e4) - should be parallel" << std::endl;
    }

    if (!e2.isParallelTo(e3)) {
        std::cout << "Failure in e2.isParallelTo(e3) - should be parallel" << std::endl;
    }

    if (!e2.isParallelTo(e4)) {
        std::cout << "Failure in e2.isParallelTo(e4) - should be parallel" << std::endl;
    }

    if (!e1.isParallelTo(e1)) {
        std::cout << "Failure in e1.isParallelTo(e1) - should be parallel" << std::endl;
    }

    if (!e2.isParallelTo(e2)) {
        std::cout << "Failure in e2.isParallelTo(e2) - should be parallel" << std::endl;
    }

    if (!e3.isParallelTo(e3)) {
        std::cout << "Failure in e3.isParallelTo(e3) - should be parallel" << std::endl;
    }

    if (!e4.isParallelTo(e4)) {
        std::cout << "Failure in e4.isParallelTo(e4) - should be parallel" << std::endl;
    }

    if (!e5.isParallelTo(e1)) {
        std::cout << "Failure in e5.isParallelTo(e1) - should be parallel" << std::endl;
    }

    if (!e5.isParallelTo(e2)) {
        std::cout << "Failure in e5.isParallelTo(e2) - should be parallel" << std::endl;
    }

    if (!e5.isParallelTo(e3)) {
        std::cout << "Failure in e5.isParallelTo(e3) - should be parallel" << std::endl;
    }

    if (!e5.isParallelTo(e4)) {
        std::cout << "Failure in e5.isParallelTo(e4) - should be parallel" << std::endl;
    }

    if (!e5.isParallelTo(e5)) {
        std::cout << "Failure in e5.isParallelTo(e5) - should be parallel" << std::endl;
    }

    // Integer Points with negative slope tests

    Point p10(0, 0, 0);
    Point p11(-1, -1, 1);
    Edge e6(&p10, &p11);

    Point p12(5, 5, 5);
    Point p13(4, 4, 6);
    Edge e7(&p12, &p13);

    Point p14(1, 0, 0);
    Point p15(0, -1, 1);
    Edge e8(&p14, &p15);

    if (!e6.isParallelTo(e7)){
        std::cout << "Failure in e6.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e6)){
        std::cout << "Failure in e8.isParallelTo(e6) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e7)){
        std::cout << "Failure in e8.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e6.isParallelTo(e6)){
        std::cout << "Failure in e6.isParallelTo(e6) - should be parallel" << std::endl;
    }

    if (!e7.isParallelTo(e7)){
        std::cout << "Failure in e7.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e8)){
        std::cout << "Failure in e8.isParallelTo(e8) - should be parallel" << std::endl;
    }

    // TODO: Writing a representative set of test cases for edges that are parallel with other
    // TODO: test non-integers
}

void EdgeTester::testNonParallelEdges() {
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges that are not parallel with other
}

void EdgeTester::testNonLengthEdges() {
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges have a length of zero or approximately zero
}

void EdgeTester::testBadEdges() {
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges not formed correctly
}
