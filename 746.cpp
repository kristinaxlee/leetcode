class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //create array to hold the optimum values
        int opt[cost.size()];

        // if length of cost array is 2, return smaller element
        if(cost.size() == 2) {
            return min(cost[0], cost[1]);

        }

        // fill memoization array
        for(int i=0; i < cost.size(); i++) {

            if(i == 0 || i == 1) {
                opt[i] = cost[i];
            }

            else {
                opt[i] = min(opt[i-1] + cost[i], opt[i-2] + cost[i]);
            }
        }

        // return the smaller of the last 2 elements in the array
        return min(opt[cost.size()-1], opt[cost.size()-2]);
    }
};
