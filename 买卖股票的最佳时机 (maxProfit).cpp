// min用来维护数组中的最小值，max用来维护最大收益。只用一重循环
// 就完成了功能，这里使用min和max在一次遍历中更新的思想。
// 时间复杂度：O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() < 1) {
            return 0;
        }
        int max = 0;    
        int min = prices[0];
        for(int i = 0; i <prices.size() ; i++){
            if (prices[i] < min)
                min = prices[i];
            else{
                if(max < prices[i] - min)   
                max = prices[i] - min;
            }          
        }
        return max;    

    }
};
