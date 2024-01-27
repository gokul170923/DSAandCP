    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       int i=0,j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0){
            int k = matrix[i][j];
            if(k==target) return true;
            else if(k>target) j--;
            else i++;
        }
        
        return false;
    }