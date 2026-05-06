class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxValue = 0;

        while(l < r){
            int value = min(heights[l], heights[r])*(r-l);
            maxValue = max(value, maxValue);

            if(heights[l] > heights[r]) r--;
            else l++;             
        }

        return maxValue;
    }
};
