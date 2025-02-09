class Solution {
    public:
        vector<vector<int>> ret_;
        vector<int> cur_combination_;
    
        void dfs(vector<int>& candidates, int cur, int index, int target) {
            if (index >= candidates.size()) {
                return;
            }
    
            int cnt = 0;
            do {
                dfs(candidates, cur, index+1, target);
                cur += candidates[index];
                cur_combination_.push_back(candidates[index]);
                cnt++;
            } while (cur < target);
    
            if (cur == target) {
                ret_.push_back(cur_combination_);
            }
    
            while(cnt--) {
                cur_combination_.pop_back();
            }
            return;
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            dfs(candidates, 0, 0, target);
            return ret_;
        }
    };