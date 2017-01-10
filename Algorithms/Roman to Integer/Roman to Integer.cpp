/**
 * 原题链接：https://leetcode.com/problems/roman-to-integer/ 
 * （题目的测试点好强大，3999个点。。。。= =） 
 * 可以按照从右往左的顺序来计算数值。 
 * 首先要明确，小的数字无论怎么搭配也不会超过一个大的数字
 * 比如I，最多只能连续写3次变成III，但它是不可能超过V的，
 * 又比如X，比它小的字符是I和V，
 * 但是I和V能组成的最大值是VIII，也是没有办法大过X的,
 * 这为我们判断到底是加还是减带来了依据，
 * 因为只有I、X、C这3个字符可以在大字符的左边构成减，所以当扫描到其他字符的时候，
 * 直接加对应的阿拉伯数值就行，至于对这3个字符，需要进行一下判断了。 
 * 以 I 为例，只有在当它是大字符的右边或者说没有更大的字符
 * (简单来说就是不在大字符的左边)的时候它才是加，
 * 不在大字符的左边意味这当前的数值不会比 I 能组成的最大数值大，
 * 比如说5，所以当扫描到 I 的时候，以5为分界点，累加数值超过5的，
 * 说明它是在大字符的左边，要用减，不超过5则用加，X和C的判断方法同理，不过分界点是50和500。 
 */

class Solution {
public:
    int romanToInt(string s) {
        int len = s.size(), ans = 0;
        for(int i = len - 1; i >= 0; --i) {
            switch(s[i]){
                case 'I' : ans += (ans >= 5 ? -1 : 1);
                break;
                case 'V' : ans += 5;
                break;
                case 'X' : ans += 10 * (ans >= 50 ? -1 : 1);
                break;
                case 'L' : ans += 50;
                break;
                case 'C' : ans += 100 * (ans >= 500 ? -1 : 1);
                break;
                case 'D' : ans += 500;
                break;
                case 'M' : ans += 1000;
                break;
            }
        }
        return ans;
    }
};
