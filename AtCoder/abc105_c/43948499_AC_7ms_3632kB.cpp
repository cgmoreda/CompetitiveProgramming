#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define ll int
#define ii pair<ll,ll>
#define sz(a) a.size()
#define all(x) x.begin(),x.end()


string letters = "0123456789ABCDEF";

int toInt(char c)
{
    return letters.find(c);
}

int FromAnyBasetoDecimal(string in, int base)
{
    int res = 0;
    for (int i = 0; i < sz(in); ++i)
        res *= base, res += toInt(in[i]);
    return res;
}

string FromDecimaltoAnyBase(int number, int base)
{
    if (number == 0)
        return "0";
    string res = "";
    for (; number; number /= base)
        res = letters[number % base] + res;
    return res;
}

string toNegativeBase(int n, int negBase)
{
    if (n == 0)
        return "0";
    string ans = "";
    while (n != 0)
    {
        int rem = n % negBase;
        n /= negBase;
        if (rem < 0)
        {
            rem += (-negBase);
            n += 1;
        }
        ans += to_string(rem);
    }
    reverse(all(ans));
    return ans;
}

void print(int x)
{
    if (x <= 1)
    {
        cout << x;
        return;
    }
    print(x >> 1);
    cout << (x & 1);
}


void solve()
{
    int n;
    cin >> n;
    cout << toNegativeBase(n, -2) << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();


}