class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lo=0;
        int hi=n-1;
        int first=-1;
        vector<int> ans;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target){
                first=mid;
                hi=mid-1;
            }
            if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
         if (first != -1) {
            while (first < n && nums[first] == target) {
                ans.push_back(first);
                first++;
            }
        }

       // sort(ans.begin(),ans.end());
        return ans;
    }
};