/**
 * 原题链接：https://leetcode.com/problems/find-the-duplicate-number/ 
 * 假设数组是nums[ ]。 
 * 我们可以把这个数组看成是一个链表，0为头结点，nums[ 0 ]的值是下一个节点的地址
 * 依次类推下一个节点nums[ nums[ 0 ] ]…… 
 * 题目说了会有一个重复的元素，即至少有两个节点的next节点位置相同,
 * 这就会形成一个环，重复的元素的值就是环的首地址。于是题目转化成求链表中环的首地址。 
 * 我们用两个指针first和second来扫描链表，其中first指针每次经过一个节点,
 * 即first = nums[ first ]，second指针每次经过两个节点，即second = nums[ nums[ second ] ]，
 * 由于链表中有环，所以在环中经过若干圈的轮回之后，
 * second指针会重新追上first指针（想像一下在400米环形跑道上进行长跑，跑的快的会领先个几圈重新追上跑的慢的）。
 * 这里我们假设慢的指针即first走过的路程（节点个数）为 n ，
 * 这 n 个节点可以分成两部分，一部分是从链表的头结点到环的起始位置的路程 a ，
 * 还有一部分是重复在环中经过的路程 b ，于是就有 ： 
 * a + b = S 
 * 由于快指针second的速度是first的两倍，所以它经过的路程是 2S ，
 * 这2S的路程也可以进行一下划分，由于这个时候两个节点是相遇的，
 * 所以first指针所经过的历程second都经历过了，
 * 不过second指针会多在环中跑了若干圈，假设环的长度是 r ，多跑的圈数为 n ，那么则有： 
 * a + b + n * r = 2S 
 * 两个式子相减可以得出 n * r = S = a + b 
 * 也就是说second指针在环中多走的圈数（n * r）实际上和first之前走过的路程（a + b）是相等的
 * 那我们就来重复这个过程，我们让first指针回到头结点来“重走老路”, 
 * second就来继续转圈圈，不过这个时候速度回到1次一个节点，
 * 很明显当继续转过n圈之后second指针还会在原地，这个时候first指针走过的路是a + b的距离，
 * 他们应该依旧在当前的位置交汇。 
 * 回想一下他们走的路程，其实他们的后半段是同样的路，
 * 很简单，由于这回的速度是一样的，他们两个在环中还能保持相遇，
 * 那只能说明当first指针刚进入环的时候两个人就是在同一个起点了，
 * 而这个位置就是环的起点，同时也是我们所要求的元素！
 */
 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int first = nums[0], second = nums[nums[0]];
        while(first != second) {
            first = nums[first];
            second = nums[nums[second]];
        }
        first = 0;
        while(first != second) {
            first = nums[first];
            second = nums[second];
        }
        return first;

    }
};
