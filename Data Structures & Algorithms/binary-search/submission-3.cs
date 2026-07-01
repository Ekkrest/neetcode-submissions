public class Solution {
    public int Search(int[] nums, int target) {
        int left = 0;
        int right = nums.Length - 1;

        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target){
                return middle;
            }else if(nums[middle] > target){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }

        return -1;
    }
}
