/**
 * 原题链接：https://leetcode.com/problems/maximum-product-of-word-lengths/ 
 * 首先需要想办法解决如何判断两个string里面没有共同字符，
 * 很容易想到用hash的方法来存储每个string里面出现的字符，然后进行比较就可以了。 
 * 这里可以采用位的方式，由于小写字母一共是26位，所以可以用26位的整型来存储结果，
 * 在对应位上置1表示这个string中已经有了对应的英文字符，
 * 然后把两个string对应的整型相与（&），
 * 如果与的结果是0则表是这两个string没有共同的字符。
 */
 
class Solution {
public:
    // 将每个string转化成对应的标志
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
        vector<int> flags; // flags数组存储对应的标记
        vector<int> sizes; // sizes数组存储对应的长度
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
