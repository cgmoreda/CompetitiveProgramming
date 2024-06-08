class Solution {
public:
    bool checkSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        map<int, int> mp;
        long long sum = 0;
        long long pr =0;
        for (int i = 0; i < n; i++) {
            sum = ((sum + v[i]) % k + k) % k;
            if (mp[sum])
                return true;
            mp[pr]++;
            pr = sum;
        }

        return false;
    }
};