    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int j = 0,i = matrix.size()-1;
        while(i>=0 && j<matrix[0].size()){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) i--;
            else j++;
        }
        return false;
    }