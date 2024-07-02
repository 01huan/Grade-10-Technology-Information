#include <iostream>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    int mid = left + (right-left)/2;
    if (left > right) return -1;
    if (target == arr[mid]) {
        return mid;
    } else if (target < arr[mid]) {
        return binarySearch(arr, left, mid-1, target);
    } else {
        return binarySearch(arr, mid+1, right, target);
    } return -1;
}

void insertionSort(int arr[], int len) {
    for (int i=1; i<len; i++) {
        int j=i-1, temp=arr[i];
        while ((j>=0) && (arr[j]>temp)) {
            arr[j+1] = arr[j];
            j--;
        } arr[j+1] = temp;
    }
}

int main() {
    srand(time(0));
    int len;
    cout << "Length of the array: ";
    cin >> len;
    int arr[len];
    for (int i=0; i<len; i++) {
        int x = rand()%100 - 30;
        arr[i] = x;
    } insertionSort(arr, len);
    while (1) {
        int target;
        cout << "Enter the target number: ";
        if (!(cin >> target)) {
            break;
        } int ans = binarySearch(arr, 0, len-1, target);
        if (ans == -1) {
            cout << "Number " << target << " not found.\n";
        } else {
            cout << "Number " << target << " found at the index: " << ans << ".\n";
        }
    }
}