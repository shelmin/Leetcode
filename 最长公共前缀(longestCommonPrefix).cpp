#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
string longestCommonPrefix(vector<string>& strs) {//目标函数
	if (strs.empty()) return "";  //当输入为指针类的类型时，需要时刻记得讨论空串的情况，不然容易出现指针越界等的报错
	if (strs.size() == 1) return strs[0]; //输入只有一个字符串
	vector<int> length;  //保存每个字符的长度
	for (vector<string>::iterator itr = strs.begin(); itr != strs.end(); itr++) {
		length.push_back((*itr).length());
		cout << *itr << endl;
		//cout << length[0] << endl;
	}
	//cout << length[4] << endl;
	auto minPosition = min_element(length.begin(), length.end());
	//cout << *length.begin();
	int min = length[minPosition - length.begin()];  //保存strs 的最短字符的长度
	cout << min << endl;
	string comStr;
	bool flag = 0;
	//cout << *(strs.end()-1) << endl;
	for (int i = 0; i < min; i++) {
		for (vector<string>::iterator itr = strs.begin(); itr != (strs.end() - 1); itr++) {
			vector<string>::iterator itr2 = itr + 1;
			char a = (*itr).at(i);
			char b = (*itr2).at(i);
			if (a == b) {
				//cout << (*itr)[0];
				//cout << (*(++itr));
				if (itr == (strs.end() - 2)) {
					comStr.push_back((*itr)[i]); cout << comStr << endl;  break;
				}
				else continue;
			}
			else flag = 1; break;
		}
		if (flag == 1) break;
	}
	if (comStr.empty()) comStr = " ";  cout << comStr << endl;  return " ";
	cout << comStr << endl;


	return comStr;
}

int main() {
	vector<string> A = { };
	longestCommonPrefix(A);
	system("pause");
	return 0;
}
