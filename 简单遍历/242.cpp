//有待改进。。默认的哈希表肯定很大。还可以在原址上排序，比较排序后的结果
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> hashTableForS, hashTableForT;
        for(auto& i:s){
            hashTableForS.insert(i);
        }
        for(auto& i:t){
            hashTableForT.insert(i);
        }
        return (hashTableForS==hashTableForT);
    }
};