//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;

//这题用一个栈来保存需要被“消除”掉的左括号类型，若新近的括号与栈顶括号刚好“配对”
//成功，则进行出栈操作，循环结束后，若栈为空，返回true,反之，表示仍有左括号未“配对”
//成功，则返回false。

bool isValid(string s) {
	int len = s.length();
	stack<char> st;
	if (s.empty()) return true;
	if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
	st.push(s[0]);
	for (int i = 1; i < len; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
		switch (s[i]) {
		case ')':
			if (st.empty() || st.top() != '(') return false;
			if (st.top() == '(') st.pop();

			break;
		case '}':
			if (st.empty() || st.top() != '{') return false;
			if (st.top() == '{') st.pop();

			break;
		case ']':
			if (st.empty() || st.top() != '[') return false;
			if (st.top() == '[') st.pop();
			break;
		default:
			break;

		}
    
	}
	if (st.empty()) return true;
	else return false;
}

int main() {
	string s = "()[]{}";
	cout << isValid(s) << endl;
	system("pause");
	return 0;
}
