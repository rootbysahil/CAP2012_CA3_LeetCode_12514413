
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int height[200] = {0};
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < cols; j++) {

                int left = j;
                int right = j;

                while (left >= 0 && height[left] >= height[j])
                    left--;

                while (right < cols && height[right] >= height[j])
                    right++;

                int width = right - left - 1;
                int area = width * height[j];

                if (area > maxArea)
                    maxArea = area;
            }
        }

        return maxArea;
    }
};
