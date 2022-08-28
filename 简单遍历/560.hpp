class Solution {
public:
    //超时
    
    int subarraySum(vector<int>& nums, int k) {
        int ret=0;
        vector<int> cache;
        for(auto it = nums.begin(); it!=nums.end(); it++){
            if(!cache.empty()){
                for(auto it2 = cache.begin(); it2!=cache.end(); it2++){
                    if(*it+*it2==k){
                        ret++;
                    }
                    c += *it;//主要是这里 要每次更新保存的值。如果只存个前缀和就不需要更新了，也就不需要二重循环了
                }
            }
            if(*it==k){
                ret++;
            }
            cache.push_back(*it);
        }
        return ret;
    }
};
//抄
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};