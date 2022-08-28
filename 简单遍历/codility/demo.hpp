/*


This is a demo task.

Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].


*/
#include <set>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> positive_set;
    int positive_num_size = 0;
    for(auto& e: A){
        if(e>0){
            positive_set.insert(e);
            positive_num_size++;
        }
    }
    for(int i=1; i<=positive_num_size+1; i++){
        if(positive_set.find(i)==positive_set.end()){
            return i;
        }
    }
    return 0;
}
