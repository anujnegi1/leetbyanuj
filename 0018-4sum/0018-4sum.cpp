class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int a = j + 1;
                int b = nums.size() - 1;
                while (a < b) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[a] + nums[b];

                    if (sum < target)
                        a++;
                    else if (sum > target)
                        b--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[a], nums[b]});
                        a++;
                        b--;
                        while (a < b && nums[a] == nums[a - 1])
                            a++;
                        while (a < b && nums[b] == nums[b + 1])
                            b--;
                    }
                }
            }
        }
        return ans; 
    }
};