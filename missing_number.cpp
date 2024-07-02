#include <iostream>
using namespace std;

void insertionSort(int arr[], int len) {
    for (int i=1; i<len; i++) {
        int j=i-1, temp=arr[i];
        while (j+1 && (temp<arr[j])) {
            arr[j+1] = arr[j];
            j--;
        } arr[j+1] = temp;
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right-left)/2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) {
        return binarySearch(arr, left, mid-1, target);
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid+1, right, target);
    } return -1;
}

int main() {
    int len;
    cout << "Length of the array: ";
    cin >> len;
    int arr[len]={0};
    cout << "Enter any " << len-1 << " different numbers integer between 1 and " << len << ": ";
    for (int i=1; i<len; i++) {
        cin >> arr[i];
    } insertionSort(arr, len);
    for (int i=1; i<=arr[len-1]; i++) {
        if (binarySearch(arr, 0, len-1, i) == -1) {
            cout << "The missing number is " << i << ".\n";
        }
    }
}