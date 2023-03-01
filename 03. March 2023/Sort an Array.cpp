class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> sorted(nums.size());
        int MAX = *max_element(begin(nums), end(nums));
        int min = *min_element(begin(nums), end(nums));
        int range = MAX-min+1;
        vector<int> count(range);
        vector<int> start(range);
        for (int i=0; i<nums.size(); i++)
        {
            count[nums[i]-min]++;
        }
        for(int i=1; i<range; i++)
        {
            start[i] =start[i-1]+count[i-1];
        }
        for(int i=0; i<nums.size(); i++)
        {
            sorted[start[nums[i]-min]]=nums[i];
            start[nums[i]-min]++;
        }
        return sorted;
    }
};
