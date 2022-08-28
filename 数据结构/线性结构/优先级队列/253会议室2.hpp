class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        multiset<int> begin_times;
        multiset<int> end_times;
        int max=0;
        int cur=0;
        for(auto& e: intervals){
            begin_times.insert(e[0]);
            end_times.insert(e[1]);
        }

        auto itb=begin_times.begin();
        auto ite=end_times.begin();

        while(itb!=begin_times.end()){
            if(*itb<*ite){
                cur++;
                itb++;
                max = (cur>max)?cur:max;
            }else if(*itb==*ite){
                itb++;
                ite++;
            }else{
                ite++;
                cur--; 
            }
        }
        return max;
    }
};