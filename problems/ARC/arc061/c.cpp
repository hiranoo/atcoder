#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


// i ~ a.size()-1番目の数式和
ll search(int i, string s){
  int n = s.size();
  if(i == n) return 0;

  ll ret = 0;
  //cout << "i:" << i << endl;
  rep(x, i+1, n){
    string sub = s.substr(i, x-i);
    //cout <<" pre:" << sub << endl;
    ret += max(n-x, 1)*stoll(sub) + search(x, s);
  }
  //cout << "i:" << i << " sum:" << ret << endl;
  return ret;
}

int main(){
  string s; cin >> s;
  vector<int> a(s.size());
  
  ll ans = search(0, s);
  cout << ans << endl;
}


string S;
 
ll rec(int n, vi &v)
{
    ll ret = 0;
 
    if(n == S.size() - 1)
    {
        int pos = 0;
        int cnt = 0;
        for(auto x : v)
        {
            cnt = x - pos + 1;
            ret += stoll(S.substr(pos, cnt));
            pos = x + 1;
        }
 
        if(pos < S.size()) ret += stoll(S.substr(pos));
 
        return ret;
    }
 
    ret += rec(n + 1, v);
    v.push_back(n);
    ret += rec(n + 1, v);
    v.pop_back();
    
    return ret;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //標準入力をファイルに変更
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
 
    in1(S);
 
    vi v;
    outl(rec(0, v));
 
    return 0;
}
#include<algorithm>     //sort,二分探索,など
#include<bitset>        //固定長bit集合
#include<cmath>         //pow,logなど
#include<complex>       //複素数
#include<deque>         //両端アクセスのキュー
#include<fstream>       //ファイルストリーム（標準入力変更用）
#include<functional>    //sortのgreater
#include<iomanip>       //setprecision(浮動小数点の出力の誤差)
#include<iostream>      //入出力
#include<iterator>      //集合演算(積集合,和集合,差集合など)
#include<map>           //map(辞書)
#include<numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include<queue>         //キュー
#include<set>           //集合
#include<stack>         //スタック
#include<string>        //文字列
#include<unordered_map> //イテレータあるけど順序保持しないmap
#include<unordered_set> //イテレータあるけど順序保持しないset
#include<utility>       //pair
#include<vector>        //可変長配列

//名前
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;

//定数
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
const int MAXR = 100000;             //10^5:配列の最大のrange

//マクロ
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,e) for(int i=s;i<e;i++)
#define repse(i,s,e) for(int i=s;i<=e;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define in1(x1) cin >> x1
#define in2(x1, x2) cin >> x1 >> x2
#define in3(x1, x2, x3) cin >> x1 >> x2 >> x3
#define in4(x1, x2, x3, x4) cin >> x1 >> x2 >> x3 >> x4
#define in5(x1, x2, x3, x4, x5) cin >> x1 >> x2 >> x3 >> x4 >> x5
#define in6(x1, x2, x3, x4, x5, x6) cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6
#define inN(x, N) rep(i, N) in1(x[i])
#define outl(x) cout << x << endl
#define out2l(x, y) cout << x << " " << y << endl 

//よく使う関数
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline ll div_ceil(ll a, ll b) { return (a + (b - 1)) / b; }

string S;

ll rec(int n, vi &v)
{
    ll ret = 0;

    if(n == S.size() - 1)
    {
        int pos = 0;
        int cnt = 0;
        for(auto x : v)
        {
            cnt = x - pos + 1;
            ret += stoll(S.substr(pos, cnt));
            pos = x + 1;
        }

        if(pos < S.size()) ret += stoll(S.substr(pos));

        return ret;
    }

    ret += rec(n + 1, v);
    v.push_back(n);
    ret += rec(n + 1, v);
    v.pop_back();
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //標準入力をファイルに変更
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());

    in1(S);

    vi v;
    outl(rec(0, v));

    return 0;
}
提出情