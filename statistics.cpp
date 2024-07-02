#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

double Mean(vector<double> data) {
    double total = 0;
    for (int i=0; i<data.size(); i++) {
        total += data[i] / data.size();
    } return total;
}

double StandardDeviation(vector<double> data) {
    double variance, squaredSum=0;
    for (int i=0; i<data.size(); i++) {
        squaredSum += pow(data[i], 2);
    } variance = squaredSum / data.size() - pow(Mean(data), 2);
    return sqrt(variance);
}

double CorrelationCoefficient(vector<pair<double, double>> data) {
    double productSum=0, r;
    vector<double> x;
    vector<double> y;
    for (int i=0; i<data.size(); i++) {
        x.push_back(data[i].first);
        y.push_back(data[i].second);
    }
    for (int i=0; i<data.size(); i++) {
        productSum += (x[i]-Mean(x)) * (y[i]-Mean(y));
    } r = productSum / StandardDeviation(x) / StandardDeviation(y) / data.size();
    return r;
}


int main() {
    char mode;
    cout << "Mode:\n(1)Mean\n(2)Standard Deviation\n(3)Correletion Coefficient\nMode: ";
    cin >> mode;
    if (mode == '1') {
        vector<double> data;
        double index, count=0;
        cout << "No" << count+1 << ". ";
        while (cin >> index) {
            count++;
            data.push_back(index);
            cout << "No" << count+1 << ". ";
        } cout << "Mean[";
        for (int i=0; i<data.size(); i++) {
            cout << data[i];
            (i == data.size()-1) ? (cout << "] = " << Mean(data) << endl) : (cout << ", ");
        }
    } else if (mode == '2') {
        vector<double> data;
        double index, count=0;
        cout << "No" << count+1 << ". ";
        while (cin >> index) {
            count++;
            data.push_back(index);
            cout << "No" << count+1 << ". ";
        } cout << "Standard Deviation[";
        for (int i=0; i<data.size(); i++) {
            cout << data[i];
            (i == data.size()-1) ? (cout << "] = " << StandardDeviation(data) << endl) : (cout << ", ");
        }
    } else if (mode == '3') {
        vector<pair<double, double>> data;
        double x, count=0;
        cout << "x" << count+1 << " y" << count+1 << ": ";
        while (cin >> x) {
            double y;
            count++;
            cin >> y;
            data.push_back({x, y});
            cout << "x" << count+1 << " y" << count+1 << ": ";
        } cout << "Correlation Coefficient[";
        for (int i=0; i<data.size(); i++) {
            cout << "(" << data[i].first << "," << data[i].second << ")";
            (i == data.size()-1) ? (cout << "] = " << CorrelationCoefficient(data) << endl) : (cout << ", ");
        }
    } else {
        cout << "quit";
    }
}