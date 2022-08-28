//动态规划 用回溯也可以
class Solution {
public:
    typedef std::map<int, vector<string>> Map;

    vector<string> generate(int n, Map& map1, Map& map2){
        if(map2.find(n)!=map2.end()){
            return map2[n];
        }
        vector<string> ret;
        auto r = generateParenthesisWithMap(n-1, map1, map2);
        for(auto& s: r){
            ret.push_back("("+s+")");
        }
        map2[n] = ret;
        return std::move(ret);
    }

    vector<string> generateParenthesisWithMap(int n, Map& map1, Map& map2){
        if(map1.find(n)!=map1.end()){
            return map1[n];
        }

        vector<string> ret;
        auto r = generate(n, map1, map2);
        ret.insert(ret.end(), r.begin(), r.end());
        for(int i=1; i<n; i++){
            std::vector<string> left = generate(i, map1, map2);
            std::vector<string> right = generateParenthesisWithMap(n-i, map1, map2);
            for(auto& ls:left){
                for(auto& rs:right){
                    auto result = ls+rs;
                    ret.push_back(result);
                }
            }
        }
        return std::move(ret);
    }

    vector<string> generateParenthesis(int n) {
        Map map1, map2;
        map1[1] = {"()"};
        map2[1] = {"()"};
        return std::move(generateParenthesisWithMap(n, map1, map2));
    }
};