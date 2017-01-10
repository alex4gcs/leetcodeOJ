/**
 * ԭ�����ӣ�https://leetcode.com/problems/integer-to-roman/
 * ������Ժ�����һ�𿴣�http://blog.csdn.net/gcs6564157/article/details/51980430 
 * �����������ֵı�ʾ���Ͳ���˵�ˡ�
 * �����е�ǧλ����λ��ʮλ����λ�����������ֱ�ʾ������
 * Ȼ���ж�������Ҫ����ǧ�����ټ���ʮ�Լ���λ�����ˡ� 
 */
 
class Solution {
public:
    string intToRoman(int num) {
        string th[] = {"", "M", "MM", "MMM"};
        string hu[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string te[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ge[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string ans;
        ans += th[num / 1000];
        ans += hu[num % 1000 / 100];
        ans += te[num % 100 / 10];
        ans += ge[num %10];
        return ans;
    }
};
