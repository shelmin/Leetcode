//该题使用贪心算法，只要第二天价格比前一天高，即卖出；
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        
        for(int i =1;i<prices.size();i++){
            if(prices[i] > prices[i-1]){
                res = res + prices[i] - prices[i-1];
            }
        }
        
        return res;
    }
    
};
