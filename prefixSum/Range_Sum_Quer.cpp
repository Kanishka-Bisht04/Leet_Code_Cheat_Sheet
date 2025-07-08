#include <iostream>
#include <vector>
using namespace std;

vector<int> buildPrefixSum(const vector<int>& nums) {
    vector<int> prefix;
    prefix.push_back(0); // prefix[0] = 0 for easy subtraction

    for (int i = 0; i < nums.size(); i++) {
        prefix.push_back(prefix[i] + nums[i]);
    }
    return prefix;
}

// Return the sum from left to right (inclusive)
int getRangeSum(const vector<int>& prefix, int left, int right) {
    return prefix[right + 1] - prefix[left];
}

int main() {
    // Input array
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    // Build prefix sum
    vector<int> prefix = buildPrefixSum(nums);

    // Test some queries using the prefix
    cout << "Sum from index 0 to 2: " << getRangeSum(prefix, 0, 2) << endl;  // Output: 1
    cout << "Sum from index 2 to 5: " << getRangeSum(prefix, 2, 5) << endl;  // Output: -1
    cout << "Sum from index 0 to 5: " << getRangeSum(prefix, 0, 5) << endl;  // Output: -3

    return 0;
}
