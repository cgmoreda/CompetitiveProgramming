const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return 42;
}();
int calc(vector<int>& hh)
{
    int n =hh.size();
    vector<int>prefmx(hh);
    for(int i=1;i<n;i++)
        prefmx[i] = max(prefmx[i],prefmx[i-1]);
    long long area=0;
    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(prefmx.begin(),prefmx.end(),hh[i])-prefmx.begin();
        area = max(area,1ll*(i-idx)*hh[i]);
    }
    return area;
}


class Solution {
public:
    int maxArea(vector<int>& hh) {
        int ans1 = calc(hh);
        reverse(hh.begin(),hh.end());
        int ans2 = calc(hh);
        return max(ans1,ans2);
    }
};