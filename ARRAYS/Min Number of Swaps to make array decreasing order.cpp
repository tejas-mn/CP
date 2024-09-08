#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum number of swaps
int minSwapsToSortDecreasing(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arrPos(n);

    // Store the value and its index
    for (int i = 0; i < n; i++) {
        arrPos[i] = {arr[i], i};
    }

    // Sort the array by value in decreasing order
    sort(arrPos.begin(), arrPos.end(), greater<pair<int, int>>());

    // To keep track of visited elements
    vector<bool> visited(n, false);

    // Initialize the number of swaps
    int swaps = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If already visited or at correct position, skip
        if (visited[i] || arrPos[i].second == i) {
            continue;
        }

        // Find the cycle length
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            // Move to the index where the current element should go
            j = arrPos[j].second;
            cycle_size++;
        }

        // If there's a cycle of size n, we need n-1 swaps to sort it
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 3};
    cout << "Minimum number of swaps: " << minSwapsToSortDecreasing(arr) << endl;
    return 0;
}
