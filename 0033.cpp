/*

Two pass solution:
- look for pivot point
- compare to see if target is in left or right half of array
- binary search for element in one of the halves


Complexity: 
Space: O(1)
Time: O(log n)

*/

class Solution {
public:
    
    int binarySearch(vector<int> arr, int l, int r, int x) { 
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(arr[mid]==x) {
                return mid;
            }
            else if(arr[mid] < x){
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        return -1; 
    } 
    
    int search(vector<int>& nums, int target) {
        
        int prev = nums[0], pivot = 0, index = -1;
        
        //search for pivot point here
        int left = 0;
        int right = nums.size()-1;
        
        // modified version of binary search to look for pivot point
        while(left < right) {
            int mid = left + (right-left)/2;
            
            // if the mid point is more than the right element, this is weird
                // 4,5,6,7,0,1,2 (comparing 7 and 2)
            // continue looking at right half for the pivot
            if(nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        
        pivot = left;
        
        if(target >= nums[pivot] && target <= nums[nums.size()-1]) {
            index = binarySearch(nums, pivot, nums.size()-1, target);
        }
        
        else {
            index = binarySearch(nums, 0, pivot-1, target);
        }
        
        return index;
    }
};