#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minKforEating(vector<int>& arr, int h, double k) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)arr[i] / k);
    }

    if (sum <= h) {
        return (int)k;
    } else {
        return minKforEating(arr, h, k + 1);
    }
}

int main() {
    vector<int> arr = {3, 6, 7, 11};
    int ans = minKforEating(arr, 8, 1.0);
    cout << ans << endl;
    return 0;
}
