/* prefix sum and suffix sum -> query sum of elements in a subarray

Array --> [1,2,3,4,5,6,7]
PrefixSum --> [1,3,6,10,15,21,28]

p[i] = A[0] + A[1] + ....... + A[i]
1st ele is fixed --> prefielementsx[0] = arr[0];
prefix[i] = prefix[i-1]+arr[i];

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the prefix sum vector
    vector<int> prefix = computePrefixSum(arr);

    // Print the prefix sum
    cout << "Prefix Sum: ";
    for (int val : prefix) {
        cout << val << " ";
    }

    return 0;
}





/*
Step 1️⃣: Take Input
int n;
cin >> n;
vector<int> arr(n);
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
💭 What is happening here?
We ask the user for the number of elements n, then read n numbers into a vector<int>.

*/

