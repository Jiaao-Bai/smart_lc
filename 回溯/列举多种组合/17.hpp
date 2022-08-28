class Solution {
public:
    std::map<char, std::set<std::string>>  map_ = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };
    //回溯，部分情况可以和多重循环转换
    backTrack(){
        if(){
            backTrack()
        }else if(){
            backTrack()
        }else{
            backTrack()
        }
        return
    }
    vector<string> letterCombinations(string digits) {
        std::vector<string> old_one, new_one;
        for(auto& c: digits){
            if(old_one.empty()){
                for(auto& s: map_[c]){
                    old_one.push_back(s);
                }
            }else{
                for(auto& res :old_one){
                    for(auto& s: map_[c]){
                        new_one.push_back(res+s);
                    }
                }
                //old_one.clear();
                //old_one.swap(new_one);
                old_one = new_one;
                new_one.clear();
            }
        }
        return old_one;
    }
};