#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  // To store prefix sum

public:
    // Constructor that takes the input array and builds the prefix sum
    NumArray(vector<int>& nums) {
        prefix.push_back(0);  // Start with 0 for easier subtraction
        for (int i = 0; i < nums.size(); i++) {
            prefix.push_back(prefix[i] + nums[i]);
        }
    }

    // Function to get sum from left to right (inclusive)
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    // Input array
    vector<int> nums = {-2, 0, 3, -5, 2, -1};

    // Create object of NumArray
    NumArray obj(nums);

    // Test some queries
    cout << "Sum from index 0 to 2: " << obj.sumRange(0, 2) << endl;  // Output: 1
    cout << "Sum from index 2 to 5: " << obj.sumRange(2, 5) << endl;  // Output: -1
    cout << "Sum from index 0 to 5: " << obj.sumRange(0, 5) << endl;  // Output: -3

    return 0;
}
