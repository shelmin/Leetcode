/*
**和螺旋矩阵1类似，只是把遍历变成了生成矩阵，思路相同，参考上题
*/
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<vector<int>> generateMatrix(int n) {
	int count = 1;
	int row = n;
	int col = n;
	vector<int> temp(col, 0);
	vector<vector<int>> ma(row, temp);
	vector<vector<int>> rel(row, temp);
	if (n == 1) {
		rel[0][0] = 1;
		return rel;
	}
	int i = 0;
	int j = 0;
	int circle = 0;
	int flag = 0;

	while (ma[i][j] == 0) {
		rel[i][j] = count;
		ma[i][j] = 1;
		count++;
		if (i == circle) {
			if (j < (col - 1 - circle)) flag = 1;
			if (j == (col - 1 - circle)) flag = 2;
		}
		else if (i == (row - 1 - circle)) {
			if (j > circle) flag = 3;
			if (j == circle) flag = 4;
		}
		else if (j == (col - 1 - circle)) flag = 5;
		else if (i == (circle + 1)) flag = 6;
		else flag = 7;

		switch (flag) {
		case 1: j++; break;
		case 2: i++; break;
		case 3: j--; break;
		case 4: i--; break;
		case 5: i++; break;
		case 6: j++; circle++; break;
		case 7: i--; break;
		default: break;
		}
	}
	return rel;
}



int main() {
	int n = 3;
	generateMatrix(n);
	system("pause");
	return 0;
}
