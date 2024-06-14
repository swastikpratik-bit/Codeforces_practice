// Problem Link -> 

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define leadingzero __builtin_clzll
#define trailingzero __builtin_ctzll
#define bitsParity __builtin_parity
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define int long long
#define vll vector<int>
#define vbb vector<bool>
#define vss vector<string>
#define vpp vector<pair<int, int>>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int MOD = 1000000007;


//------------------------------ SOLVE -------------------------------------
/*
        --> READ PROPERLY (READ AGAIN)
        --> THINK > FORMULATE > STRUCTURE CODE > CODE
        --> Check variables, overflows
        --> DEBUG
        --> SUBMIT
 
        * special cases (n=1?)
        * do something instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
 
        * try to apply brute force first > 
        * think greedy > 
        * Don't Overthink about complexity >
        * Use pen-copy > 
*/

void super(int test, int totTest)
{
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }

    vector<int> ans(n);
    map<int, int> marked;
    int cur = 1;
    int times = 0;
    int other = 0;
    for (auto &x : mp)
    {
        if(x.second.size() >= k){
            times++;
            for (int i = 0; i < k; i++)
            {
                ans[x.second[i]] = i + 1;
            }
        }
        else{
            for (int i = 0; i < x.second.size();i++){
                ans[x.second[i]] = cur;
                cur++;
                if(cur > k){
                    cur = 1;
                }
            }
            other += x.second.size();
        }
    }

    times += other/k;
    map<int, int> chk;
    for (int i = 0; i < n; i++)
    {
        chk[ans[i]]++;
        if(chk[ans[i]] > times){
            cout << 0 << " ";
        }
        else{
            cout << ans[i] << ' ';
        }
    }
    cout << endl;
}

//------------------------- MAIN -------------------------------------
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases = 1;
    cin >> testcases;
    int totTest = testcases;

    int test = 1;
    while (testcases--)
    {
        super(test++, totTest);
    }

    return 0;
}