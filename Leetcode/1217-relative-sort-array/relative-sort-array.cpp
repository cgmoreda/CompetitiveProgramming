class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> val(1e3 + 1, 1e9);
        for (int i = 0; i < arr2.size(); i++)
            val[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (val[a] == val[b])
                return a < b;
            return val[a] < val[b];
        });
        return arr1;
    }
};