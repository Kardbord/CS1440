//
// Created by Stephen Clyde on 2/3/17.
//

#include <iostream>
#include <cmath>

#include "../Point.h"
#include "PointTester.h"

void PointTester::testConstructorWithDoubles() {
    std::cout << "Execute PointTester::testConstructorWithDoubles" << std::endl;

    // Test 1st constructor by building 4 points
    Point p0(0, 0, 0);
    if (!p0.isValid() || p0.getX() != 0 || p0.getY() != 0 || p0.getZ() != 0) {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p0.isValid()
                  << " x=" << p0.getX()
                  << " y=" << p0.getY()
                  << " z=" << p0.getZ()
                  << std::endl;
        return;
    }

    Point p1(1, 2, 3);
    if (!p1.isValid() || p1.getX() != 1 || p1.getY() != 2 || p1.getZ() != 3) {
        std::cout << "Failure in constructing Point(1,2,3) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p2(2.235, 43.2, 0);
    if (!p2.isValid() || p2.getX() != 2.235 || p2.getY() != 43.2 || p2.getZ() != 0) {
        std::cout << "Failure in constructing Point(2.235,43.2,0) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p3(2.235, 43.2, 0.00001);
    if (!p3.isValid() || p3.getX() != 2.235 || p3.getY() != 43.2 || p3.getZ() != 0.00001) {
        std::cout << "Failure in constructing Point(2.235,43.2,0.00001) isValid()="
                  << p3.isValid()
                  << " x=" << p3.getX()
                  << " y=" << p3.getY()
                  << " z=" << p3.getZ()
                  << std::endl;
        return;
    }

}

void PointTester::testIsEquivalentTo() {
    std::cout << "Execute PointTester::testIsEquivalentTo" << std::endl;

    Point p0(0, 0, 0);
    Point p1(1, 2, 3);
    Point p2(2.235, 43.2, 0);
    Point p3(2.235, 43.2, 0.00001);

    // Test the equality of p0 with all four points
    if (!p0.isEquivalentTo(p0)) {
        std::cout << "Failure in comparing p0 and p0 -- should be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p1)) {
        std::cout << "Failure in comparing p0 and p1 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p2)) {
        std::cout << "Failure in comparing p0 and p2 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p3)) {
        std::cout << "Failure in comparing p0 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p1 with all four points
    if (p1.isEquivalentTo(p0)) {
        std::cout << "Failure in comparing p1 and p0 -- should not be equal" << std::endl;
    }

    if (!p1.isEquivalentTo(p1)) {
        std::cout << "Failure in comparing p1 and p1 -- should be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p2)) {
        std::cout << "Failure in comparing p1 and p2 -- should not be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p3)) {
        std::cout << "Failure in comparing p1 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p2 with all four points
    if (p2.isEquivalentTo(p0)) {
        std::cout << "Failure in comparing p2 and p0 -- should not be equal" << std::endl;
    }

    if (p2.isEquivalentTo(p1)) {
        std::cout << "Failure in comparing p2 and p1 -- should not be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p2)) {
        std::cout << "Failure in comparing p2 and p2 -- should be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p3)) {
        std::cout << "Failure in comparing p2 and p3 -- should be equal" << std::endl;
    }

    // Test the equality of p3 with all four points
    if (p3.isEquivalentTo(p0)) {
        std::cout << "Failure in comparing p3 and p0 -- should not be equal" << std::endl;
    }

    if (p3.isEquivalentTo(p1)) {
        std::cout << "Failure in comparing p3 and p1 -- should not be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p2)) {
        std::cout << "Failure in comparing p3 and p2 -- should be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p3)) {
        std::cout << "Failure in comparing p3 and p3 -- should be equal" << std::endl;
    }

}

void PointTester::testConstructorWithStrings() {
    std::cout << "Execute PointTester::testConstructorWithStrings" << std::endl;

    Point p0(0, 0, 0);
    Point p1(1, 2, 3);
    Point p2(2.235, 43.2, 0);
    Point p3(2.235, 43.2, 0.00001);

    // Test second constructor by creating for new points that should be the same as the previous four
    Point q0("0,0,0");
    if (!q0.isValid() || !q0.isEquivalentTo(p0)) {
        std::cout << "Failure in constructing Point(\"0,0,0\") isValid()="
                  << q0.isValid()
                  << " x=" << q0.getX()
                  << " y=" << q0.getY()
                  << " z=" << q0.getZ()
                  << std::endl;
    }

    Point q1("1,2,3");
    if (!q1.isValid() || !q1.isEquivalentTo(p1)) {
        std::cout << "Failure in constructing Point(\"1,2,3\") isValid()="
                  << q1.isValid()
                  << " x=" << q1.getX()
                  << " y=" << q1.getY()
                  << " z=" << q1.getZ()
                  << std::endl;
    }

    Point q2("2.235,43.2,0");
    if (!q2.isValid() || !q2.isEquivalentTo(p2)) {
        std::cout << "Failure in constructing Point(\"2.235,43.2,0\") isValid()="
                  << q2.isValid()
                  << " x=" << q2.getX()
                  << " y=" << q2.getY()
                  << " z=" << q2.getZ()
                  << std::endl;
    }

    Point q3("2.235,43.2,0.00001");
    if (!q3.isValid() || !q3.isEquivalentTo(p3)) {
        std::cout << "Failure in constructing Point(\"2.235,43.2,0.00001\") isValid()="
                  << q3.isValid()
                  << " x=" << q3.getX()
                  << " y=" << q3.getY()
                  << " z=" << q3.getZ()
                  << std::endl;
    }
}

void PointTester::testInvalid() {
    std::cout << "Execute PointTester::testInvalid" << std::endl;

    Point p0(INFINITY, 0, 0);
    Point p1(0, INFINITY, 0);
    Point p2(0, 0, INFINITY);

    if (p0.isValid()) {
        std::cout << "p0(INFINITY, 0, 0) should be invalid" << std::endl;
    }
    if (p1.isValid()) {
        std::cout << "p1(0, INFINITY, 0) should be invalid" << std::endl;
    }
    if (p2.isValid()) {
        std::cout << "p2(0, 0, INFINITY) should be invalid" << std::endl;
    }

    Point p3("INFINITY,0,0");
    Point p4("0,INFINITY,0");
    Point p5("0,0,INFINITY");

    if (p3.isValid()) {
        std::cout << "p3(\"INFINITY,0,0\") should be invalid" << std::endl;
    }
    if (p4.isValid()) {
        std::cout << "p4(\"0,INFINITY,1\") should be invalid" << std::endl;
    }
    if (p5.isValid()) {
        std::cout << "p5(\"0,0,INFINITY\") should be invalid" << std::endl;
    }

    std::string s0 = "INFINITY,0,0";
    std::string s1 = "0,INFINITY,0";
    std::string s2 = "0,0,INFINITY";
    Point p6(s0);
    Point p7(s1);
    Point p8(s2);

    if (p6.isValid()) {
        std::cout << "p6(s0) should be invalid" << std::endl;
    }
    if (p7.isValid()) {
        std::cout << "p7(s1) should be invalid" << std::endl;
    }
    if (p8.isValid()) {
        std::cout << "p8(s2) should be invalid" << std::endl;
    }

    //*************************************************************************************************************

    Point p9(INFINITY, 1, -1);
    Point p10(1, INFINITY, -1);
    Point p11(1, -1, INFINITY);

    if (p9.isValid()) {
        std::cout << "p9(INFINITY, 1, -1) should be invalid" << std::endl;
    }
    if (p10.isValid()) {
        std::cout << "p10(1, INFINITY, -1) should be invalid" << std::endl;
    }
    if (p11.isValid()) {
        std::cout << "p11(1, -1, INFINITY) should be invalid" << std::endl;
    }

    Point p12("INFINITY,1,-1");
    Point p13("-1,INFINITY,1");
    Point p14("1,-1,INFINITY");

    if (p12.isValid()) {
        std::cout << "p12(\"INFINITY,1,-1\") should be invalid" << std::endl;
    }
    if (p13.isValid()) {
        std::cout << "p13(\"-1,INFINITY,1\") should be invalid" << std::endl;
    }
    if (p14.isValid()) {
        std::cout << "p14(\"1,-1,INFINITY\") should be invalid" << std::endl;
    }

    std::string s3 = "INFINITY,1,-1";
    std::string s4 = "-1,INFINITY,1";
    std::string s5 = "1,-1,INFINITY";
    Point p15(s3);
    Point p16(s4);
    Point p17(s5);

    if (p15.isValid()) {
        std::cout << "p15(s3) should be invalid" << std::endl;
    }
    if (p16.isValid()) {
        std::cout << "p16(s4) should be invalid" << std::endl;
    }
    if (p17.isValid()) {
        std::cout << "p17(s5) should be invalid" << std::endl;
    }

    //*************************************************************************************************************

    Point p18(0, 1.486, -1.254);
    Point p19(1.486, 0, -1.254);
    Point p20(1.486, -1.254, 0);

    if (!p18.isValid()) {
        std::cout << "p18(0, 1.486, -1.254) should be valid" << std::endl;
    }
    if (!p19.isValid()) {
        std::cout << "p19(1.486, 0, -1.254) should be valid" << std::endl;
    }
    if (!p20.isValid()) {
        std::cout << "p20(1.486, -1.254, 0) should be valid" << std::endl;
    }

    Point p21("0, 1.486, -1.254");
    Point p22("1.486, 0, -1.254");
    Point p23("1.486, -1.254, 0");

    if (!p21.isValid()) {
        std::cout << "p21(\"0, 1.486, -1.254\") should be valid" << std::endl;
    }
    if (!p22.isValid()) {
        std::cout << "p22(\"1.486, 0, -1.254\") should be valid" << std::endl;
    }
    if (!p23.isValid()) {
        std::cout << "p23(\"1.486, -1.254, 0\") should be valid" << std::endl;
    }

    std::string s6 = "0, 1.486, -1.254";
    std::string s7 = "1.486, 0, -1.254";
    std::string s8 = "1.486, -1.254, 0";
    Point p24(s6);
    Point p25(s7);
    Point p26(s8);

    if (!p24.isValid()) {
        std::cout << "p24(s6) should be valid" << std::endl;
    }
    if (!p25.isValid()) {
        std::cout << "p25(s7)) should be valid" << std::endl;
    }
    if (!p26.isValid()) {
        std::cout << "p26(s8) should be valid" << std::endl;
    }

    //*************************************************************************************************************

    Point p27(6, 1.486, -1.254);
    Point p28(1.486, 6, -1.254);
    Point p29(1.486, -1.254, 6);

    if (!p27.isValid()) {
        std::cout << "p27(6, 1.486, -1.254) should be valid" << std::endl;
    }
    if (!p28.isValid()) {
        std::cout << "p28(1.486, 6, -1.254) should be valid" << std::endl;
    }
    if (!p29.isValid()) {
        std::cout << "p29(1.486, -1.254, 6) should be valid" << std::endl;
    }

    Point p30(6.0, 1.486, -1.254);
    Point p31(1.486, 6.0, -1.254);
    Point p32(1.486, -1.254, 6.0);

    if (!p30.isValid()) {
        std::cout << "p30(6.0, 1.486, -1.254) should be valid" << std::endl;
    }
    if (!p31.isValid()) {
        std::cout << "p31(1.486, 6.0, -1.254) should be valid" << std::endl;
    }
    if (!p32.isValid()) {
        std::cout << "p32(1.486, -1.254, 6.0) should be valid" << std::endl;
    }
}

