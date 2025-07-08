#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findMaxLength(vector<int> &nums){
    //covert all 0s to -1
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            nums[i]=-1;
        }
    }

    int sum=0;
    int maxLength=0;
    unordered_map<int, int> map;
    map[0] = -1; // Initialize with sum 0 at index -1
    for(int i=0;i<nums.size();i++){
        sum += nums[i];

        // If this sum has been seen before, calculate the length of the subarray
        if(map.find(sum) != map.end()){
            int last = map[sum];
            // Update maxLength if the current subarray is longer
            maxLength = max(maxLength, i - last);
        } else {
            // Store the first occurrence of this sum
            map[sum] = i;
        }
    }
    return maxLength;
}
int main(){
    vector<int> nums = {0, 1, 0, 1, 0, 1};
    int result = findMaxLength(nums);
    cout << "The maximum length of a contiguous subarray with equal number of 0s and 1s is: " << result << endl;
    return 0;
}