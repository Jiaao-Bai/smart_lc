class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string ret;
        int i = 0;
        int j = 0;
        ret.reserve(word1.size() + word2.size());

        while(ret.size() < (word1.size() + word2.size())) {
            if (i < word1.size()) {
                ret.push_back(word1[i]);
                i++;
            }
            if (j < word2.size()) {
                ret.push_back(word2[j]);
                j++;
            }
        }
        return ret;
    }
};