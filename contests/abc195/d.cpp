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

/**
 * segment treeは単純にやるとダメ。
 * 同じ重さの荷物が複数あると、上書きされて1つの荷物として扱われるから。
 * 正しくは、重複を許さないといけない。
 */
pii op(pii a, pii b) {
  return max(a, b);
}

pii e() {
  return pii(0, -1);
}

int main() {
  int n, m, Q; cin >> n >> m >> Q;
  vector<pii> item(n);
  rep(i, 0, n-1) cin >> item[i].first >> item[i].second;
  vector<int> x(m);
  rep(i, 0, m-1) cin >> x[i];

  sort(all(item));

  map<int, deque<int>> mp;
  rep(i, 0, n-2) if(item[i].first == item[i+1].first) mp[item[i].first].push_front(item[i].second);

  atcoder::segtree<pii, op, e> seg(1000005);
  while(Q--) {
    int l, r; cin >> l >> r; l--, r--;
    vector<int> box;
    rep(i, 0, m-1) if(i < l || r < i) box.push_back(x[i]);
    sort(all(box));
    for(pii p : item) seg.set(p.first, pii(p.second, p.first));

    int ans = 0;
    for(int b : box) {
      pii p = seg.prod(0, b+1);
      if(p.first > 0) {
        ans += p.first;
        if(mp.count(p.second) && mp[p.second].size()) {
          seg.set(p.second, pii(mp[p.second].front(), p.second));
          mp[p.second].pop_front();
        }else{
          seg.set(p.second, pii(0, -1));
        }
      }
    }
    cout << ans << endl;
  }
}

/**
 * Priority Queue を使うと楽
 */
int main() {
  int n, m, Q; cin >> n >> m >> Q;
  vector<pii> item(n);
  rep(i, 0, n-1) cin >> item[i].first >> item[i].second;
  vector<int> x(m);
  rep(i, 0, m-1) cin >> x[i];

  sort(all(item));

  while(Q--) {
    int l, r; cin >> l >> r; l--, r--;
    vector<int> box;
    rep(i, 0, m-1) if(i < l || r < i) box.push_back(x[i]);
    sort(all(box));
    priority_queue<int, vector<int>> q;
    int cur = 0;
    int ans = 0;
    for(auto b : box) {
      while(cur < n && item[cur].first <= b) {
        q.push(item[cur].second);
        cur++;
      }
      if(q.size()) {
        ans += q.top();
        q.pop();
      }
    }
    cout << ans << endl;
  }
}