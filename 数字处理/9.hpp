class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> normal, revert;

        if(x<0){
            return false;
        }

        if(x==0){
            return true;
        }

        while(x!=0){
            revert.push_back(x%10);
            x = x/10;
        }

        for(auto it = revert.rbegin(); it!= revert.rend(); it++){
            normal.push_back(*it);
        }

        auto it = revert.begin();
        while(*it==0 && it!=revert.end()){
            revert.erase(it);
        }

        return normal==revert;
    }
};