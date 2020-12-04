class Solution {
public:

    // returns index of where number is found, or if not found, where it should be
    // does NOT return -1 if number isn't found
    int binarySearch(vector<int>& nums, int target, int &index) {
        int lo = 0;
        int hi = nums.size()-1;
        int mid;

        while(lo <= hi) {
            mid = (lo+hi)/2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] < target) {
                lo = mid+1;
            }

            else {
                hi = mid-1;
            }
        }

        if(target < nums[lo]) {
            index = lo;
        }

        else {
            index = lo+1;
        }

        return index;

    }

    int searchInsert(vector<int>& nums, int target) {

        if(nums[0] > target) {
            return 0;
        }

        else if(nums[nums.size()-1] < target) {
            return nums.size();
        }

        else {
            int index;

            return binarySearch(nums, target, index);
        }

    }
};
