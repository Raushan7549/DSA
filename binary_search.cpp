#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int arr[11] = {1,23,34,44,45,56,76,77,88,98,99};
//     int left = 0;
//     int right = 10;
//     int value;
//     cin >> value;

//     bool found = false;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (arr[mid] == value) {
//             found = true;
//             break;
//         } else if (arr[mid] > value) {
//             right = mid - 1;
//         } else {
//             left = mid + 1;
//         }
//     }

//     if (found) {
//         cout << "Element found.";
//     } else {
//         cout << "Element not found.";
//     }
    
//     return 0;
// }

int main() {
    long long x, y;
    cin >> x >> y;

    long long result = 1;

    while (y > 0) {
        if (y % 2 == 1) {
            result = result * x;
        }
        x = x * x;
        y = y / 2;
    }

    cout << result;
    return 0;
}