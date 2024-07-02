#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int A[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }
    int o, p;
    cin >> o >> p;
    if (n != o) {
        cout << "error" << endl;
        return 0;
    } int B[o][p];
    for (int i=0; i<o; i++) {
        for (int j=0; j<p; j++) {
            cin >> B[i][j];
        }
    }
    
    int AB[m][p];
    for (int i=0; i<m; i++) {
        for (int j=0; j<p; j++) {
            int index=0;
            for (int k=0; k<n; k++) {
                index += A[i][k]*B[k][j];
            } AB[i][j] = index;
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<p; j++) {
            cout << AB[i][j] << " ";
        } cout << endl;
    }
} 