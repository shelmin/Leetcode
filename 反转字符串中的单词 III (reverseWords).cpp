/*
**reverseString函数用来翻转字符串中特定长度位置的字符，reverseWords函数找到空格点位置进行分割翻转
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

string reverseString(string s,int low,int high) {
	int len = high-low+1;
	char temp;
	if (len % 2 == 1) {
		for (int i = low; i < (low+((high-low)/2)); i++) {
			temp = s[high - (i - low)];
			s[high - (i - low)] = s[i];
			s[i] = temp;
		}
	}
	else {
		for (int i = low; i < (low+((high-low+1)/2)); i++) {
			temp = s[high - (i - low)];
			s[high - (i - low)] = s[i];
			s[i] = temp;
		}
	}
	return s;
}
string reverseWords(string s) {
	int len = s.length();
	vector<int> L;
	vector<int> H;
	L.push_back(0);
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			L.push_back(i+1);
			H.push_back(i-1);
		}
	}
	H.push_back(len - 1);

	for (int j = 0; j < L.size(); j++) {
		s = reverseString(s,L[j],H[j]);
	}
	return s;
}


int main() {
	string A = "Let's take LeetCode contest";
	cout << reverseWords(A) << endl;
//	cout << reverseString(A, 11, 18);
	system("pause");
	return 0;
}
