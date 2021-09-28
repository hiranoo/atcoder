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
#include <atcoder/segtree>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main(){
  ll n, m; cin >> n >> m;
  string s, t;
  cin >> s;
  cin >> t;

  ll n_ = n / gcd(n, m);
  ll m_ = m / gcd(n, m);

  ll a = lcm(n_, m_) / m_;
  ll b = lcm(n_, m_) / n_;

  ll k = 0;
  bool judge = true;
  while(k*a < n && k*b < m){
    if(s[k*a] != t[k*b]){
      judge = false;
      break;
    }
    k++;
  }

  if(judge) cout << lcm(n, m) << endl;
  else cout << -1 << endl;
}