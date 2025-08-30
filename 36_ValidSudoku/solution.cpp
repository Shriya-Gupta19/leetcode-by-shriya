class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>s;
        int n=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c!='.'){
                    n++;
                    string row="row"+to_string(i)+c;
                    string col="col"+to_string(j)+c;
                    int bid=(i/3)*3+j/3;
                    string block="block"+to_string(bid)+c;
                    if(s.count(row) || s.count(col) || s.count(block)){
                        return false;
                    }
                    s.insert(row);
                    s.insert(col);
                    s.insert(block);
                }
            }
        }
        return true
    }
};