/**
 * 原题链接：https://leetcode.com/problems/missing-number/ 
 * 线性额外空间的算法： 
 * 开一个哈希数组，然后统计数组里面的所有元素
 * 最后扫描一遍数组，找出缺少的那一个
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int hash[len + 1] = {};
        for(int i = 0; i < len; ++i) {
            hash[nums[i]] = 1;
        }
        for(int i = 0; i < len+1; ++i) {
            if(!hash[i]) return i;
        }
        return -1;
    }
};

/**
 * 常数空间复杂度算法： 
 * 利用位操作，以及“消除”的思想，定义ans = 0，然后去和数组里面每一个元素异或，
 * 然后在和从0到n的数字都分别异或一下，这样最终的结果就是丢失的那一个元素。
 */
 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, i = 0;
        for(auto num : nums) {
            ans ^= num;
            ans ^= i++;
        }
        return ans ^ i; //注意不要忘记和n异或一下
    }
};
