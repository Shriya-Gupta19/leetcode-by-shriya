class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>ans(row*col);
        int i=0,j=0,k=0;
        while(i<row*col){
            ans[i]=mat[j][k];
            if((j+k)%2==0){
                if(k==col-1) j++;
                else if(j==0) k++;
                else j--,k++;
            }
            else{
                if(j==row-1) k++;
                else if(k==0) j++;
                
                else j++,k--;
            }
            i++;
        }
        return ans;
    }
};