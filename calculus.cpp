#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


void OutputTheFunction(vector<double> terms) {
    for (int i=terms.size()-1; i>=0; i--) {
        if (terms[i] != 0) {
            if (i == terms.size()-1) {
                if (terms[i] < 0) {
                    cout << " -";
                } else {
                    cout << " ";
                }
            } else {
                if (terms[i] < 0) {
                    cout << " - ";
                } else {
                    cout << " + ";
                }
            }
            if ((abs(terms[i]) != 1) || (i == 0)) {
                cout << abs(terms[i]);
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
}

vector<double> Differentiate(vector<double> terms) {
    vector<double> derivative;
    for (int i=1; i<terms.size(); i++) {
        derivative.push_back(i*terms[i]);
    } return derivative;
}

vector<double> Integrate(vector<double> terms) {
    vector<double> integral;
    if (terms.size() != 1) {
        integral.push_back(0);
        for (int i=1; i<=terms.size(); i++) {
            integral.push_back(terms[i-1]/i);
        }
    } else {
        integral.push_back(0);
    } return integral;
}


int main() {
    int deg;
    vector<double> coefficients;
    cout << "deg(f) = ";
    cin >> deg;
    for (int i=0; i<=deg; i++) {
        coefficients.push_back(0);
    }
    for (int i=deg; i>=0; i--) {
        if (i == 0) {
            cout << "coefficient of constant: ";
        } else if (i == 1) {
            cout << "coefficient of x: ";
        } else {
            cout << "coefficient of x^" << i << ": ";
        } cin >> coefficients[i];
    }
    cout << endl << "f(x) =";
    OutputTheFunction(coefficients);
    cout << endl << "f'(x) =";
    OutputTheFunction(Differentiate(coefficients));
    cout << endl << "F(x) =";
    OutputTheFunction(Integrate(coefficients));
    cout << " + C" << endl;


    int mode;
    while (1) {
        cout << endl << "(1) derivative";
        cout << endl << "(2) integral";
        cout << endl << "(3) original function";
        cout << endl << "Mode: ";
        cin >> mode;
        if (mode == 1) {
            double x, y=0;
            cout << "Enter \"x\" to calculate the derivative value: ";
            cin >> x;
            for (int i=0; i<Differentiate(coefficients).size(); i++) {
                y += Differentiate(coefficients)[i] * pow(x, i);
            } cout << "f'(" << x << ") = " << y << endl;
        } else if (mode == 2) {
            double a, b, I=0;
            cout << "Enter \"a\" to calculate the integral from \"a\" to \"b\": ";
            cin >> a;
            cout << "Enter \"b\" to calculate the integral from \"a\" to \"b\": ";
            cin >> b;
            for (int i=0; i<Integrate(coefficients).size(); i++) {
                I += Integrate(coefficients)[i] * pow(b, i);
            } for (int i=0; i<Integrate(coefficients).size(); i++) {
                I -= Integrate(coefficients)[i] * pow(a, i);
            } cout << "F(" << b << ") - F(" << a << ") = " << I << endl;
        } else if (mode == 3) {
            double x, y=0;
            cout << "Enter \"x\" to calculate the orginal function value: ";
            cin >> x;
            for (int i=0; i<coefficients.size(); i++) {
                y += coefficients[i] * pow(x, i);
            } cout << "f(" << x << ") = " << y << endl;
        } else {
            cout << "left";
            break;
        }
    }
}