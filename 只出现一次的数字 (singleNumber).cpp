//其中^为异或运算符，将数字转换为2进制后按位进行运算，例如：15的2进制表示为1111, 2的2进制表示为0010，那么15^2的结果为1101返回值为13。
//重要特性a^=b的效果等价于a=a^b。对一个元素连续与另一个元素做两次异或运算后得到的元素还是自己，当对整个数组进行遍历异或运算后最后得到
//的xor就是所求的唯一的那个。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo = 0;
        for (int i = 0; i < nums.size(); i++ ) {
            xo ^= nums[i];
        }
        return xo;
    }
};
