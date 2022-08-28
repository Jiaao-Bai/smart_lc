/*
微软2021年四面，类似的题
vector<string> process(map<string, set<string>> input){
  set<string> processed_str;
  stack<string> s;
  set<string> all_node; //一共有多少节点
  vector<string> ret;
  
  for(auto& p:input){
    all_node.insert(p.first);
    for(auto& e:p.second){
      all_node.insert(e);
    }
  }
  //all_node = {ABCDEFG}
  if(all_node.empty()){
    return;
  }
  
  for(auto& e:all_node){
    s.push(e);
  }
  //s=ABCDEF
  while(!s.empty()){
    auto e = s.top(); //e=F
    if(processed_str.find(e)!=processed_str.end()){//not find
      s.pop();
      continue;
    }
    if(input.find(e)==input.end()){//true
      //no depent node
      ret.push_back(e); //ret=FEDBG
      processed_str.insert(e);//processed_str =FEDBG
      s.pop();//
      continue;
    }
    for(auto& d:input[e]){ //d=B
      if(processed_str.count(d)==0){ //
        s.push(d);
      }
    }
    if(s.top()==e){ // s.top=G,
      ret.push_back(e); //ret = 
      processed_str.insert(e);//processed_str =
      s.pop();//s is empty reture
    }
  }
  return ret;
}
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> m;
        stack<int> s;
        set<int> todo_set;
        set<int> processed_course;
        vector<int> ret;
        set<int> processing;

        for(auto& v: prerequisites){
            m[v[0]].insert(v[1]);
            todo_set.insert(v[0]);
        }

        for(auto& e:todo_set){
            s.push(e);
        }

        while(!s.empty()){
            auto e = s.top();
            if(processed_course.find(e)!=processed_course.end()){
                s.pop();
                continue;
            }
            if(m.find(e)==m.end()){
                //no depent node
                ret.push_back(e); //ret=FEDBG
                processed_course.insert(e);//processed_str =FEDBG
                s.pop();
                continue;
            }

            processing.insert(e);

            for(auto& d:m[e]){ //d=B
                if(processed_course.find(d)==processed_course.end()){ //
                    s.push(d);
                    if(processing.find(d)!=processing.end()){
                        ret.clear();
                        return ret;
                    }
                }
            }
            if(s.top()==e){ // s.top=G,
                ret.push_back(e); //ret = 
                processed_course.insert(e);//processed_str =
                s.pop();//s is empty reture
                processing.erase(e);
            }
        }

        for(int i=0; i<numCourses; i++){
            if(processed_course.find(i)==processed_course.end()){
                ret.push_back(i);
            }
        }
        return ret;
    }
};

