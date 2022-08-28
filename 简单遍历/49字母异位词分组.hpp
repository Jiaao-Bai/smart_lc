class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> strMap;
        vector<vector<string>> res;
        for(auto& s: strs){
            string t = s;
            sort(t.begin(), t.end());
            auto it = strMap.find(t);
            if(it==strMap.end()){
                vector<string> v;
                v.push_back(s);
                res.push_back(v);
                strMap[t] = res.size()-1;
            }else{
                res[strMap[t]].push_back(s);
            }
        }
        return res;
    }
};