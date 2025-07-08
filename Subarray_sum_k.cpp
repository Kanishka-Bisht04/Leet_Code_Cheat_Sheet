#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;

        if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - k];
        }

        prefixSumCount[currentSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3}; // You can change input here
    int k = 3;

    int result = subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
