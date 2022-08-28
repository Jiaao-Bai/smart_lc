class Solution {
public:
    string reverseWords(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        auto it1 = s.begin();
        auto it2 = s.begin();
        bool allow_space = false;
        while(it1!=s.end()){
            if(*it1==' '){
                if(!allow_space){
                    it1++;
                }else{
                    *it2 = *it1;
                    it1++;
                    it2++;
                    allow_space = false;
                }
            }else{
                *it2 = *it1;
                it2++;
                it1++;
                allow_space = true;
            }
        }
        if(*(it2-1)==' '){
            it2--;
        }
        s.erase(it2, s.end());
        it1 = s.begin();
        it2 = s.begin();
        stack<char> char_stack;
        while(it1!=s.end()){
            if(*it1!=' '){
                char_stack.push(*it1);
                it1++;
            }else{
                while(!char_stack.empty()){
                    *it2 = char_stack.top();
                    it2++;
                    char_stack.pop();
                }
                it2++;
                it1++;
            }
        }
        while(!char_stack.empty()){
            *it2 = char_stack.top();
            it2++;
            char_stack.pop();
        }
        return s;
    }   
};