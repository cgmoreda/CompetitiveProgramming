class Solution
{
 public:
	vector<int> productExceptSelf(vector<int>& nums)
	{

		int n = nums.size();
		vector<int> ret(n);
		int x = nums[0];

		for (int i = 1; i < n; i++)
		{
			ret[i] = x;
			x *= nums[i];
		}
		x = nums[n-1];
        ret[0]=1;
		for (int i = n - 2; i >= 0; i--)
		{
			ret[i] *= x;
			x *= nums[i];
		}
		return ret;
	}
};