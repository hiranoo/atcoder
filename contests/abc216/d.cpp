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
const ll INF = 1e16;

void chmax(ll &a, ll b) {a = max(a, b);}
void chmin(ll &a, ll b) {a = min(a, b);}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(m);
  vector<int> limit(m), top_id(m, 0);

  rep(i, 0, m-1) {
    int k; cin >> k; limit[i] = k-1;
    rep(j, 0, k-1) {
      int c; cin >> c; a[i].push_back(c);
    }
  }
  
  queue<int> q; // 一番上のボールが同色になっている筒のid
  map<int, set<int>> mp; // 先頭が色c である筒の集合
  rep(i, 0, m-1) {
    set<int> &g = mp[a[i][0]];
    g.insert(i);
    if(g.size() == 2) for(auto v : g) q.push(v);
  }

  // while(q.size()) cout << "q:" << q.front() << endl, q.pop();

  while(q.size()) {
    int i = q.front(); q.pop();
    int top_color = a[i][top_id[i]];
    mp[top_color].erase(i);
    top_id[i]++;
    if(top_id[i] <= limit[i]) {
      top_color = a[i][top_id[i]];
      mp[top_color].insert(i);
      if(mp[top_color].size() == 2) for(auto v : mp[top_color]) q.push(v);
    }
  }

  bool done = true;
  rep(i, 0, m-1) if(top_id[i] <= limit[i]) done = false;
  if(done) cout << "Yes" << endl;
  else cout << "No" << endl;
}
