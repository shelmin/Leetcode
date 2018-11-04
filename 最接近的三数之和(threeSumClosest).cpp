//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//例如，给定数组 nums = [-1，2，1， - 4], 和 target = 1.
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

//最简单的三重循环，只用注意不要越界
        // 或者也可以通过外层循环先确定一个数，之后双指针扫描数组右边剩下的数，对于每次找到的两个数，
        // 通过这 3 个数的和来更新结果，以后再实现
        // 转自博客 https://blog.csdn.net/hacker_zhidian/article/details/80257080
int threeSumClosest(vector<int>& nums, int target) {
	int near_sum = 9999;
	for (vector<int>::iterator itr1 = nums.begin(); itr1 != nums.end()-2; itr1++) {
		for (vector<int>::iterator itr2 = itr1+1; itr2 != nums.end()-1; itr2++) {
			for (vector<int>::iterator itr3 = itr2+1; itr3 != nums.end(); itr3++) {
				if (abs((*itr1 + *itr2 + *itr3) - target) < abs(near_sum-target)) {
					near_sum = *itr1 + *itr2 + *itr3;
				}
			}
		}
	}
	return near_sum;
}

int main() {
	vector<int> nums = { 1,1,-1,-1,3 };
	int target = 3;
	cout << threeSumClosest(nums, target) << endl;
	system("pause");
	return 0;
}
