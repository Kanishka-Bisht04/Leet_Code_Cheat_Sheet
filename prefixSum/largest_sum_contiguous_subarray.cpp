// Kadane's Algorithm
#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Function to return the maximum sum of contiguous subarray
int LargestSum(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum;

        if (currentSum < 0)
            currentSum = 0;  // Reset if current sum becomes negative
    }

    return maxSum;
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

    int result = LargestSum(arr);
    cout << "Maximum contiguous subarray sum is: " << result << endl;

    return 0;
}
