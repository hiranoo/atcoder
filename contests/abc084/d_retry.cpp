#include <bits/stdc++.h>
// #include <atcoder/segtree>
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

vector<bool> make_likes(int n) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  vector<bool> ans(n+1, false);
  for(int i = 2; i * i <= n; i++) {
    if(is_prime[i]) {
      for(int j = i*2; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  rep(i, 3, n) if(is_prime[i] && is_prime[(i+1)/2]) ans[i] = true;
  return ans;
}

int main() {
  int q; cin >> q;
  vector<bool> likes = make_likes(100000);
  vector<int> sum(100005, 0);
  
  rep(i, 3, 100000) {
    sum[i] = sum[i-1];
    if(likes[i]) sum[i]++;
  }

  rep(i, 0, q-1) {
    int l, r; cin >> l >> r;
    cout << sum[r] - sum[l-1] << endl;
  }
}