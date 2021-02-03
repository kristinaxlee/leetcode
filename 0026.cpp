class Solution {
public:
    
    void swap(vector<int>&nums, int x1, int x2) {
        int temp = nums[x1]; //contains number at x1
        nums[x1] = nums[x2];
        nums[x2] = temp;
    }
    
    int findNextNumber(vector<int>&nums, int curIdx, int searchNum) {
        
        int i = curIdx;
        int foundIdx;
        
        // search through the array until we find the next number in the series
        while(1) {    
            if(nums[i] >= searchNum) {
                foundIdx = i;
                break;
            }
            i++;
        }
        return foundIdx;
    }
    
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }
        
        // find the highest number in the array, once we have sorted up to this point, we can stop
        int hi = nums[nums.size()-1];
        //bool finished = false;
        
        int prev = nums[0], curIdx = 1;
        
        
        
        if(nums[0] == hi) {
            return 1;
        }
        
        while(1) {
            // check and see if the number is a duplicate
            if(nums[curIdx] <= prev) {
                // find the next number in the series
                int swapIdx = findNextNumber(nums, curIdx, prev+1);
                // swap the numbers
                swap(nums, curIdx, swapIdx);
            }
            
            // check and see if we've reached the last number
            if(nums[curIdx] == hi) {
                //finished = true;
                break;
            }
            
            prev = nums[curIdx];
            curIdx++;
        }
        
        
        return curIdx + 1;
    }
};