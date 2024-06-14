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

int helper(vector<int> a , vector<int> b){
    int i = 0;
    int j = 0;
    int ans = 0;
    int n = a.size();
    sort(all(a));
    sort(all(b));
    while (i < n && j < n)
    {
        if(a[i] >= b[j]){
            ans++;
            j++;
        }
        else if(a[i] < b[j] ){
            i++;
            j++;
        }
    }
    return ans;
}

void super(int test, int totTest)
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 1; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    

    int low = 1, high = m;
    int cnt = 0;
    a[0] = 1;
    int prev = helper(a, b);
    while (high >= low)
    {
        int mid = (high + low) / 2;
        a[0] = mid;
        int cur = helper(a, b);

        if (cur == prev){
            low = mid + 1;
            cnt = mid;
        }
        else{
            high = mid - 1;
        }
    }

    cout << (prev * m + (m - cnt)) << endl;
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