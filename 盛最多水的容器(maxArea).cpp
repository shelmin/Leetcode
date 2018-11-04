//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//说明：你不能倾斜容器，且 n 的值至少为 2。

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

//一个简单的双重循环从头和尾向内收缩寻找最大面积。
int maxArea(vector<int>& height) {
	if (height.empty()) return 0;
	int sum=0;
	int len = height.size();
	for (int i = 0; i < len; i++) {  //i为头
		for (int j = len - 1; j > i; j--) {  //j为尾
			if (abs(i - j)*(min(height[i], height[j])) > sum) sum = abs(i - j)*(min(height[i], height[j]));
		}
	}
	return sum;
}

int main() {
	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	cout << maxArea(nums) << endl;
	system("pause");
	return 0;
}
