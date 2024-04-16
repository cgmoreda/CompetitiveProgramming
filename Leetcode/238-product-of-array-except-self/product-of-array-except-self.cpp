class Solution
{
 public:
	vector<int> productExceptSelf(vector<int>& nums)
	{

		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int n = nums.size();
		vector<int> ret(n, 1);
		int x = nums[0];

		for (int i = 1; i < n; i++)
		{
			ret[i] *= x;
			x *= nums[i];
		}
		x = nums[n-1];
		for (int i = n - 2; i >= 0; i--)
		{
			ret[i] *= x;
			x *= nums[i];
		}
		return ret;
	}
};