class Solution {
public:
//最后一组输入超时， 需要对比一下其他人的解法
    map<int, bool> m;
    int word_size = 0;

    void f(string& s, int i, multiset<string>& check_set, multiset<string>& word_set){
        if(m.find(i)==m.end()){
            m[i] = word_set.find(s.substr(i,word_size))!=word_set.end();
        }
        if(m[i]==true && check_set.find(s.substr(i,word_size))!=check_set.end()){
            cout<<"i: "<<i<<endl;
            check_set.erase(check_set.find(s.substr(i,word_size)));
            i+=word_size;
            f(s, i, check_set, word_set);
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        word_size = words[0].size();
        int total_size = word_size * words.size();
        vector<int> res;
        multiset<string> word_set;
        multiset<string> check_set;

        for(auto& st:words){
            word_set.insert(st);
        }

        for(int i=0; i<s.size()-total_size+1; i++){
            check_set = word_set;
            f(s, i, check_set, word_set);
            if(check_set.empty()){
                res.push_back(i);
            }
        }
        return res;
    }
};
//抄来的 总感觉跟我的差不多但是没超时
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res; // 结果
        unordered_map<string, int> search;
        for (auto &word : words) ++search[word]; // 参照物初始化
        int n = s.size(), m = words.size(), len = words[0].size(); // 获取隐藏变量
        for (int i = 0, j = 0; i < n - m * len + 1; ++i) { // 主逻辑
            unordered_map<string, int> sub; // 子字符 查找的中间结果
            for (j = 0; j < m; ++j) { // 子字符串查找逻辑
                auto word = s.substr(i + j * len, len); // 获取子串
                if (!search.count(word)) break; // 子串 不在 words 里面
                if (++sub[word] > search[word]) break; // 子串个数 比 words 多
            }
            if (j == m) res.push_back(i); // 完全匹配
        }
        return res;
    }
};