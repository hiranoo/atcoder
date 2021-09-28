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
#include <atcoder/modint>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
using mint = modint1000000007;


int main(){
  int n, k;
  cin >> n >> k;
  string s; cin >> s;

  vector<vector<int>> cnt(n+1, vector<int>(26, -1));
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      cnt[i][j] = cnt[i+1][j];
    }
    int j = s[i] - 'a';
    cnt[i][j] = i;
  }

  string ans = "";
  int head = 0;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < 26; j++){
      if(cnt[head][j] != -1 && n - cnt[head][j] >= k-i){
        head = cnt[head][j];
        break;
      }
    }
    ans.push_back(s[head]);
    head++;
  }

  cout << ans << endl;
}