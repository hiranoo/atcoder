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
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e16;

int main() {
  int n, k; cin >> n >> k;
  vector<int> cnt(n+1, 0);
  vector<bool> is_prime(n+1, true);
  
  for(int i = 2; i*i <= n; i++) {
    if(is_prime[i]) {
      for(int j = 2*i; j <= n; j+=i) {
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i <= n; i++) {
    if(!is_prime[i]) continue;
    for(int j = i; j <= n; j+=i) cnt[j]++;
  }

  int ans = 0;
  rep(i, 2, n) if(cnt[i] >= k) ans++;
  cout << ans << endl;
}