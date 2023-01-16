class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
};
/*************************************************************************************************/
vector<vector<int>> Solution::insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    vector<vector<int>> v{};
    size_t i{0}, size{0}, sizeIntervals{intervals.size()};
    /* sort intervals by first value */
    sort(intervals.begin(), intervals.end());
    /* process data */    
    for (; i < sizeIntervals; ++i) {
        if (i == 0 || v.at(size-1).at(1) < intervals.at(i).at(0)) {
            /* just push the new element to the vector */
            /* new non overlapping interval, just push the new element because end i-1 < start i */
            v.push_back(intervals.at(i));
            ++size;
        } else if (v.at(size-1).at(1) >= intervals.at(i).at(0) && v.at(size-1).at(1) < intervals.at(i).at(1)) {
            /* update previous interval because end i-1 < start i and end i-1 < end i */
            v.at(size-1).at(1) = intervals.at(i).at(1);
        }
    }
    return v;
}
/*************************************************************************************************/
