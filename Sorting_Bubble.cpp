#include <bits/stdc++.h>
using namespace std;

// function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // if no swapping happened, array is already sorted
        if(!swapped)
            break;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
