#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minDiffKadaneStyle(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;

    sort(arr.begin(), arr.end()); // Step 1: Sort

    int minDiff = INT_MAX;

    // Step 2: Kadane-style loop on adjacent elements
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1];  // just like currentSum
        minDiff = min(minDiff, diff);    // just like maxSum = max(...)
    }

    return minDiff;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minDiffKadaneStyle(arr);
    cout << "Minimum difference is: " << result << endl;

    return 0;
}
