/**
 * 原题链接：https://leetcode.com/problems/bulb-switcher/ 
 * 模拟会超时，样例的测试点有的数据非常大。
 * 这里有一种很神奇的解法： 
 * 首先我们考虑一下什么情况下灯泡会亮，
 * 灯泡你拨1次它是on，拨2次它是off，拨3次是on。。。
 * 循环下来可以发现，当拨动灯泡的个数是奇数次的时候，灯泡的最终结果是亮的，
 * 所以我们的任务转而计算拨动次数为奇数次的灯泡的个数。
 * 对于位置为 i 的灯泡，能够动到它的轮数一定是 i 的约数，
 * 比如位置是6，能够动到它的轮数是1，2，3，6这四轮，
 * 又比如9，能够拨动它的轮数是1，3，9这3轮，
 * 可以看出来有的位置的约数的个数是偶数个，有的位置的约数的个数是奇数个，
 * 很明显，最后灯泡为on的是那些约数是奇数的位置，
 * 那么问题再一次转化成计算1到n中约数个数为奇数的数字的个数。
 * 那么什么样的数字约数个数是奇数呢？答案是完全平方数，
 * 可以发现，如果是非完全平方数 i ，它的约数一定是成对出现的，
 * 因为他们要的乘积要等于 i，比如6中的1和6，2和3等，
 * 所以它们的约数个数一定是偶数，如果是完全平方数 i ，则它的约数会有一个sqr（i）,
 * 这个约数只能和自己配对，但是很遗憾它只会出现一次，
 * 比如9里面的3，所以完全平方数的约数个数一定是奇数。
 * 这样子，答案再次转化成计算1到n中完全平方数的个数，
 * 这个个数就呼之欲出了，那就是sqr（n），
 * 很简单完全平方数里面那个单独的约数从小到大的排列
 * 是从1，2，3。。。到sqr（n）,超过整个数的话那原来的数就会大于n了。
 */

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
