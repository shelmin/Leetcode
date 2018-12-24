//最先尝试了递归，拿到OJ上运行，显示Time Limit Exceeded，就是说运行时间超了，
//因为递归计算了很多分支，效率很低，这里需要用动态规划 (Dynamic Programming) 
//来提高效率


//递归：
class Solution {
public:
    int climb(int n, int &count) {
	if (n == 0) {
		count++;
		return count;
	}
	else if (n < 0) {
		return count;
	}
	else {
		climb(n - 1, count);
		climb(n - 2, count);
		return count;
	}
}
    int climbStairs(int n) {
        	int count = 0;
	climb(n - 1, count);
	climb(n - 2, count);
	return count;
    }
};

//动态规划：
class Solution {
public:
  int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < n; ++i) {
             dp[i] = dp[i - 1] + dp[i - 2];
         }
         return dp.back();
   }
};

//优化：
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--) {
            b += a;
            a = b - a;
        }
        return a;
    }
};
//引用博文：https://www.cnblogs.com/ariel-dreamland/p/9153960.html
