#include <iostream>
#include <climits>
using namespace std;

int main() {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    int arr[10] = {0, -1, -5};
    int n = 3;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;

    return 0;
}
