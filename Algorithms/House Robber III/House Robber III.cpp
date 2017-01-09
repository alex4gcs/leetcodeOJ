/**
 * ԭ�����ӣ�https://leetcode.com/problems/burst-balloons/ 
 * �ö�̬�滮����,
 * ��һ��dp[ ][ ]���飬����dp[ i ][ j ]��ʾ�ӵ� i ���� j ���������ܵõ������Ӳ��ֵ,
 * ��ʼ״̬����Ϊ0����nums�����ͷ��β���� 1 �����������㡣 
 * ��һ���±�start�Ѵ� i �� j �ֳ�����
 * ����dp[ i ][ j ]��ֵ������
 * dp[ i ][start - 1] + nums[ i - 1 ] * nums[ start ] * nums[ j + 1 ] +dp[ start + 1 ][ j ]
 * ����ʾ����start�� i �� j ѭ��һ���ҳ�����ֵ���ɡ� 
 */
 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(nums.size(),vector<int>(nums.size(), 0));
        for(int len = 1; len <= n; ++len) { // len�ǳ��ȣ�������
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
