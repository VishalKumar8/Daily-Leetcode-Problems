// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        using RET = pair<int, int>;
        RET result{};
        vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, -1, 0, nullptr, &result}};
        while (!stk.empty()) {
            const auto [step, par, node, new_ret, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                ret->second = int(hasApple[node]);
                for (const auto& nei : graph[node]) {
                    if (nei == par) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(2, -1, -1, new_ret, ret);
                    stk.emplace_back(1, node, nei, nullptr, new_ret.get());
                }
            } else {
                ret->first += new_ret->first + new_ret->second;
                ret->second |= bool(new_ret->first + new_ret->second);
            }
        }
        return 2 * result.first;
    }
};
