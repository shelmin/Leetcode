/*
**分为偶数基数两种情况讨论，该方法省空间不省时间
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;


string reverseString(string s) {
	int len = s.length();
	char temp;
	if (len % 2 == 1) {  //基数
		for (int i = 0; i < ((len-1) / 2) ; i++) {
			temp = s[len - 1 - i];
			s[len - 1 - i] = s[i];
			s[i] = temp;
		}
	}
	else {  //偶数
		for (int i = 0; i < (len / 2); i++) {
			temp = s[len - 1 - i];
			s[len - 1 - i] = s[i];
			s[i] = temp;
		}
	}
	return s;
}


int main() {
	string A = "helloo";
	cout<<reverseString(A)<<endl;
	system("pause");
	return 0;
}
