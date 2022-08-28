Description
平面上给 N 个点，要求找到三个点构成一个三角形，使得其他点都在这个三角形之外（也不能落在边上）。保证所有点不在一条线上。
//第一反应是三重循环
struct Point{
  float x=0.0;
  float y=0.0;
};
//点在线段上
bool on_line(Point a, Point b, Point c){

}

//a->b cross 0->d
bool cross(Point a, Point b, Point d){
  if(b.x-a.x==0){
  	//竖直
    if(d.x==0){
    	return false;
    }
    float k = d.y/d.x;
    Point c;
    c.x = b.x;
    c.y = k*b.x;
    return on_line(a, b, c);
  }
	float k = (b.y-a.y)/(b.x-a.x);
  
}


bool inside(Point a, Point b, Point c, Point d){
	int cross_times=0;
  
  if(cross(a,b,d)){
  	cross_times++;
  }
  if(cross(a,c,d)){
  	cross_times++;
  }
  if(cross(c,b,d)){
  	cross_times++;
  }
  return (cross_times==1)?(true):(false);
}

inline bool pal(Point a, Point b, Point c){
	auto ab_x = b.x-a.x;
  auto ab_y = b.y-a.y;
	auto ac_x = c.x-a.x;
  auto ac_y = c.y-a.y;
  return ab_x*ac_y == ab_y*ac_x;
}

std::vector<Point> find(std::vector<Point> input){
		//std::set<Point> set_;
    std::vector<Point> ret;
  
  	if(input.size()<3){
      return ret;
    }
    
    Point point_a = input[0];
  	Point point_b = input[1];
  	Point point_c = input.begin();
  	bool find = false;
    
  
  	for(auto it=input.begin()+2; it!=input.end(); it++){
    	if(!pal(a,b,*it)){
        //find
      	point_c = *it;
        find = true;
        break;
      }
    }
  	
  	if(find){
    	for(auto it=input.begin()+2; it!=input.end(); it++){
      	if(inside(point_a, point_b, point_c， *it)){
          //考虑下在边上和重复点
          point_a = *it;
        }
      }
      ret.push_back(point_a);
      ret.push_back(point_b);
      ret.push_back(point_c);
    }
  	return ret;
}