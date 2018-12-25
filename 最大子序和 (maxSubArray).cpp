//第一次采用递归的方法，时间复杂度太高，还差几个用例通过不了，代码如下
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <numeric>


using namespace std;

int findMax(vector<int> vec) {
	int max = INT_MIN;
	for (auto v : vec) {
		if (max < v) max = v;
	}
	return max;
}

void sumn(vector<int>::iterator it1, vector<int>::iterator it2,int &sum) {
	if ((it2 - it1) == 0) {
		return;
	}
	int temp=accumulate(it1,it2, 0);
	if (sum < temp) {
		sum = temp;
	}
	sumn(it1 + 1, it2, sum);
	sumn(it1, it2 - 1, sum);
	
}

int maxSubArray(vector<int>& nums) {
//	int max = findMax(nums);
	int summ = INT_MIN;
	sumn(nums.begin(), nums.end(), summ);
	return summ;
}  


int main() {
	vector<int> i = { -84,-87,-78,-16,-94,-36,-87,-93,-50,-22,-63,-28,-91,-60,-64,-27,-41,-27,-73,-37,-12,-69,-68,-30,-83,-31,-63,-24,-68,-36,-30,-3,-23,-59,-70,-68,-94,-57,-12,-43,-30,-74,-22,-20,-85,-38,-99,-25,-16,-71,-14,-27,-92,-81,-57,-74,-63,-71,-97,-82,-6,-26,-85,-28,-37,-6,-47,-30,-14,-58,-25,-96,-83,-46,-15,-68,-35,-65,-44,-51,-88,-9,-77,-79,-89,-85,-4,-52,-55,-100,-33,-61,-77,-69,-40,-13,-27,-87,-95,-40 };
	cout << maxSubArray(i) << endl;
	//cout << accumulate(i.begin()+7, i.end()-2,0);
	system("pause");
	return 0;
}

/* 
 ** 之后借鉴网上动态规划的算法：设sum[i]为以第i个元素结尾且和最大的连续子数组。假设对于元素i，
 ** 所有以它前面的元素结尾的子数组的长度都已经求得，那么以第i个元素结尾且和最大的连续子数组实际上，
 ** 要么是以第i-1个元素结尾且和最大的连续子数组加上这个元素，要么是只包含第i个元素，即sum[i] = 
 ** max(sum[i-1] + a[i], a[i])。可以通过判断sum[i-1] + a[i]是否大于a[i]来做选择，而这实际上
 ** 等价于判断sum[i-1]是否大于0。由于每次运算只需要前一次的结果，因此并不需要像普通的动态规划
 ** 那样保留之前所有的计算结果，只需要保留上一次的即可，因此算法的时间和空间复杂度都很小
*/
#include <numeric>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        	
        int ans = 0, maxn = INT_MIN;  
        int len = nums.size();
        for(int i = 0; i < len; i++){  
            if(ans < 0) ans = 0;  //如果前面的和小0，那么重新开始求和
            ans += nums[i];  
            maxn = max(maxn, ans);   
        }  
        return maxn;

    }
};

//分治算法参阅博客：https://blog.csdn.net/qq_33168253/article/details/79775107
