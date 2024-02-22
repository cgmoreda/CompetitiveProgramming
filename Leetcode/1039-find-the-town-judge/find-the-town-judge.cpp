class Solution
{
 public:
	int findJudge(int n, vector<vector<int>>& trust)
	{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

		vector<int> countTrust(n + 1);
		for (auto& v : trust)
		{
			int a = v[0], b = v[1];
			countTrust[b]++;
			countTrust[a] = -1e5;
		}
		for (int i = 1; i <= n; i++)
			if (countTrust[i] == n - 1)
				return i;

		return -1;

	}
};