/*
**这里引用：
**作者：nomasp 
**来源：CSDN 
**原文：https://blog.csdn.net/nomasp/article/details/50810589 
**版权声明：本文为博主原创文章，转载请附上博文链接！
/*

/*
**本题关键讨论数组中含0的个数问题，为1和大于2需要分别对待
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        int pro = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)           count++;
            else            pro *= nums[i];
        }       
        if (count == 1) { //0个数为1
            vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0)               res.push_back(pro);
                else                res.push_back(0);
            }
            return res;
        }
        else if (count >= 2) { //0个数大于2
            vector<int> res(nums.size());
            return res;
        }
        else {
            vector<int> res;
            for (int i = 0; i < nums.size(); i++)
                res.push_back(pro / nums[i]);
            return res;
        }       

    }
};
