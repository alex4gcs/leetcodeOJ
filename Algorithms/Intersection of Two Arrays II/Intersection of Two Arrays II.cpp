/**
 * 原题链接：https://leetcode.com/problems/intersection-of-two-arrays-ii/ 
 * 把两个数组排序，然后从头开始同时扫描2个数组，
 * 元素相同则输出，元素不同则根据大小关系决定哪个数组的扫描接着往下，
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while(i < len1 && j < len2) {
            if(nums1[i] == nums2[j]) { 
                ans.push_back(nums1[i]);
                i++,j++;
            }else if(nums1[i] < nums2[j]) {
                i++;
            }else j++;
        }
        return ans;
    }
};

