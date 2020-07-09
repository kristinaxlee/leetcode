class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> tSum{-1, -1};
        vector<int>::iterator it;

        for(int i = 0; i < nums.size(); i++) {

            // set first to be the current index
            tSum[0] = i;

            // search for target - firstNumber using C++ find function
            it = find(nums.begin(), nums.end(), target - nums[i]);

            if(it != nums.end()) {
                int index = distance(nums.begin(), it);

                //if the numbers are not the same index
                if(tSum[0] != index) {
                    tSum[1] = index;
                    break;
                }

            }

        }

        return tSum;

    }
};
