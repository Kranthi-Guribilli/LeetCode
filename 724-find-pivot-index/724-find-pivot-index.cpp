class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,ls=0;
        for(int val: nums)
            sum+=val;
        for(int i=0;i<nums.size();i++){
            if(ls==(sum-nums[i]))
                return i;
            ls+=nums[i];
            sum-=nums[i];
        }
        return -1;
    }
};