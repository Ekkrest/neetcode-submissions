class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i < (int)nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = nums[i];
            int start = i + 1;
            int end = nums.size() - 1;

            while(start < end){
                int sum = nums[start] + nums[end];
                if(-target == sum){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[start]);
                    tmp.push_back(nums[end]);
                    ans.push_back(tmp);
                    while (start < end && nums[start] == nums[start+1]) start++;
                    while (start < end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;
                }else if(-target < sum){
                    end--;
                }
                else{
                    start++;
                }
            }    
        }
        return ans;
    }
};
