#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vi vector<int>

int vis[35][35][6000], n, id;
vi nums, signs;
set<int> s;
string x;

void dope(int i, int inv, int csum)
{
    if (i == nums.size())
    {
        s.insert(csum);
        return;
    }
    if (vis[i][inv][csum + 3000] == id)
        return;
    vis[i][inv][csum + 3000] = id;
    int nsum = csum + nums[i] * signs[i] * (inv % 2 ? 1 : -1);
    dope(i + 1, inv, nsum);
    if (signs[i] == -1)
        dope(i + 1, inv + 1, nsum);

    if (inv > 0)
        dope(i + 1, inv + (signs[i] == -1) - 1, nsum);

}

void solve()
{
    stringstream line(x);
    char a;
    id++;
    nums = signs = vi(1, 1);
    line >> nums[0];
    while (line >> a && line >> n)
        nums.push_back(n), signs.push_back(a == '+' ? 1 : -1);

    s.clear();
    dope(0, 0, 0);
    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (getline(cin, x) && !x.empty())
        solve();

}