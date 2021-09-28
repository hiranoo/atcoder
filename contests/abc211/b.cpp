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
const ll MOD = 1e9+7;

int main() {
  vector<string> s(4);
  rep(i, 0, 3) cin >> s[i];
  map<string, int> mp;
  
  rep(i, 0, 3) mp[s[i]]++;
  for(auto str : s) {
    if(mp[str] != 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
}