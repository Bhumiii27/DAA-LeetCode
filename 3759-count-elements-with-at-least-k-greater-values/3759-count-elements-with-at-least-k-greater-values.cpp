class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int last = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin() - 1;
            if(n - last - 1 >= k)
                count++;
        }
        return count;
    }
};