/* O(n^2)时间复杂度方法——从中心向外扩散

1.思想：

     1）将子串分为单核和双核的情况，单核即指子串长度为奇数，双核则为偶数；

    2）遍历每个除最后一个位置的字符index(字符位置)，单核：初始low = 初始high = index，low和high均不超过原字符串的下限和上限；判断low和high处的字符是否相等，相等则low++、high++（双核：初始high = 初始low+1 = index + 1）；

    3）每次low与high处的字符相等时，都将当前最长的回文子串长度与high-low+1比较。后者大时，将最长的回文子串改为low与high之间的；

    4）重复执行2）、3），直至high-low+1 等于原字符串长度或者遍历到最后一个字符，取当前截取到的回文子串，该子串即为最长的回文子串。

2.时间复杂度解释：

   遍历字符：一层循环、O(n-1)；

   找以当前字符为中心的最长回文子串：嵌套两个独立循环、O(2n*(n-1)) = O(n^2)。
--------------------- 
作者：Zt小哥 
来源：CSDN 
原文：https://blog.csdn.net/qq_32354501/article/details/80084325 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;
 
string longestPalindrome(string s) {
	string str=s.substr(0,1);
	if (s.empty()) return "";
	if (s.length() == 1) return s;
	int count = 0;
	int low = 0;
	int high = 0;
	int len = s.length();
	for (int index = 0; index < len; index++) {//单核情况
		//if (index == 0 || index == (len - 1)) continue;
		low = index;
		high = index;
		while (s[low] == s[high] && low!=0 && high!=(len-1)) {
			low--;
			high++;
		}
		if (s[low] != s[high]) {
			low++;
			high--;
		}
		if ((high - low+1) > count) {
			str = s.substr(low,high-low+1);
			count = high - low + 1;
		}
	}
	for (int index = 0; index < len; index++) {//双核情况
		if (index == (len - 1)) {
			continue;
		}
		low = index;
		high = index + 1;
		while (s[low] == s[high] && low != 0 && high != (len - 1)) {
			low--;
			high++;
		}
		if (s[low] != s[high]) {
			low++;
			high--;
		}
		if ((high - low +1) > count) {
			str = s.substr(low, high - low + 1);
			count = high - low + 1;
		}
	}
	cout << str << endl;
	cout << count << endl;
	return str;
}

int main() {
	string s = "aaaa";
	cout << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}
