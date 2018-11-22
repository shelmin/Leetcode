/*
**依旧对于数组要先考虑到排序的问题
*/
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void myquicksort(vector<int> &vec, int low, int high) { //快排，必须传引用,否则出错,因为vector是一个类对象
	if (low < high)
	{
		int l = low;
		int r = high;
		int key = vec[l];//记录key值

		while (l < r)
		{
			while (l < r&&key <= vec[r])//从右往左遍历,找到第一个小于key的元素
				--r;
			vec[l] = vec[r];
			while (l < r&&key >= vec[l])//从左往右遍历,找到第一个大于key值的元素
				++l;
			vec[r] = vec[l];
		}
		vec[l] = key;//其实此时l=r

		myquicksort(vec, low, l - 1);
		myquicksort(vec, r + 1, high);
	}
}

bool containsDuplicate(vector<int>& nums) {
	myquicksort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size()-1; i++) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}



int main() {
	vector<int> A = { 1,1,3,5,6 };
	cout << containsDuplicate(A) << endl;
	system("pause");
	return 0;
}
