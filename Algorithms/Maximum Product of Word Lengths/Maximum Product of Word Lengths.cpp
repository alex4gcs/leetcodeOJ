/**
 * ԭ�����ӣ�https://leetcode.com/problems/maximum-product-of-word-lengths/ 
 * ������Ҫ��취�������ж�����string����û�й�ͬ�ַ���
 * �������뵽��hash�ķ������洢ÿ��string������ֵ��ַ���Ȼ����бȽϾͿ����ˡ� 
 * ������Բ���λ�ķ�ʽ������Сд��ĸһ����26λ�����Կ�����26λ���������洢�����
 * �ڶ�Ӧλ����1��ʾ���string���Ѿ����˶�Ӧ��Ӣ���ַ���
 * Ȼ�������string��Ӧ���������루&����
 * �����Ľ����0�����������stringû�й�ͬ���ַ���
 */
 
class Solution {
public:
    // ��ÿ��stringת���ɶ�Ӧ�ı�־
    int getFlag(string& s) {
        int ans = 0;
        int len = s.length();
        for(int i = 0; i < len; ++i) {
            ans |= 1<<(s[i] - 'a');
        }
        return ans;
    }
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> flags; // flags����洢��Ӧ�ı��
        vector<int> sizes; // sizes����洢��Ӧ�ĳ���
        for(int i = 0; i < len; ++i) {
            flags.push_back(getFlag(words[i]));
            sizes.push_back(words[i].size());
        }
        int ans = 0;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(((flags[i] & flags[j]) == 0) && (sizes[i] * sizes[j] > ans))
                    ans = sizes[i] * sizes[j];
            }
        }
        return ans;
    }
};
