class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for (auto& i : grid)
            mp[i]++;

        int n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(grid[i][j], grid[j][i]);
        int ans = 0;
        for (auto& i : grid)
            ans += mp[i];
        return ans;
    }
};