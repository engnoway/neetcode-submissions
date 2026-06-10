class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>myset;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char tmp=board[i][j];
                if(tmp!='.'){
                    string row=to_string(tmp)+"in row"+to_string(i);
                    string col=to_string(tmp)+"in col"+to_string(j);
                    string box=to_string(tmp)+"in box"+to_string(i/3)+to_string(j/3);

                    if(myset.count(row) ||
                    myset.count(col)    ||
                    myset.count(box))
                    return false;
                        myset.insert(row);
                        myset.insert(col);
                        myset.insert(box);
                    
                }
            }
        }
        return true;
    }
};
