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
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  int n, X; cin >> n >> X;
  vector<int> x(n);
  rep(i, 0, n-1) cin >> x[i];

  x.push_back(X);
  sort(all(x));

  vector<int> dis(n);
  for(int i = 0; i < n; i++){
    dis[i] = x[i+1] - x[i];
  }

  sort(all(dis));
  
  ll g = dis[0];
  for(int i = 0; i < n-1; i++){
    g = gcd(dis[i+1], g);
  }

  cout << g << endl;
}