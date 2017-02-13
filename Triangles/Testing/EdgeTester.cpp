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

    // Integer Points with negative slope tests:

    Point p10(0, 0, 0);
    Point p11(-1, -1, 1);
    Edge e6(&p10, &p11);

    Point p12(5, 5, 5);
    Point p13(4, 4, 6);
    Edge e7(&p12, &p13);

    Point p14(1, 0, 0);
    Point p15(0, -1, 1);
    Edge e8(&p14, &p15);

    if (!e6.isParallelTo(e7)) {
        std::cout << "Failure in e6.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e6)) {
        std::cout << "Failure in e8.isParallelTo(e6) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e7)) {
        std::cout << "Failure in e8.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e6.isParallelTo(e6)) {
        std::cout << "Failure in e6.isParallelTo(e6) - should be parallel" << std::endl;
    }

    if (!e7.isParallelTo(e7)) {
        std::cout << "Failure in e7.isParallelTo(e7) - should be parallel" << std::endl;
    }

    if (!e8.isParallelTo(e8)) {
        std::cout << "Failure in e8.isParallelTo(e8) - should be parallel" << std::endl;
    }

    // Non-integer Points with positive and negative slope tests:

    Point p16(1.84, 1.84, 1.84);
    Point p17(2.84, 2.84, 2.84);
    Edge e9(&p16, &p17);

    Point p18(2.84, 1.84, 1.84);
    Point p19(3.84, 2.84, 2.84);
    Edge e10(&p18, &p19);

    Point p20(4.84, 4.84, 4.84);
    Point p21(5.84, 5.84, 5.84);
    Edge e11(&p21, &p20);

    if (!e9.isParallelTo(e9)) {
        std::cout << "Failure in e9.isParallelTo(e9) - should be parallel" << std::endl;
    }

    if (!e10.isParallelTo(e10)) {
        std::cout << "Failure in e10.isParallelTo(e10) - should be parallel" << std::endl;
    }

    if (!e11.isParallelTo(e11)) {
        std::cout << "Failure in e11.isParallelTo(e11) - should be parallel" << std::endl;
    }

    if (!e9.isParallelTo(e10)) {
        std::cout << "Failure in e9.isParallelTo(e10) - should be parallel" << std::endl;
    }

    if (!e9.isParallelTo(e11)) {
        std::cout << "Failure in e9.isParallelTo(e11) - should be parallel" << std::endl;
    }

    if (!e10.isParallelTo(e11)) {
        std::cout << "Failure in e8.isParallelTo(e8) - should be parallel" << std::endl;
    }

    Point p22(1.84, 1.84, 1.84);
    Point p23(0.84, 0.84, 2.84);
    Edge e12(&p22, &p23);

    Point p24(2.84, 1.84, 1.84);
    Point p25(1.84, 0.84, 2.84);
    Edge e13(&p24, &p25);

    Point p26(4.84, 4.84, 4.84);
    Point p27(3.84, 3.84, 5.84);
    Edge e14(&p26, &p27);

    if (!e12.isParallelTo(e12)) {
        std::cout << "Failure in e12.isParallelTo(e12) - should be parallel" << std::endl;
    }

    if (!e13.isParallelTo(e13)) {
        std::cout << "Failure in e13.isParallelTo(e13) - should be parallel" << std::endl;
    }

    if (!e14.isParallelTo(e14)) {
        std::cout << "Failure in e14.isParallelTo(e14) - should be parallel" << std::endl;
    }

    if (!e12.isParallelTo(e13)) {
        std::cout << "Failure in e12.isParallelTo(e13) - should be parallel" << std::endl;
    }

    if (!e12.isParallelTo(e14)) {
        std::cout << "Failure in e12.isParallelTo(e14) - should be parallel" << std::endl;
    }

    if (!e13.isParallelTo(e14)) {
        std::cout << "Failure in e13.isParallelTo(e14) - should be parallel" << std::endl;
    }

    // Edges with infinite or undefined slopes

    Point p28(0, 1, 0);
    Point p29(0, 0, 0);
    Edge e15(&p28, &p29);

    Point p30(0, 3, 0);
    Point p31(0, 2, 0);
    Edge e16(&p30, &p31);

    if (!e15.isParallelTo(e15)) {
        std::cout << "Failure in e15.isParallelTo(e15) - should be parallel" << std::endl;
    }

    if (!e16.isParallelTo(e16)) {
        std::cout << "Failure in e16.isParallelTo(e16) - should be parallel" << std::endl;
    }

    if (!e15.isParallelTo(e16)) {
        std::cout << "Failure in e15.isParallelTo(e16) - should be parallel" << std::endl;
    }

    Point p32(1, 0, 0);
    Point p33(0, 0, 0);
    Edge e17(&p32, &p33);

    Point p34(5, 1, 0);
    Point p35(20, 1, 0);
    Edge e18(&p34, &p35);

    if (!e17.isParallelTo(e17)) {
        std::cout << "Failure in e17.isParallelTo(e17) - should be parallel" << std::endl;
    }

    if (!e18.isParallelTo(e18)) {
        std::cout << "Failure in e18.isParallelTo(e18) - should be parallel" << std::endl;
    }

    if (!e17.isParallelTo(e18)) {
        std::cout << "Failure in e17.isParallelTo(e18) - should be parallel" << std::endl;
    }

    Point p36(0, 0, 1);
    Point p37(0, 0, 0);
    Edge e19(&p36, &p37);

    Point p38(0, 1, 5);
    Point p39(0, 1, 20);
    Edge e20(&p38, &p39);

    if (!e19.isParallelTo(e19)) {
        std::cout << "Failure in e19.isParallelTo(e19) - should be parallel" << std::endl;
    }

    if (!e20.isParallelTo(e20)) {
        std::cout << "Failure in e20.isParallelTo(e20) - should be parallel" << std::endl;
    }

    if (!e19.isParallelTo(e20)) {
        std::cout << "Failure in e19.isParallelTo(e20) - should be parallel" << std::endl;
    }
}

void EdgeTester::testNonParallelEdges() {
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;

    Point p0(0, 0, 0);
    Point p1(2, 3, 4);
    Edge e1(&p0, &p1);

    Point p2(0, 0, 0);
    Point p3(-1, 5, 6);
    Edge e2(&p2, &p3);

    Point p4(0, 0, 0);
    Point p5(-1, -1, 1);
    Edge e3(&p4, &p5);

    Point p6(-1.84, -1.84, 2);
    Point p7(1, 3.0, 4.524);
    Edge e4(&p6, &p7);

    if (e1.isParallelTo(e2)) {
        std::cout << "Failure in e1.isParallelTo(e2) - should not be parallel" << std::endl;
    }

    if (e1.isParallelTo(e3)) {
        std::cout << "Failure in e1.isParallelTo(e3) - should not be parallel" << std::endl;
    }

    if (e1.isParallelTo(e4)) {
        std::cout << "Failure in e1.isParallelTo(e4) - should not be parallel" << std::endl;
    }

    if (e2.isParallelTo(e3)) {
        std::cout << "Failure in e2isParallelTo(e3) - should not be parallel" << std::endl;
    }

    if (e2.isParallelTo(e4)) {
        std::cout << "Failure in e2.isParallelTo(e4) - should not be parallel" << std::endl;
    }

    if (e3.isParallelTo(e4)) {
        std::cout << "Failure in e3.isParallelTo(e4) - should not be parallel" << std::endl;
    }
}

void EdgeTester::testNonLengthEdges() {
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;

    Point p0(0, 0, 0);
    Point p1(0, 0, 0);
    Edge e1(&p0, &p1);

    if (e1.getLength() != 0) {
        std::cout << "Failure in e1.getLength()=" << e1.getLength()
                  << "\n- should be 0" << std::endl;
    }

    Point p2(0, 0, 0);
    Point p3(0.01, 0, 0);
    Edge e2(&p2, &p3);

    if (e2.getLength() != 0.01) {
        std::cout << "Failure in e2.getLength()=" << e2.getLength()
                  << "\n- should be 0.01" << std::endl;
    }

    Point p4(0, 0, 0);
    Point p5(0.001, 0, 0);
    Edge e3(&p4, &p5);

    if (e3.getLength() != 0.001) {
        std::cout << "Failure in e3.getLength()=" << e3.getLength()
                  << "\n- should be 0.001" << std::endl;
    }

    Point p6(0.0001, 0, 0);
    Point p7(0, 0, 0);
    Edge e4(&p6, &p7);

    if (e4.getLength() != 0.0001) {
        std::cout << "Failure in e4.getLength()=" << e4.getLength()
                  << "\n- should be 0.0001" << std::endl;
    }

    if (!e4.isParallelTo(e4)) {
        std::cout << "Failure in e4.isParallelTo(e4)=" << e2.isParallelTo(e4) << " Should be 1\n";
    }

    if (!e2.isParallelTo(e2)) {
        std::cout << "Failure in e2.isParallelTo(e2)=" << e2.isParallelTo(e2) << " Should be 1\n";
    }

    if (!e3.isParallelTo(e3)) {
        std::cout << "Failure in e3.isParallelTo(e3)=" << e3.isParallelTo(e3) << " Should be 1\n";
    }

    if (!e1.isParallelTo(e1)) {
        std::cout << "Failure in e1.isParallelTo(e1)=" << e1.isParallelTo(e1) << " Should be 1\n";
    }

    if (!e2.isParallelTo(e3)) {
        std::cout << "Failure in e2.isParallelTo(e3)=" << e2.isParallelTo(e3) << " Should be 1\n";
    }

    if (!e2.isParallelTo(e4)) {
        std::cout << "Failure in e2.isParallelTo(e4)=" << e2.isParallelTo(e4) << " Should be 1\n";
    }

    if (!e3.isParallelTo(e4)) {
        std::cout << "Failure in e2.isParallelTo(e2)=" << e3.isParallelTo(e4) << " Should be 1\n";
    }
}

void EdgeTester::testBadEdges() {
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges not formed correctly
}
