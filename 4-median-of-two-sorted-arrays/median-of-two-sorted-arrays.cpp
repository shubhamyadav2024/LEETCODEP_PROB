class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        int k=0;
        vector<int> arr(n+m);
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                arr[k++] = nums1[i++];
            }
                else arr[k++]= nums2[j++];
        }  
        while(i<n){
            arr[k++]=nums1[i++];
        }
        while(j<m){
            arr[k++]=nums2[j++];
        }
        int t = n+m;
        if(t%2==1) return arr[t/2];
        return (double)(double)((arr[t/2]) + (arr[t/2-1]))/2.0;
    }
};