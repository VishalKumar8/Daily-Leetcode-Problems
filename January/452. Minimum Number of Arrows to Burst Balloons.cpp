/* Intuition: question asks for minimum, so either DP or Greedy can be applied. We will solve using Greedy algorithm.

Approach:

=> We can sort the array based on starting or ending points, lets go with ending points.
=> Lets observe the given test case

=> input: points = [[10,16],[2,8],[1,6],[7,12]]
   output: 2
   Explanation: The balloons can be burst by 2 arrows: 
   - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
   - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
   
=> Here we can see that [1,6] and [2,8] overlap because starting of [2,8] is less than ending of [1,6]. In such cases 1 arrow will burst them both.
=> But if we check [1,6] and [7,12], they do not overlap because starting of [7,12] is not less than ending of [1,6]. In such cases, another arrow will be needed to burst it.

=> We will just apply this logic in our solution.  */


/* Time Complexity => O(NlogN)
   Space Complexity => O(1)     */

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        
        sort(points.begin(), points.end(), comp);
        
        int arrows = 1;
        int last = points[0][1];
        
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0]>last)
            {
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
};
