class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int low = 0;
        int high = matrix[0].size()-1;
        while(low<=high && i<matrix.size()){
            if(matrix[i][high] < target) i++;
            else{
                int mid = (low + high)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};