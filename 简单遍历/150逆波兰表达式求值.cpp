/*
2019微软1面
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& s: tokens){
            if(s=="+"){
                auto op1 = st.top();
                st.pop();
                auto op2 = st.top();
                st.pop();
                st.push(op1+op2);
            }else if(s=="-"){
                auto op1 = st.top();
                st.pop();
                auto op2 = st.top();
                st.pop();
                st.push(op2-op1);
            }else if(s=="*"){
                auto op1 = st.top();
                st.pop();
                auto op2 = st.top();
                st.pop();
                st.push(op1*op2);
            }else if(s=="/"){
                auto op1 = st.top();
                st.pop();
                auto op2 = st.top();
                st.pop();
                st.push(op2/op1);
            }else{
                //a num
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};