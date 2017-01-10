/**
 * 原题链接：https://leetcode.com/problems/integer-to-roman/
 * 这题可以和这条一起看：http://blog.csdn.net/gcs6564157/article/details/51980430 
 * 关于罗马数字的表示法就不再说了。
 * 把所有的千位，百位，十位，各位都用罗马数字表示出来，
 * 然后判断数字需要几个千几个百几个十以及个位就行了。 
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
