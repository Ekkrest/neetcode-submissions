class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int u){
        if(l < u){
            int pivot = partition(nums, l, u);
            quickSort(nums, l, pivot - 1);
            quickSort(nums, pivot + 1, u);
        }
    }

    int partition(vector<int>& nums, int l, int u){
        int pivot = nums[u];
        int i = l - 1;

        for(int j=l; j<u; j++){
            if(nums[j] <= pivot){
                i++;
                swap(&nums[i], &nums[j]);
            }
        }
        
        swap(&nums[i+1], &nums[u]);
        return  i + 1;
    }

    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};