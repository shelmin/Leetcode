/*
**转自https://www.cnblogs.com/grandyang/p/4395356.html
**这道题让我们求两个字符串数字的相乘，输入的两个数和返回的数都是以字符串格式储存的，
**这样做的原因可能是这样可以计算超大数相乘，可以不受int或long的数值范围的约束，那么
**我们该如何来计算乘法呢，我们小时候都学过多位数的乘法过程，都是每位相乘然后错位相加，
**那么这里就是用到这种方法，把错位相加后的结果保存到一个一维数组中，然后分别每位上算
**进位，最后每个数字都变成一位，然后要做的是去除掉首位0，最后把每位上的数字按顺序保存
**到结果中即可，代码如下：
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
/*
**c与c++中长整型，浮点型，double型等的表示方法,以及最大位数
*/
using namespace std;

string multiply(string num1, string num2) {
	int len_nums1 = num1.length();
	int len_nums2 = num2.length();
	vector<int> num11;
	vector<int> num22;
	string mul;
    long long count = 0;
    long long count1 = 0;
    long long count2 = 0;
	//const char * c_s1 = num1.c_str();
	//const char * c_s2 = num2.c_str();
	//count1 = atoll(c_s1);
	//count2 = atoll(c_s2);
	//count = count1 * count2;
	//cout << count;
	//char mull[999];
	//mul=to_string(count);

	string res;
	int n1 = num1.size(), n2 = num2.size();
	int k = n1 + n2 - 2, carry = 0;
	vector<int> v(n1 + n2, 0);
	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
		}
	}
	for (int i = 0; i < n1 + n2; ++i) {
		v[i] += carry;
		carry = v[i] / 10;
		v[i] %= 10;
	}
	int i = n1 + n2 - 1;
	while (v[i] == 0) --i;
	if (i < 0) return "0";
	while (i >= 0) res.push_back(v[i--] + '0');
	return res;
}


int main() {
	string num1 = "498828660196";
	string num2 = "840477629533";
	cout << multiply(num1, num2);
	/*double co;
	co = pow(2,250);
	cout << co;*/
	system("pause");
	return 0;
}
