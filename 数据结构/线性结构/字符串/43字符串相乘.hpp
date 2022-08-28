class Solution {
public:
    //amd1面 待调试
    string sum(string input1, string input2){
        cout<<"----- "<<input1<<" -- "<<input2<<endl;
        int max = input1.size()>input2.size()?input1.size():input2.size();
        int i1, i2;
        int carry = 0;
        string res;
        string ret;
        
        //逆序
        //max = 3
        for(int i=0; i<max; i++){   
            int val = 0;
            cout<<"val: "<<val<<endl;
            i1 = input1.size()-i-1; //2,1,0
            i2 = input2.size()-i-1; //1,0,-1
            if(i1>=0){
                cout<<"val: "<<val<<endl;
                val += (input1[i1]-'0');
            }
            if(i2>=0){
                cout<<"val: "<<val<<endl;
                val += (input2[i2]-'0');
            }
            val += carry;
            if(val>9){
                carry = val/10;
                val  = val%10;
            }
            res.push_back(val+'0');
        }
        if(carry!=0){
            res.push_back(carry+'0');
        }
        for(auto&e: res){
            ret.push_back(e);
        }
        return ret;
    }

    string multiply(string num1, string num2) {
        cout<<num1<<" -- "<<num2<<endl;
        string res;

        if(num1.empty()||num2.empty()){
            return res;
        }

        string a, c;
        int b = num1.back()-'0', d = num2.back()-'0';

        if(num1.size()>1){
            a = num1;
            a.pop_back();
        }
        if(num2.size()>1){
            c = num2;
            c.pop_back();
        }
        //a = [12] b=3
        //c= [empty] d=9

        //100ac+10bc+10ad+bd

        //bd
        int r1 = b*d; //27
        string v1 = to_string(r1);
        res = sum(res , v1);
        //res = [2 7]

        //10ad
        char c_d = d+'0';
        string v_d  = {c_d};//
        v1 = multiply(a, v_d);//[12] *[9]
        v1.push_back(0);//[1 0 8 0]
        res = sum(res , v1);//[1 1 0 7]
        //10bc
        char c_b = b+'0';
        string v_b  = {c_b};
        v1 = multiply(c, v_b);
        v1.push_back(0);
        res = sum(res , v1);  

        //100ac
        v1 = multiply(c, a);
        v1.push_back(0);
        v1.push_back(0);
        res = sum(res , v1);

        return res;
    }
};