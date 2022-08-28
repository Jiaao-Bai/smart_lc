class Solution {
    //低效
public:
    map<string, map<string, int>> cache_;
    int minDistance(string word1, string word2) {
        if(cache_.find(word1)!=cache_.end()){
            if(cache_[word1].find(word2)!=cache_[word1].end()){
                return cache_[word1][word2];
            }
        }
        if(word1.empty()){
            return word2.size();
        }
        if(word2.empty()){
            return word1.size();
        }

        string word1_sub = word1.substr(1, word1.size()-1);
        string word2_sub = word2.substr(1, word2.size()-1);

        if(word1.front()==word2.front()){
            return minDistance(word1_sub, word2_sub);
        }

        //delete
        auto delete_res = minDistance(word1_sub, word2)+1;

        //insert
        auto insert_res = minDistance(word1, word2_sub)+1;

        //replace
        auto replace_res = minDistance(word1_sub, word2_sub)+1;

        auto res = std::min(delete_res, insert_res);
        res = std::min(res, replace_res);

        cache_[word1][word2]=res;
        return res;
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()){
            return word2.size();
        }
        if(word2.empty()){
            return word1.size();
        }
        int word1_length = word1.length();
        int word2_length = word2.length();
        int a[word1_length+1][word2_length+1];
        int res=0;
        int remove, insert, replace;
        for(int i=0; i<=word1_length; i++){
            a[i][0] = i;
        }
        for(int i=0; i<=word2_length; i++){
            a[0][i] = i;
        }
        for(int i=1; i<=word1_length; i++){
            for(int j=1; j<=word2_length; j++){
                if(word1[i-1]==word2[j-1]){
                    replace = a[i-1][j-1];
                }else{
                    replace = a[i-1][j-1]+1;
                }
                remove = a[i-1][j]+1;
                insert = a[i][j-1]+1;
                res = min(remove, insert);
                res = min(replace, res);
                a[i][j]=res;
            }
        }
        return a[word1_length][word2_length];
    }
};