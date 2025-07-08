// subarray --> continuous part of an array
/*
arr = [4,5,6,7]
1 size => 4     5    6     7
2 size => 4,5   5,6    6,7     
3 size => 4,5,6     5,6,7
4 size => 4,5,6,7
*/ 

// Qus -> Divide array in 2 subarray with equal sum
// [3,4,-2,5,8,20,-10,8]
//  | --18-- | | --18-- |

// 1st part --> 0 to i then i+1 to n

// Brute force approach ---> o(n^2)

#include <iostream>
#include <vector>
using namespace std;

bool canBeDivided(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int sum1 = 0, sum2 = 0;

        // Sum of left part: 0 to i
        for (int j = 0; j <= i; j++) {
            sum1 += arr[j];
        }

        // Sum of right part: i+1 to n-1
        for (int j = i + 1; j < n; j++) {
            sum2 += arr[j];
        }

        // If both parts are equal
        if (sum1 == sum2) {
            cout << "Array can be divided at index " << i << " into two parts with equal sum." << endl;
            return true;
        }
    }
    cout << "Array cannot be divided into two parts with equal sum." << endl;
    return false; 
}

int main() {
    vector<int> arr = {3, 4, -2, 5, 8, 20, -10, 8};
    canBeDivided(arr);

    return 0;
}



