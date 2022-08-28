class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto& e:s){
            if(e=='('||e=='['||e=='{'){
                st.push(e);
            }else if(st.empty()){
                return false;
            }else{
                if((e==')' && st.top()=='(') || (e==']' && st.top()=='[') || (e=='}' && st.top()=='{')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};

class Solution {
public:
    int skip(vector<int>& nums, int& i, int target){
        int size=0;
        while(i<nums.size()&&nums[i]==target){
            size++;
            i++;
        }
        return size;
    }

    int find_end(vector<int>& nums, int& end, int k){
        skip(nums, end, 1);
        while(end!=nums.size()){
            int cur_end = end-1;
            int zero_size = skip(nums, end, 0);
            if(k<zero_size){
                end = cur_end;
                return zero_size; 
            }
            k-=zero_size;
            skip(nums, end, 1);
        }

    }

    int longestOnes(vector<int>& nums, int k) {
        int begin=0;
        int end=0;
        int zero_before_begin=0;
        int zero_after_end=0;

        zero_before_begin = skip(nums, begin, 0);

        if(zero_before_begin==nums.size()){
            return nums.size()>k?k:nums.size();
        }


        
    }
};