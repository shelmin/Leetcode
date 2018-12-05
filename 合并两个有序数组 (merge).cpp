/*
**合并两个数组，数组1后面有很多0位是没用的，最后合并完还得去掉，真是坑
*/
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (n == 0) {//如果数组2为空，数组1没有元素需要加入，直接返回
		return;  
	}
	if (m == 0) {//如果数组1为空，直接把数组2加入之后把0去掉返回
		for (int i = 0; i < nums2.size(); i++)
		{
			nums1.insert(nums1.begin() + i, nums2[i]);
		}
		for (int i = m; i < nums1.size(); i++) {
			nums1.pop_back();
		}
		return;
	}
	int i = 0;//标定数组1的位置
	int j = 0;//标定数组2的位置
	while (i < m&&j < n) {//进行比较插入
		if (nums1[i] >= nums2[j]) {
			nums1.insert(nums1.begin() + i, nums2[j]);
			m++;
			i++;
			j++;
		}
		else {
			i++;
		}
	}

	if (i == m) {//如果数组1插到头了再用一个while插入剩下的数组2的元素
		while (j < n) {
			if (nums1[i-1] >= nums2[j]) {
				nums1.insert(nums1.begin() + i-1, nums2[j]);
				m++;
				i++;
				j++;
			}
			else {
				nums1.insert(nums1.begin() + i, nums2[j]);
				m++;
				i++;
				j++;
			}
		}
	}

	int len = nums1.size();
	for (int i = m; i < len; i++) {//去掉尾部的0
		nums1.pop_back();
	}
}

int main() {
	vector<int> A = { 1,2,3,0,0,0 };
	vector<int> B = { 2,5,6 };
	merge(A,3,B,3);
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}
	system("pause");
	return 0;
}
