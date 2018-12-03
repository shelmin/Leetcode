/*
**从内到外用circle表示目前所在的圈数，用i,j判断目前所处的圈的位置，然后决定怎么遍历下个点
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


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> rel;
	if (matrix.empty()) return rel;
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> temp(col, 0);
	vector<vector<int>> ma(row,temp);
	int i = 0;
	int j = 0;
  int circle = 0; //圈数
	int flag = 0;
	if (row == 1) {
		for (int k = 0; k < col; k++) {
			rel.push_back(matrix[0][k]);
		}
		return rel;
	}
	if (col == 1) {
		for (int k = 0; k < row; k++) {
			rel.push_back(matrix[k][0]);
		}
		return rel;
	}
	while(ma[i][j] == 0) { 
		rel.push_back(matrix[i][j]);  //遍历
		ma[i][j] = 1;  //已经走过的地方置为1
		if (i == circle){ //处于上面
			if (j < (col-1-circle)) flag = 1;   //处于上面最右元素左边的元素
			if (j == (col-1-circle)) flag = 2;  //处于上面最右元素
		}
		else if (i == (row-1-circle)) { //处于下面
			if (j > circle) flag = 3;   //处于下面最左元素右边的元素
			if (j == circle) flag = 4;  //处于下面最左元素
		}
		else if (j == (col - 1 - circle)) flag=5;  //最右边最右边的元素
		else if (i == (circle + 1)) flag = 6;  //处于一圈的最末元素
		else flag = 7; //处于左边最末元素前的元素

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
	for (int k = 0; k < rel.size(); k++) {
		cout << rel[k];
	}
	return rel;
}



int main() {
	vector<vector<int>> A = { 
	{1}
	};
	spiralOrder(A);
	system("pause");
	return 0;
}
