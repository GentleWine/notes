#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int first = (size1 + size2)/2;
        int second = (size1 + size2)/2 + 1;
        if((size1+size2)%2==0) return (double(find(first, nums1, 0, nums2, 0))+double(find(second, nums1, 0, nums2, 0)))/2;
        else return find(second, nums1, 0, nums2,0);
    }
    // pos starts from 1
    int find(int pos, vector<int>&nums1, int start1, vector<int>&nums2, int start2)
    {
        if(start1>=nums1.size()) return nums2[start2+pos-1];
        if(start2>=nums2.size()) return nums1[start1+pos-1];
        if(pos == 1) return nums1[start1]<=nums2[start2]?nums1[start1]:nums2[start2];

        int n = pos/2;
        int len1=n;
        int len2=n;
        if(start1+n-1>=nums1.size())len1 = nums1.size()-start1;
        if(start2+n-1>=nums2.size())len2 = nums2.size()-start2;
        if(nums1[start1+len1-1]>nums2[start2+len2-1]) return find(pos - len2, nums1, start1,nums2, start2 + len2); 
        else return find(pos - len1, nums1,start1+len1, nums2, start2);
    }
};
int main()
{
    Solution s;
    vector<int> nums1 ={1};
    vector<int> nums2 ={2,3,4,5,6};
    cout<<s.findMedianSortedArrays(nums1,nums2);
    return 0;
}