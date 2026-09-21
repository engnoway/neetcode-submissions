class NumMatrix {
   public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rosize = matrix.size();
        int colsize = matrix[0].size();

        int size = rosize * colsize;
        prefix = vector<vector<int>>(rosize + 1, vector<int>(colsize + 1, 0));
        for (int ro = 0; ro < rosize; ro++) {
            for (int col = 0; col < colsize; col++) {
                prefix[ro + 1][col + 1] =
                    matrix[ro][col] - prefix[ro][col] + prefix[ro][col + 1] + prefix[ro + 1][col];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        int top = prefix[row1][col2 + 1];
        int left = prefix[row2 + 1][col1];
        int overlap = prefix[row1][col1];
        sum = prefix[row2 + 1][col2 + 1] - top - left + overlap;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */