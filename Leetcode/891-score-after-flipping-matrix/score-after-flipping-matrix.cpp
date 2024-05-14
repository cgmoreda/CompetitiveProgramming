class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sol = 0;

	int ans = 0;
	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (!grid[i][j])
				cnt++;
		if (cnt * 2 > n) {
			for (int i = 0; i < n; i++)
				grid[i][j] ^= 1;
		}
		if (j == 0) {
			for (int k = 0; k < n; k++) {
				if (grid[k][0] == 0)
					for (int i = 0; i < m; i++)
						grid[k][i] ^= 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j])
				sol+=1<<(m-1-j);

        return sol;
    }
};