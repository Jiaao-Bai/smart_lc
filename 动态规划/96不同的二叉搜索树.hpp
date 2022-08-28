class Solution {
public:
    int numTrees(int n) {
        int a[n+1];
        a[0]=1;
        a[1]=1;
        for(int i=2; i<=n; i++){
            int res=0;
            for(int j=0; j<=i-1; j++){
                res+=a[j]*a[i-1-j];
            }
            a[i] = res;
        }
        return a[n];
    }
};