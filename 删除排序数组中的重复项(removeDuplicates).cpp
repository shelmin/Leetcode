//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;
//该题规定使用原地算法,我使用一个index,一个temp 各自保存需要对比的元素的索引和大小。效率高且空间复杂度极低。
int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int temp = 0;
	temp = nums[0];
	int index = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != temp ) {
			nums[index + 1] = nums[i];   //元素前移
			index++;    //索引加一
			temp = nums[i];  //大小更新
		}
	}
	return index+1;   //最后有效大小为index+1
}

int main() {
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
	cout << removeDuplicates(nums) << endl;
	system("pause");
	return 0;
}
