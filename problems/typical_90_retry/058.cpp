#include <bits/stdc++.h>
#include <atcoder/all>
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
const ll INF = 1e16;

template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b; return true;} return false;}

int main() {
  int n; ll k; cin >> n >> k;

  vector<int> to(100000, -1);
  rep(i, 0, 99999) {
    int x = i;
    int y = 0;
    while(x > 0) {
      y += x%10;
      x /= 10;
    }
    int z = (i + y) % 100000;
    to[i] = z;
  }


  vector<int> visited(100000, -1);
  int cur = n;
  int cnt = 0;
  vector<int> vs;
  while(cnt <= k) {
    if(visited[cur] != -1) break;
    visited[cur] = cnt++;
    vs.push_back(cur);
    cur = to[cur];
  }

  int a = vs.size();
  int c = cnt - visited[cur];
  int loop_s = visited[cur];
  
  if(k <= a) cout << vs[k] << endl;
  else{
    cout << vs[loop_s + (k-a) % c] << endl;
  }
  
}