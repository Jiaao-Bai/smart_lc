class Solution {
public:
    map<string, set<string>> m;
    set<string> searched;

    bool connected(string& a, string& b){           
        if(a.size()!=b.size()){
            return false;
        }else{
            int count = 0;
            for(int i=0; i<a.size(); i++){
                if(a[i]!=b[i]){
                    count++;
                }
            }
            return (count==1);
        }

    }
    
    void init_map(vector<string>& wordList, string beginWord){
        for(auto& w1:wordList){
            if(connected(w1,beginWord)){
                m[beginWord].insert(w1);
            }
            for(auto& w2:wordList){
                if(w1<=w2 && connected(w1,w2)){
                    m[w1].insert(w2);
                    m[w2].insert(w1);
                }
            }
        }
        
        cout<<"m size:  "<<m.size()<<endl;
        /*
        for(auto& p:m){
            cout<<"debug:  "<<p.second.size()<<endl;
        }
        */
    }
    vector<vector<string>> dsp(string word, int length, string target, vector<string>& wordList){
        vector<vector<string>> ret;
        if(length==2){
            if(connected(word, target)){
                ret.push_back({word, target});
            }
            return ret;
        }
        for(auto& w:m[word]){
            if(searched.find(w)==searched.end()){
                searched.insert(w);
                vector<vector<string>> res = dsp(w, length-1, target, wordList);
                if(!res.empty()){
                    for(auto& re:res){
                        re.insert(re.begin(), word);
                        ret.push_back(re);
                    }
                }
                searched.erase(w);
            }
        }
        return ret;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        queue<string> q;
        stack<string> st;
        int length=0;
        bool find = false;

        q.push(beginWord);
        s.insert(beginWord);
        init_map(wordList, beginWord);

        while(!q.empty()){
            int size = q.size();
            length++;
            while(size--){
                auto target = q.front();
                for(auto& w:m[target]){
                    if(s.find(w)==s.end()){
                        //cout<<"debug, target: "<<target<<", with: "<<w<<endl;
                        s.insert(w);
                        q.push(w);
                        if(w==endWord){
                            length++;
                            cout<<"find, length: "<<length<<endl;
                            find = true;
                            goto finded;
                        }
                    }
                }
                q.pop();
            }
        }
    
    finded:
        if(!find){
            return vector<vector<string>>();
        }
        cout<<"done"<<endl;
        return dsp(beginWord, length, endWord, wordList);
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        // 修改以后看一下，如果根本就不在 dict 里面，跳过
        if (dict.find(endWord) == dict.end()) {
            return res;
        }
        // 特殊用例处理
        dict.erase(beginWord);

        // 第 1 步：广度优先遍历建图
        // 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先遍历的第几层
        unordered_map<string, int> steps = {{beginWord, 0}};
        // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        unordered_map<string, set<string>> from = {{beginWord, {}}};
        int step = 0;
        bool found = false;
        queue<string> q = queue<string>{{beginWord}};
        int wordLen = beginWord.length();
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const string currWord = move(q.front());
                string nextWord = currWord;
                q.pop();
                // 将每一位替换成 26 个小写英文字母
                for (int j = 0; j < wordLen; ++j) {
                    const char origin = nextWord[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(currWord);
                        }
                        if (dict.find(nextWord) == dict.end()) {
                            continue;
                        }
                        // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到，且距离更远的单词，需要将它从 dict 中删除
                        dict.erase(nextWord);
                        // 这一层扩展出的单词进入队列
                        q.push(nextWord);
                        // 记录 nextWord 从 currWord 而来
                        from[nextWord].insert(currWord);
                        // 记录 nextWord 的 step
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                    nextWord[j] = origin;
                }
            }
            if (found) {
                break;
            }
        }
        // 第 2 步：深度优先遍历找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
        if (found) {
            vector<string> Path = {endWord};
            dfs(res, endWord, from, Path);
        }
        return res;
    }

    void dfs(vector<vector<string>> &res, const string &Node, unordered_map<string, set<string>> &from,
             vector<string> &path) {
        if (from[Node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string &Parent: from[Node]) {
            path.push_back(Parent);
            dfs(res, Parent, from, path);
            path.pop_back();
        }
    }
};