class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ret;
        if(s.size()==1){
            ret.push_back(s);
            return ret;
        }

        auto i=s.begin(), j=s.begin()+1;

        auto sub_ret = permutation(string(j, s.end()));
        for(auto& e:sub_ret){
            string c;
            c.push_back(*i);
            ret.push_back(c+e);
        }
        
        while(j!=s.end()){
            if(*j==*i){
                i++;
                j++;
                continue;
            }
            auto sub_s = string(s.begin(), j)+string(j+1, s.end());
            auto sub_ret = permutation(sub_s);
            for(auto& e:sub_ret){
                string c;
                c.push_back(*j);
                ret.push_back(c+e);
            }
            i++;
            j++;
        }
        return ret;
    }
};