class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
       vector<int> arr;
       for(int i =0;i<n;i++){
       bool flag= false;
        for(int j=i+1;j<i+n;j++){
            int idx = j%n;
            if(nums[idx]> nums[i]){
                arr.push_back(nums[idx]);
                flag = true;
                break;
            }
        }
        if(!flag) arr.push_back(-1);
       }
       return arr; 
    }
};
