#include <iostream>
using namespace std;

int max(int arr[], int len) {
    int max=0;
    for (int i=1; i<len; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    } return arr[max];
}

int min(int arr[], int len) {
    int min=0;
    for (int i=1; i<len; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    } return arr[min];
}

int main() {
    int len, k;
    while (cin >> len >> k) {
        int * arr = new int[len];
        for (int i=0; i<len; i++) {
            cin >> arr[i];
        }
        int * M = new int[len-k+1];
        int * m = new int[len-k+1];
        for (int i=0; i<=len-k; i++) {
            int * window = new int[k];
            for (int j=0; j<k; j++) {
                window[j] = arr[i+j];
            }
            m[i] = min(window, k);
            M[i] = max(window, k);
            delete[] window;
        } delete[] arr;
        for (int i=0; i<=len-k; i++) {
            cout << m[i];
            if (i == len-k) cout << "\n";
            else cout << " ";
        } delete[] m;
        for (int i=0; i<=len-k; i++) {
            cout << M[i];
            if (i == len-k) cout << "\n";
            else cout << " ";
        } delete[] M;
    }
}