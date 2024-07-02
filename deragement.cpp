#include <iostream>
using namespace std;

int factorial(int x) {
    if (!x) {
        return 1;
    } else {
        return factorial(x-1)*x;
    }
}

int C(int n, int k) {
    if ((n==k) || (k==0)) {
        return 1;
    } else {
        return C(n-1,k-1)+C(n-1,k);
    }
}
int D(int n) {
    int ans, i;
    ans = factorial(n);
    if (n == 0) {
        return 1;
    }
    else {
        for (i=0; i<n; i++) {
            ans -= D(i) * C(n,i);
        } return ans;
    }
}

int main() {
    int n;
    cout << "Number of object: ";
    cin >> n;
    for (int i=0; i<=n; i++) {
        cout << "Number of derangement of " << i << " object";
        if (!((i==0) || (i==1))) {
            cout << "s";
        }
        cout << " = " << D(i) << endl;
    }
}