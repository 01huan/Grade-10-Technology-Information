#include <iostream>
using namespace std;

void outputArray(int arr[], int len) {
    for (int i=0; i<len; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

void copyArray(int arr[], int copied[], int len) {
    for (int i=0; i<len; i++) {
        copied[i] = arr[i];
    }
}

void bubbleSort(int arr[], int len) {
    cout << "Bubble sort:\n";
    for (int i=1; i<=len; i++) {
        for (int j=0; j<len-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } cout << "Comparison " << i << ": ";
        outputArray(arr, len);
    }
    cout << "Sorted array: ";
    outputArray(arr, len);
}

void selectionSort(int arr[], int len) {
    cout << "Selection sort:\n";
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            if (arr[i] > arr[j]) {
                int temp=arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } cout << "Comparison " << i+1 << ": ";
        outputArray(arr, len);
    }
    cout << "Sorted array: ";
    outputArray(arr, len);
}

void insertionSort(int arr[], int len) {
    cout << "Insertion sort:\n";
    for (int i=1; i<len; i++) {
        int j=i-1, temp=arr[i];
        while (j+1 && (arr[j]>temp)) {
            arr[j+1] = arr[j];
            j--;
        } arr[j+1] = temp;
        cout << "Comparison " << i << ": ";
        outputArray(arr, len);
    }
    cout << "Sorted array: ";
    outputArray(arr, len);
}

int main() {
    int len;
    cout << "Length of the array: ";
    cin >> len;
    int array[len];
    cout << "Array: ";
    for (int i=0; i<len; i++) {
        cin >> array[i];
    }
    int copy[len];
    cout << "The original: ";
    outputArray(array, len);
    
    copyArray(array, copy, len);
    bubbleSort(copy, len);

    copyArray(array, copy, len);
    selectionSort(copy, len);

    copyArray(array, copy, len);
    insertionSort(copy, len);
}