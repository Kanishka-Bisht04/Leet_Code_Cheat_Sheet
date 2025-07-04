//Optimized approach using prefix sum  --> o(n)
#include <iostream>
#include <vector>
using namespace std;

// Optimized approach using prefix sum
bool canBeDivided(const vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;

    // Step 1: Calculate total sum
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int prefix = 0;

    // Step 2: Check if there's a split point
    for (int i = 0; i < n-1; i++) {
        prefix += arr[i];  // sum of left part
        int rightSum = totalSum - prefix;

        if (prefix == rightSum ) {
            cout << "✅ Array can be divided at index " << i
                 << " into two parts with equal sum: " << prefix << endl;
            return true;
        }
    }

    return false;  // just return false silently
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    canBeDivided(arr);  // just call the function, no if needed

    return 0;
}
