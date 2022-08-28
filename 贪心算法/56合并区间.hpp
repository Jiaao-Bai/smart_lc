/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, pair<int, int>> m;
        vector<vector<int>> ret;
        vector<int> current;
        int left = 0;

        for(auto& v: intervals){
            if(m.find(v[0])==m.end()){
                m[v[0]] = make_pair(1, 0);
            }else{
                m[v[0]].first += 1;
            }
            if(m.find(v[1])==m.end()){
                m[v[1]] = make_pair(0, 1);
            }else{
                m[v[1]].second += 1;
            }
        }

        for(auto& p:m){
            while(p.second.first>0){
                if(left==0){
                    if(current.size()==0){
                        current.push_back(p.first);
                    }else if(current.size()==2){
                        ret.push_back(current);
                        current.clear();
                        current.push_back(p.first);
                    }
                }
                p.second.first--;
                left++;
            }
            while(p.second.second>0){
                if(current.size()==1){
                    current.push_back(p.first);
                }else if(current.size()==2){
                    current[1] = p.first;
                }
                p.second.second--;
                left--;
            }
        }
        if(!current.empty()){
            ret.push_back(current);
        }
        return ret;
    }
};
*/

class Solution {
public:
    //贪心算法，迭代过程中寻找当前的最优解而非全局最优解
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ret;
        if(intervals.empty()){
            return ret;
        }
        sort(intervals.begin(), intervals.end());
        int begin = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][1]>end){
                if(intervals[i][0]<=end){
                    end = intervals[i][1];
                }else{
                    vector<int> res{begin, end};
                    ret.push_back(res);
                    begin = intervals[i][0];
                    end = intervals[i][1];
                }
            }
        }
        vector<int> res{begin, end};
        ret.push_back(res);
        return ret;
    }
};