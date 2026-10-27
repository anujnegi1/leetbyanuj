class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(),c=0;
        if(n<=2) return true;
        for(int i=0;i<n-2;i++){
            if(nums[i]>nums[i+1] && nums[i+2]>=nums[i+1]){
                if(nums[i+2]>=nums[i]){
                    nums[i+1]=nums[i];
                }
                else{
                    nums[i]=nums[i+1];
                }
                c++;
            }
            else if(nums[i]>nums[i+1]){
                return false;
            }
            else if(nums[i]<=nums[i+1] && nums[i+2]<nums[i+1]){
                if(nums[i+2]>=nums[i]){
                    nums[i+1]=nums[i];
                }
                else{
                    nums[i+2]=nums[i+1];
                }
                c++;
            }
        }
        if(c>=2) return false;
        return true;
    }
};