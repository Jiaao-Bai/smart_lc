class Solution {
public:
    bool check(string str1, string str2) {
        // std::cout << str1 << ", " << str2 << std::endl;
        int begin = 0;
        while (begin < str2.size()){
            if (str1 != str2.substr(begin, str1.size())) {
                return false;
            }
            begin += str1.size();
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        string ret;
        if (str1.size() == 0 || str2.size() == 0) {
            return ret;
        }

        int len = str1.size() < str2.size() ? str1.size() : str2.size();
        for (int i=1; i<=len; i++) {
            if (str1.size() % i == 0 && str2.size() % i == 0) {
                if (check(str1.substr(0, i), str1) && check(str1.substr(0, i), str2)) {
                    ret = str1.substr(0, i);
                }
            }
        }
        return ret;
    }
};