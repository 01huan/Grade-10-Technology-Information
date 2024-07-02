#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int factorial(int x) {
    if (x == 0) {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

vector<double> differentiate(vector<double> terms) {
    vector<double> derivative;
    for (int i=1; i<terms.size(); i++) {
        derivative.push_back(i*terms[i]);
    } return derivative;
}

double y(vector<double> terms, double x) {
    double y=0;
    for (int i=0; i<terms.size(); i++) {
        y += terms[i] * pow(x, i);
    } return y;
}

vector<double> NthOrderD(vector<double> terms, int n) {
    for (int i=0; i<n; i++) {
        terms = differentiate(terms);
    } return terms;
}

void OutputTheResult(vector<double> terms, double a) {
    char sgn;
    if (a >= 0) {
        sgn = '-';
    } else {
        sgn = '+';
    } int deg = terms.size()-1;
    for (int i=deg; i>=0; i--) {
        double coefficient = y(NthOrderD(terms, i), a) / factorial(i);
        if (coefficient != 0) {
            if (i == deg) {
                if (coefficient < 0) {
                    cout << " -";
                } else {
                    cout << " ";
                }
            } else {
                if (coefficient < 0) {
                    cout << " - ";
                } else {
                    cout << " + ";
                }
            }
            if (abs(coefficient) != 1 || i == 0) {
                cout << abs(coefficient);
            }
            if (i == 0) {
                cout << "";
            } else if (i == 1) {
                cout << "(x" << sgn << abs(a) << ")";
            } else {
                cout << "(x" << sgn << abs(a) << ")^" << i;
            }
        }
    }
}


int main() {
    int degree;
    vector<double> coefficients;
    cout << "deg(f) = ";
    cin >> degree;
    for (int i=0; i<=degree; i++) {
        coefficients.push_back(0);
    }

    for (int i=degree; i>=0; i--) {
        if (i == 1) {
            cout << "x term coefficient: ";
        } else if (i == 0) {
            cout << "constant term coefficient: ";
        } else {
            cout << "x^" << i << " term coefficient: ";
        } cin >> coefficients[i];
    }

    cout << endl << "f(x) =";
    for (int i=coefficients.size()-1; i>=0; i--) {
        if (coefficients[i] != 0) {
            if (i == coefficients.size()-1) {
                if (coefficients[i] < 0) {
                    cout << " -";
                } else {
                    cout << " ";
                }
            } else {
                if (coefficients[i] < 0) {
                    cout << " - ";
                } else {
                    cout << " + ";
                }
            }
            if ((abs(coefficients[i]) != 1) || (i == 0)) {
                cout << abs(coefficients[i]);
            }
            if (i == 0) {
                cout << "";
            } else if (i == 1) {
                cout << "x";
            } else {
                cout << "x^" << i;
            }
        }
    }
    cout << endl;
    double a;
    cout << "a: ";
    cin >> a;
    cout << "f(x) =";
    OutputTheResult(coefficients, a);
}