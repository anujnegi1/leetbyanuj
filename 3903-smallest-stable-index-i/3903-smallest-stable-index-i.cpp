class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr1(n);
        vector<int>arr2(n);
        arr1[0]=nums[0];
        for(int i=1;i<n;i++){
            arr1[i]=max(arr1[i-1],nums[i]);
        }
        arr2[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            arr2[i]=min(arr2[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int ans=arr1[i]-arr2[i];
            if (ans<=k) return i;
        }
        return -1;
    }
};