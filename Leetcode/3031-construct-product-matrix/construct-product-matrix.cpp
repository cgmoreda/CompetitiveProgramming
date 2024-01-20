class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    
        int n,m;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>out(grid),sf(grid);
        long long tota=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--){
                sf[i][j]=tota;
                tota*=grid[i][j];
                tota%=12345;
            }
        }
        tota=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                out[i][j] = tota*sf[i][j]%12345;
                tota*=grid[i][j];
                tota%=12345;
            }
        }
        return out;
    }
};