/*
2020.5.14
2020.5.29 虽然pass了，但是实际上没达到时间要求
二分查找前提：1.有序，2.一次判断能排除掉一半情况
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int>::iterator pNums1 = nums1.begin();
        vector<int>::iterator pNums2 = nums2.begin();
        while(pNums1!=nums1.end()||pNums2!=nums2.end()){
            if(pNums1==nums1.end()){
                result.push_back(*pNums2);
                pNums2++;
            }else if(pNums2==nums2.end()){
                result.push_back(*pNums1);
                pNums1++;                
            }else if(*pNums1<*pNums2){
                result.push_back(*pNums1);
                pNums1++;                  
            }else{
                result.push_back(*pNums2);
                pNums2++;                
            }
        }
        if(result.size()%2==1){
            return (double)result[result.size()/2];
        }else{
            return ((double)(result[result.size()/2-1]+result[result.size()/2]))/2.0;
        }
    }
};
