#include <iostream>
#include <vector>
using namespace std;


int rowWithMax1(vector<vector<int>>& arr) {
    int r = arr.size();
    int c = arr[0].size();
    int ans = -1;
    int max1Count = 0;

    for (int i = 0; i < r; i++) {
        int start = 0;
        int end = c - 1;
        int firstOneIndex = c; // If no 1s found, default is c (means 0 ones)

        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[i][mid] == 1) {
                firstOneIndex = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        int count1 = c - firstOneIndex;
        if (count1 > max1Count) {
            max1Count = count1;
            ans = i;
        }
    }

    return ans;
}

//✨ Optmial O(R+C) approach
int rowWithMax1Optimal(vector<vector<int>>& arr) {
    int r = arr.size();
    int c = arr[0].size();
    int maxRowIndex = -1;
    int j = c - 1; // Start from top-right

    for (int i = 0; i < r; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;              // move left
            maxRowIndex = i;  // update answer
        }
    }
    return maxRowIndex;
}

int main() {
    vector<vector<int>> arr = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}
    };
    int ans = rowWithMax1Optimal(arr);
    cout << ans;
}
