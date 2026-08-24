class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;

        int max = 0;
        while (left < right){
            int min_height = min(heights[left], heights[right]);
            if (min_height * (right - left) > max){
                max = min_height * (right - left);
            }else if (heights[right] > heights[left]){
                left++;
            }else{
                right--;
            }
        }
        return max;
    }
};
