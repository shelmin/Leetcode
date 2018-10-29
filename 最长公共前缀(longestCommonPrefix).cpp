#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
string longestCommonPrefix(vector<string>& strs) {//目标函数
	if (strs.empty()) return "";
	if (strs.size() == 1) return strs[0];
	vector<int> length;
	for (vector<string>::iterator itr = strs.begin(); itr != strs.end(); itr++) {
		length.push_back((*itr).length());
		cout << *itr << endl;
		//cout << length[0] << endl;
	}
	//cout << length[4] << endl;
	auto minPosition = min_element(length.begin(), length.end());
	//cout << *length.begin();
	int min = length[minPosition - length.begin()];
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
