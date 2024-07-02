#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

double x, y;
pair<double, double> A;
pair<double, double> B;
pair<double, double> C;
pair<double, double> O;
pair<double, double> I;
pair<double, double> G;
pair<double, double> H;

double PosNegError(double n) {
    if (abs(n) != n) {
        return -abs(n);
    } else {
        return abs(n);
    }
}
pair<double, double> Circumcenter(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    double xA = A.first, yA = A.second, xB = B.first, yB = B.second, xC = C.first, yC = C.second;
    double xD = (xA + xB) / 2, yD = (yA + yB) / 2, xE = (xA + xC) / 2, yE = (yA + yC) / 2;
    double mAB = (yA-yB) / (xA-xB), mDO = -(xA-xB) / (yA-yB), mAC = (yA-yC) / (xA-xC), mEO = -(xA-xC) / (yA-yC);
    x = PosNegError((-mEO * xE + yE + mDO * xD - yD) / (mDO - mEO));
    y = PosNegError(mEO * (x - xE) + yE);
    return make_pair(x, y);
}
pair<double, double> Incenter(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    double xA = A.first, yA = A.second, xB = B.first, yB = B.second, xC = C.first, yC = C.second;
    double a = sqrt(pow(xB-xC, 2) + pow(yB-yC, 2)), b = sqrt(pow(xA-xC, 2) + pow(yA-yC, 2)), c = sqrt(pow(xA-xB, 2) + pow(yA-yB, 2));
    x = (a*xA + b*xB + c*xC) / (a + b + c);
    y = (a*yA + b*yB + c*yC) / (a + b + c);
    return make_pair(x, y);
}
pair<double, double> Centroid(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    x = PosNegError((A.first + B.first + C.first) / 3);
    y = PosNegError((A.second + B.second + C.second) / 3);
    return make_pair(x, y);
}
pair<double, double> Orthocenter(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    double xA = A.first, yA = A.second, xB = B.first, yB = B.second, xC = C.first, yC = C.second;
    double mAB = (yA-yB) / (xA-xB), mDH = -(xA-xB) / (yA-yB), mAC = (yA-yC) / (xA-xC), mEH = -(xA-xC) / (yA-yC);
    x = PosNegError((-mEH * xB + yB + mDH * xC - yC) / (mDH - mEH));
    y = PosNegError(mEH * (x - xB) + yB);
    return make_pair(x, y);
}

int main() {
    cout << "Enter 3 coordinates:" << endl;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cout << "A(" << A.first << ", " << A.second << ")  " << "B(" << B.first << ", " << B.second << ")  " << "C(" << C.first << ", " << C.second << ")" << endl;
    cout << "---------------------" << endl;
    O = Circumcenter(A, B, C);
    I = Incenter(A, B, C);
    G = Centroid(A, B, C);
    H = Orthocenter(A, B, C);
    cout << "O(" << O.first << ", " << O.second << ")" << endl;
    cout << "I(" << I.first << ", " << I.second << ")" << endl;
    cout << "G(" << G.first << ", " << G.second << ")" << endl;
    cout << "H(" << H.first << ", " << H.second << ")" << endl;
}