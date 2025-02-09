class Solution {
public:
    int numTilings(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        std::vector<int64_t> res(n+1, 0);
        std::vector<int64_t> res_up(n+1, 0);
        std::vector<int64_t> res_down(n+1, 0);
        
        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i<=n; i++){
            //std::cout << "i: " << i << std::endl;
            res[i] = res[i-1] + res[i-2] + res_up[i-1] + res_down[i-1];
            res_up[i] = res_down[i-1] + res[i-2];
            res_down[i] = res_up[i-1] + res[i-2];
        }

        return int(res[n] % (10^9));
    }
};