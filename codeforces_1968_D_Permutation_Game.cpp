
//Code by Sarbojit Rana
//Linkedin : https://www.linkedin.com/in/sarbojit-rana/
//Codeforces: https://codeforces.com/profile/sarbojit_007
//Leetcode: https://leetcode.com/u/sarbojit_007/


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef map<ll,ll> mll;

const ll MOD = 998244353;
const double eps = 1e-12;

#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
// #define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


// unique sort :
// sort(all(v));
// v.resize(unique(all(v)) - v.begin())

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 


ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}

ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}

ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}

bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}


void f( vll &p , vll &a, vll &turns, ll k, ll &pos, ll sum){
    for(int i = 1; i< turns.size(); i++){
        sum += a[pos -1] ;
        turns[i] = sum + (k-i)*a[pos -1] ;
        pos = p[pos -1] ;
    }
    
}


void solve(){
    ll n, k , pb, ps ;
    cin >> n >> k >> pb >> ps;
    vll p(n,0) , a(n, 0);
    forn(i, n) cin >> p[i];
    forn(i, n) cin >> a[i];
    ll turns = min(n, k);
    vll turnsb(turns + 1, -1), turnss(turns +1, -1) ;
    f(p, a, turnsb, k, pb, 0);
    f(p, a, turnss, k, ps, 0);
    ll bs = *max_element(all(turnsb));
    ll ss = *max_element(all(turnss));
    if( bs > ss) cout << "Bodya" << endl;
    else if( bs < ss) cout << "Sasha" << endl;
    else cout << "Draw" << endl;

}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        solve();
    }
    return 0;
}
