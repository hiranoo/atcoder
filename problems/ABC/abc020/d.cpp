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

vector<ll> make_divisors(ll k) {
  vector<ll> ans;
  for(ll i = 1; i*i <= k; i++) {
    if(k%i == 0) {
      ans.push_back(i);
      if(i*i != k) ans.push_back(k/i);
    }
  }
  sort(all(ans));
  return ans;
}

// int main() {
//   ll n, k; cin >> n >> k;
//   map<ll, ll> mp; // (a, b): aの倍数の和

//   vector<ll> divisors = make_divisors(k);
//   reverse(all(divisors));

//   set<ll> calculated;
//   for(auto d : divisors) {
//     mp[d] = (1+(n/d)) * (n/d) / 2 * d % MOD;
//     for(auto itr : calculated) {
//       if(itr % d == 0) mp[d] = (mp[d] - mp[itr]) % MOD;
//     }
//     calculated.insert(d);
//   } 

//   ll ans = 0;
//   for(auto itr : mp) {
//     ans += k/itr.first * itr.second;
//     ans %= MOD;
//   }

//   cout << (ans + MOD) % MOD << endl;
// }

vector<ll> factorize(ll n) {
  vector<ll> ans;
  for(ll i = 2; i*i <= n; i++) {
    int idx = 0;
    while(n%i == 0){
      idx++;
      n/=i;
    }
    if(idx) ans.push_back(i);
  }
  if(n!=1) ans.push_back(n);
  return ans;
}

ll f(ll n, ll k) {
  ll fans = 0;
  vector<ll> v = factorize(k);
  int ps = v.size();
  for(ll s = 0; s < 1LL << ps; s++) {
    int len = 0;
    ll div = 1;
    for(int i = 0; i < ps; i++) if(s>>i & 1) {len++; div *= v[i];}
    
    ll tmp = (1 + (n/div)) * (n/div) / 2 * div % MOD;
    if(len%2 == 0) fans += tmp;
    else fans -= tmp;
    fans %= MOD;
  }

  return fans;
}

int main() {
  ll n, k; cin >> n >> k;
  ll ans = 0;

  for(auto d : make_divisors(k)){
    if(n >= d) ans += k * f(n/d, k/d) % MOD;
    ans %= MOD;
  }

  cout << (ans + MOD) % MOD << endl;
}