/***************************************************
//递归方法，一如既往的超时了。。。
void unique(int m, int n, int &count) {
	if (m == 0 || n == 0) {
		count++;
		return;
	}
	if (m > 0 && n > 0) {
		unique(m-1, n, count);
		unique(m, n-1, count);
	}
	if (m == 0 && n == 0) {
		return;
	}
}

int uniquePaths(int m, int n) {
	int count = 0;
	m--;
	n--;
	unique(m, n, count);
	return count;
}
****************************************************/
// 动态规划Dynamic Programming：我们维护一个二维数组dp，其
// 中dp[i][j]表示到当前位置不同的走法的个数，然后可以得到递
// 推式为: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，这里
// 为了节省空间，我们使用一维数组dp，一行一行的刷新也可以，
// 代码如下：
// 借用博客：http://www.cnblogs.com/grandyang/p/4353555.html
// 以下是该算法的一维数组 dp 刷新过程，容易理解该算法
//  1
//  1   2   3   4   5   6   7
//  1   3   6   10  15  21  28
class Solution {
public:
int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
}
};

/***************************************************
// 组合方法：
// 借用博客：http://www.cnblogs.com/grandyang/p/4353555.html
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom);
    }
};
