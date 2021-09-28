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
const ll INF = 1e18;

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  deque<int> q;

  rep(i, 0, k-1) {
    if(q.size()==0) q.push_front(i);
    if(a[q.front()] > a[i]) q.push_front(i);
    else if(a[q.top()] < a[i]) q.push_back(i);
  }

  vector<int> b;
  b.push_back(a[q.front()]);
  
  rep(i, 0, n-k) {
    b.push_back(a[q.front()]);
  }
}