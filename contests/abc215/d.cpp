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
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  int max_a = 0;
  rep(i, 0, n-1) max_a = max(max_a, a[i]);

  vector<bool> as(max_a+1, false);
  for(int i : a) as[i] = true;

  vector<int> codivisor;
  rep(i, 2, max_a) {
    bool f = false;
    for(int j = i; j <= max_a; j += i) if(as[j]) {
      f = true;
      break;
    }
    if(f) codivisor.push_back(i);
  }

  vector<bool> ok(m+1, true);
  for(int d : codivisor) for(int j = d; j <= m; j += d) ok[j] = false;

  int cnt = 0;
  rep(i, 1, m) if(ok[i]) cnt++;
  cout << cnt << endl;
  rep(i, 1, m) if(ok[i]) cout << i << endl;
}

// vector<int> factorize(int n) {
//   vector<int> ans;
//   for(int i = 2; i*i <= n; i++) {
//     int idx = 0;
//     while(n%i==0) idx++, n/=i;
//     if(idx>0) ans.push_back(i);
//   }if(n>1) ans.push_back(n);
//   return ans;
// }

// int main() {
//   int n, m; cin >> n >> m;
//   vector<int> a(n);
//   rep(i, 0, n-1) cin >> a[i];

//   set<int> ng_primes;
//   for(int i : a) for(int p : factorize(i)) ng_primes.insert(p);

//   // for(auto p : ng_primes) cout << p << " "; cout << endl;

//   vector<bool> ok(m+1, true);
//   rep(i, 1, m) {
//     for(int p : ng_primes) {
//       if(i < p) break;
//       if(i % p == 0) {
//         ok[i] = false;
//         break;
//       }
//     }
//   }
//     // cout << i << " ";
//   // }cout << ":debug" << endl;

//   int cnt = 0;
//   rep(i, 1, m) if(ok[i]) cnt++;
//   cout << cnt << endl;
//   rep(i, 1, m) if(ok[i]) cout << i << endl;
// }

// int main() {
//   int n, m; cin >> n >> m;
//   vector<int> a(n);
//   rep(i, 0, n-1) cin >> a[i];

//   vector<bool> is_prime(351, true);
//   is_prime[0] = is_prime[1] = false;

//   for(int i = 2; i*i <= 100005; i++) {
//     if(is_prime[i]) {
//       for(int j = i*2; j <= 350; j += i) {
//         is_prime[j] = false;
//       }
//     }
//   }

//   vector<int> primes;
//   rep(i, 2, 350) if(is_prime[i]) primes.push_back(i);

//   rep(i, 0, n-1) {
//     for(auto p : primes) {
//       while(a[i] % p == 0) a[i] /= p; 
//     }
//     if(a[i] > 1) primes.push_back(a[i]);
//   }
  
//   for(auto p : primes) cout << p << " "; cout << endl;

//   vector<bool> ok(m+1, true);
//   for(auto p : primes) {
//     rep(i, 2, m) if(i%p == 0) ok[i] = false;
//   }

//   int cnt = 0;
//   rep(i, 1, m) if(ok[i]) cnt++;
//   rep(i, 1, m) if(ok[i]) cout << i << endl;
// }