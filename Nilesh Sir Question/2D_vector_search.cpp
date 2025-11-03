class Solution {
public:
    bool binarysearch(vector <int>& row ,int left, int right,int target){
        int mid = left + (right - left) / 2;
        if(left <= right){
            if(row[mid]== target){
            return true;
        }
        else if(row[mid]>target){
            return binarysearch(row,left,mid-1,target);
        }else{
            return binarysearch(row,mid+1,right,target);
        }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int a = 0 ; a < row ; a++){
            if(target >= matrix[a][0] && matrix[a][col-1] >= target){
                int left = 0;
                int right = col - 1;
                return binarysearch(matrix[a],left, right,target);
            }
        }
        return false;
    }
};
