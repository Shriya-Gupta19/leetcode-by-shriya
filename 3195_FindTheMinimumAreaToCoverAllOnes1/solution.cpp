class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minrow=m;
        int mincol=n;
        int maxrow=-1,maxcol=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minrow=min(minrow,i);
                    maxrow=max(maxrow,i);
                    mincol=min(mincol,j);
                    maxcol=max(maxcol,j);
                }
            }
        }

        int height=maxrow-minrow+1;
        int width=maxcol-mincol+1;
        int area=height*width;
        return area;
    }
};