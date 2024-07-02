#include <iostream>
using namespace std;

int step=0;
void Hanoi(char A, char B, char C, int n) {
    if (n == 1) {
        step++;
        cout << "Step " << step << ": Move " << n << " from " << A << " to " << C << ".\n";
        return;
    }
    Hanoi(A, C, B, n-1);
    step++;
    cout << "Step " << step << ": Move " << n << " from " << A << " to " << C << ".\n";
    Hanoi(B, A, C, n-1);
}

int main() {
    int n;
    cout << "Number of tower: ";
    cin >> n;
    cout << "(1 is the top one, " << n << " is the bottom one.)\n";
    Hanoi('A', 'B', 'C', n);
}