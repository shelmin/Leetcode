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


//	std::vector<double> v(10'000'007, 0.5);
//	for (auto t_ = v.begin(); t_ != v.end(); t_++) {
//		std::cout << *t_ << std::endl;
//	}

//	{
//		auto t1 = std::chrono::high_resolution_clock::now();
//		double result = std::accumulate(v.begin(), v.end(), 0.0);
//		auto t2 = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double, std::milli> ms = t2 - t1;
//		std::cout << std::fixed << "std::accumulate result " << result
//			<< " took " << ms.count() << " ms\n";
//	}

//	{
//		auto t1 = std::chrono::high_resolution_clock::now();
//		double result = std::reduce(std::execution::par, v.begin(), v.end());
//		auto t2 = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<double, std::milli> ms = t2 - t1;
//		std::cout << "std::reduce result "
//			<< result << " took " << ms.count() << " ms\n";
//	}