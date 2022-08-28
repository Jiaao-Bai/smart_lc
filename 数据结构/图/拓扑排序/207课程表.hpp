class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()){
            return true;
        }
        map<int, set<int>> course_map;
        set<int>    not_finish;
        set<int>    wait;
        stack<int>  s;

        for(auto& v:prerequisites){
            course_map[v[0]].insert(v[1]);
            not_finish.insert(v[0]);
        }

        while(!not_finish.empty()){
            //not_finish可以保证越来越小
            if(s.empty()){
                s.push(*not_finish.begin());
            }
            auto course = s.top();
            wait.insert(course);

            if(not_finish.find(course)!=not_finish.end()){
                for(auto& dep:course_map[course]){
                    if(not_finish.find(dep)!=not_finish.end()){
                        s.push(dep);
                        if(wait.find(dep)!=wait.end()){
                            return false;
                        }
                    }
                }
            }
            if(course==s.top()){
                s.pop();
                not_finish.erase(course);
                wait.erase(course);
            }
        }

        return true;
    }
};