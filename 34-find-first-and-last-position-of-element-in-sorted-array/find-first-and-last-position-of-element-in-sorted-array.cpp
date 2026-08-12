class Solution {
public:
int first(vector<int>& nums,int target){
    int n = nums.size();
    int s =0, e = n-1;
    int ans =-1;
    while(s<=e){
        int mid = s +(e-s)/2;
        if(nums[mid]==target){
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid]<target){
            s = mid+1;
        }
        else e = mid -1;
    }
    return ans;
}
int last(vector<int>& nums,int target){
    int n = nums.size();
    int s =0, e = n-1;
    int ans =-1;
    while(s<=e){
        int mid = s +(e-s)/2;
        if(nums[mid]==target){
            ans = mid;
            s = mid+1;
        }
        else if(nums[mid]<target){
            s = mid+1;
        }
        else e = mid -1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       return {first(nums,target),last(nums,target)}; 
    }
};