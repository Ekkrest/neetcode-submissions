class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ans;

        while(l < r){
            int first = numbers[l];
            int end = numbers[r];
            int sum = first + end;

            if(target == sum){
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                return ans;
            } 
            else if(target > sum){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};
