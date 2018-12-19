/** 
 * 算法基础：摩尔投票法 
 * @param nums 
 * @return 
 */
 
//摩尔投票法，摩尔投票法的基本思想很简单，在每一轮投票过程中，从数组中找出一对不同的元素，
//将其从数组中删除。这样不断的删除直到无法再进行投票，如果数组为空，则没有任何元素出现的
//次数超过该数组长度的一半。如果只存在一种元素，那么这个元素则可能为目标元素。
//在算法执行过程中，我们使用常量空间实时记录一个候选元素c以及其出现次数f(c)，c即为当前阶
//段出现次数超过半数的元素。根据这样的定义，我们也可以将摩尔投票法看作是一种动态规划算法。
//其实这样的算法也可以衍生到其它频率的问题上，比如说，找出所有出现次数大于n/3的元素。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
            int majority = -1;  
  
    int count = 0;  
  
    for (int num : nums) {  
        if (count == 0) {  
            majority = num;  
            count++;  
        } else {  
            if (majority == num) {  
                count++;  
            } else {  
                count--;  
            }  
        }  
    }  
  
    int counter = 0;  
    if (count <= 0) {  
        return -1;  
    } else {  
        for (int num : nums) {  
            if (num == majority) counter ++;  
        }  
    }  
  
    if (counter > nums.size() / 2) {  
        return majority;  
    }  
  
    return -1;  
    }
};
