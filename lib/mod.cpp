// O(log m)
ll modpow(ll a, ll p, ll m) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = ans * a % m;
    a = a * a % m;
    p >>= 1;
  }
  return ans;
}

// O(log m)
ll modinv(ll a, ll m) {
  return modpow(a, m-2, m);
}

// O(log m)
ll euler_modinv(ll a, ll m) {
  ll _m = m;
  vector<ll> ps;
  for(ll i = 2; i * i <= m; i++) {
    int idx = 0;
    while(m % i == 0) {
      idx++;
      m /= i;
    }
    if(idx>0) ps.push_back(i);
  }if(m != 1) ps.push_back(m);

  ll phi = _m;
  for(ll p : ps) phi = phi * (p-1) / p;

  return modpow(a, phi-1, _m);
}

// O(N)
vector<ll> modinvs(ll n, ll p) {
  vector<ll> ans(n+1);
  ans[0] = 0;
  ans[1] = 1;
  rep(i, 2, n) ans[i] = (-p/i * ans[p%i] + p) % p;
  return ans;
}

// O(N)
ll mod_factorial(ll n, ll p) {
  ll ans = 1;
  vector<ll> vec = modinvs(n, p);
  rep(i, 2, vec.size()-1) {
    ans = (ans * vec[i]) % p;
  }
  return (ans + p) % p;
}

// O(N)
ll mod_comb(ll n, ll k, ll p) {
  ll ans = 1;
  rep(i, 1, n) ans = (ans * i) % p;
  if(n>k && k>0) {
    ans = ans * mod_factorial(n-k, p) % p;
    ans = ans * mod_factorial(k, p) % p;
  }else if(n==k || k==0) {
    ans = 1;
  }else{
    ans = 0;
  }
  return (ans + p) % p;
}

// 連立合同式
pll mod_simultaneous(vector<ll> &a, vector<ll> &b, vector<ll> &m) {
  ll x = 0, m = 1;
  int n = a.size();
  rep(i, 0, n-1) {
    ll a = a[i] * m;
    ll b = b[i] - a[i] * x;
    ll d = __gcd(a, m[i]);
    if(b % d != 0) return pll(0, -1);
    ll t = modinv(a/d, m[i]/d) * b/d % (m[i]/d);
    x = x + m * t;
    m *= m[i]/d;
  }
  return pll(x % m, m);
}

