// House Robber LeetCode
// Max Sum Such that No Two Elements are Adjacent

// https://leetcode.com/problems/house-robber/
// https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.  [EXPLANATION]

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int dp[n];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++) dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        
        return dp[n-1];
    }
};
