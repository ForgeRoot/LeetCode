// URL: https://leetcode.com/problems/valid-mountain-array/description/
// 
// 941. Valid Mountain Array
// 
// Given an array of integers arr, return true if and only if it is a valid mountain array.
// 
// Recall that arr is a mountain array if and only if:
// 
// 	arr.length >= 3
// 	There exists some i with 0 < i < arr.length - 1 such that:
// 	
// 		arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// 		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// 	
// 	
// 
//  
// Example 1:
// Input: arr = [2,1]
// Output: false
// Example 2:
// Input: arr = [3,5,5]
// Output: false
// Example 3:
// Input: arr = [0,3,2,1]
// Output: true
// 
//  
// Constraints:
// 
// 	1 <= arr.length <= 104
// 	0 <= arr[i] <= 104

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool mountainFlag = false;
        bool mountainRise = false;
        bool mountainFall = false;
        for (int i = 1; i < arr.size(); i++){
            if (!mountainFlag){
                if (arr[i-1] > arr[i])
                    mountainFlag = true;
                else if (arr[i-1] == arr[i])
                    return false;
                else 
                    mountainRise = true;
            } else if (mountainFlag){
                if (arr[i-1] < arr[i])
                    return false;
                else if (arr[i-1] == arr[i])
                    return false;
                else
                    mountainFall = true;
            }
        }
        if (mountainRise == true && mountainFall == false)
            return true;
        else
            return false;
    }
};


