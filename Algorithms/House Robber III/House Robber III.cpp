/**
 * 原题链接：https://leetcode.com/problems/burst-balloons/ 
 * 用动态规划来做,
 * 开一个dp[ ][ ]数组，其中dp[ i ][ j ]表示从第 i 到第 j 个气球所能得到的最大硬币值,
 * 初始状态都置为0。在nums数组的头和尾插入 1 用来辅助计算。 
 * 用一个下标start把从 i 到 j 分成两块
 * 其中dp[ i ][ j ]的值可以用
 * dp[ i ][start - 1] + nums[ i - 1 ] * nums[ start ] * nums[ j + 1 ] +dp[ start + 1 ][ j ]
 * 来表示，将start从 i 到 j 循环一遍找出最大的值即可。 
 */
 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(),vector<int>(nums.size(), 0));
        for(int len = 1; len <= n; ++len) { // len是长度，逐步扩大
            for(int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for(int start = left; start <= right; ++start) {
                    dp[left][right] = max(dp[left][right], dp[left][start - 1] + nums[left - 1] * nums[start] * nums[right + 1] + dp[start + 1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
