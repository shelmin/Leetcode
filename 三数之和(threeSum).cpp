#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
//拿到一串数字可以先想到排序
//快排？归并排序？冒泡?...

void myquicksort(vector<int> &vec, int low, int high){ //快排，必须传引用,否则出错,因为vector是一个类对象
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
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> re;
	if (nums.empty()) return re;
	myquicksort(nums, 0, nums.size()-1);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}

	
	vector<int> temp;
	if (nums[0] > 0) return re; //最小数大于0
	if (nums[0] == 0 && nums[1] > 0) return re;//最小数等于0，次小数大于0
	if (nums[0] == 0 && nums[1] == 0 && nums[2] > 0) return re;//最小数等于0，次小数等于0，次次小数大于0
	if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0) { re.push_back({ 0,0,0 }); return re; }

	vector<int>::iterator itr0;
	bool flag = 0;
	for (vector<int>::iterator itr = nums.begin(); itr != nums.end()-1; itr++) {
		if (*itr <= 0 && *(itr + 1) >= 0) { itr0 = itr; flag = 1; break; }
	};
	if (flag == 0) return re;
	if ((nums.end() - itr0) > 3 && *(itr0 + 3) == 0 && *(itr0 + 1) == 0 && *(itr0 + 2) == 0) re.push_back({ 0,0,0 });
	for (vector<int>::iterator itr = nums.begin(); itr != itr0 + 1; itr++) {
		flag = 0;
		vector<int>::iterator low = itr + 1;
		if (itr != nums.begin()) {
			if (*itr == *(itr - 1)) {
				continue;
			}
		}
		vector<int>::iterator high = nums.end()-1;
		while ( high != low) {
			if ((*high + *low) == (-*itr)) { 
				re.push_back({ *itr,*low,*high }); 
				low = low + 1;
				if (high == low) { break; }
				while (*low == *(low - 1)) { 
					low = low + 1; 
					if (high == low) {  break; }
				} 
				if (high == low) { break; }
				continue; 
			}
			if ((*high + *low) > (-*itr)) { 
				high = high - 1;
				if (high == low) { break; }
				while (*high == *(high + 1)) { 
					high = high - 1; 
					if (high == low) {  break; }
			} 
				if (high == low) { break; }
				continue; 
			}
			if ((*high + *low) < (-*itr)) {
				low = low + 1;
				if (high == low) { break; }
				while (*low == *(low - 1)) { 
					low = low + 1; 
					if (high == low) {  break; }
			}
				if (high == low) { break; }
				continue; 
			}
		}

	}
	

	return re;
}

int main() {
	vector<int> nums = { -4,-2,-1 }; //排序后是-4 -1 -1 0 1 2
	vector<vector<int>> re = threeSum(nums);
	for (int i = 0; i < re.size(); i++){
		for (int j = 0; j < re[i].size(); j++) {
			cout << re[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

