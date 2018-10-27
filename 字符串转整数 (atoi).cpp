/*实现 atoi，将字符串转为整数。
该函数首先根据需要丢弃任意多的空格字符，直到找到第一个非空格字符为止。
如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续
的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直
接将其与之后连续的数字字符组合起来，形成整数。字符串可以在形成整数的字
符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。当字符
串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含
空白字符时，则不进行转换。若函数不能执行有效的转换，返回 0。
说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 
。*/
#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <execution>
#include <string>
#include <sstream>

#define MAXNUM 2147483647;
#define MINNUM -2147483648;
#define INT_MIN (-2147483647 - 1)
using namespace std;

void str2int(int &int_temp, const string &string_temp)
{
	stringstream stream(string_temp);
	stream >> int_temp;
}
int minn = INT_MIN;
int maxx = 2147483647;
int myAtoi(string str) {
	int minn = INT_MIN;
	int maxx = 2147483647;
	int len = str.length();
	int num = len;
    int res;
	int flag = 0;

	if (len < 1) {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')  continue;
		else
			num = i; 
		    break; 
//		cout << str[i] << endl;
	}
	str = str.substr(num, len);
	if (str[0] == ' ') return 0;    //去掉空格字符


	num = str.length();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') {
			flag = 1;  
			continue;
		}
		else
			num = i;
		break;
//		cout << str[i] << endl;
	}
	str = str.substr(num, len);     //去掉前面的0字符

	num = str.length()-1;
	char sym = str[0];
	if (flag == 1) {
		if(str[0]<'0' || str[0]> '9') return 0;
	}
	if (flag == 0) {
		if (str[0] == '-' || str[0] == '+')
		{
			if (str[1]<'0' || str[1]> '9') return 0;
			else {
				for (int i = 1; i < str.length(); i++) {
					if (str[i] >= '0' && str[i] <= '9')
						continue;
					else num = i;
				}
				str = str.substr(0, num + 1);    //str为所求数字字符  还得加上前面的-/+符号
			}
			switch (sym)
			{
			case '+':
				str2int(res, str);
				if (res <= maxx)
					return res;
				else
					return maxx;
			case '-':
				str2int(res, str);
				if (res >= minn)
					return res;
				else
					return minn;
			}
		}
	}

	if (str[0]<'0' || str[0]> '9') {
		return 0;
	}             //第一个为字符


	if (str[0] >'0' || str[0]<'9') {
		for (int i = 0; i < str.length(); i++) {
			if (str[i]<'0' || str[i]> '9')
				continue;
			else num = i;
		}
		str = str.substr(0, num+1);
		str2int(res, str);
		return res;
	}             //第一个为数字，非符号
}
int main()
{
	string s("0-1");
	cout << "最终结果：" << endl;
	cout <<myAtoi(s)<<endl;
	cout << minn;
	system("pause");
}

