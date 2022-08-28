//有一个输入会超时
//并查集：元素分组管理，每两个元素可以判断是否在一个组中
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<set<int>> cache;
        string ret=s;
        for(auto& pair: pairs){
            int find0=-1, find1=-1;
            if(cache.empty()){
                cache.push_back(set<int>({pair[0], pair[1]}));
            }
            for(int i=0; i<cache.size(); i++){
                if(find0==-1 && cache[i].find(pair[0])!=cache[i].end()){
                    find0 = i;
                }
                if(find1==-1 && cache[i].find(pair[1])!=cache[i].end()){
                    find1 = i;
                }
                if(find0!=-1 && find1!=-1){
                    break;
                }
            }
            if(find0!=-1 && find1==-1){
                cache[find0].insert(pair[1]);
            }else if(find1!=-1 && find0==-1){
                cache[find1].insert(pair[0]);
            }else if(find1==-1 && find0==-1){
                cache.push_back(set<int>({pair[0], pair[1]}));
            }else{
                if(find0!=find1){
                    for(auto& e :cache[find1]){
                        cache[find0].insert(e);
                    }
                    //cache.erase(cache.begin()+find1);
                    cache[find1].clear();
                }
            }
        }/*
        for(auto& w:cache){
            string tmp="";
            vector<int> v;
            for(auto& q:w){
                v.push_back(q);
            }
            //sort(v.begin(), v.end());
            for(auto& e:v){
                tmp+=s[e];
            }
            sort(tmp.begin(), tmp.end());
            for(int i=0; i<v.size(); i++){
                ret[v[i]] = tmp[i];
            }
        }
        */
        for(auto& w:cache){
            if(w.empty()){
                continue;
            }
            string tmp="";

            for(auto& e:w){
                tmp+=s[e];
            }
            sort(tmp.begin(), tmp.end());
            int i=0;
            for(auto& e:w){
                ret[e] = tmp[i];
                i++;
            }
        }
        return ret;
    }
};