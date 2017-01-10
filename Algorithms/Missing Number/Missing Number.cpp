/**
 * ԭ�����ӣ�https://leetcode.com/problems/missing-number/ 
 * ���Զ���ռ���㷨�� 
 * ��һ����ϣ���飬Ȼ��ͳ���������������Ԫ��
 * ���ɨ��һ�����飬�ҳ�ȱ�ٵ���һ��
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
 * �����ռ临�Ӷ��㷨�� 
 * ����λ�������Լ�����������˼�룬����ans = 0��Ȼ��ȥ����������ÿһ��Ԫ�����
 * Ȼ���ںʹ�0��n�����ֶ��ֱ����һ�£��������յĽ�����Ƕ�ʧ����һ��Ԫ�ء�
 */
 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, i = 0;
        for(auto num : nums) {
            ans ^= num;
            ans ^= i++;
        }
        return ans ^ i; //ע�ⲻҪ���Ǻ�n���һ��
    }
};
