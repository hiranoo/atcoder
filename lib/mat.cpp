struct Mat {
  int n;
  vector<vector<ll>> m;
  Mat() {}
  Mat(int _n) {
    n = _n;
    m = vector<vector<ll>>(n, vector<ll>(n, 0));
  }

  void set(int i, int j, ll v) {
    m[i][j] = v;
  }

  ll get(int i, int j) {
    return m[i][j];
  }

  int size() {
    return n;
  }

  void show() {
    cout << endl;
    rep(i, 0, n-1) {
      rep(j, 0, n-1) cout << m[i][j] << " ";
      cout << endl;
    }cout << endl;
  }

  Mat operator*(const Mat &M) {
    Mat B(n);
    rep(i, 0, n-1) rep(j, 0, n-1) rep(k, 0, n-1) B.m[i][j] += m[i][k] * M.m[k][j] % MOD, B.m[i][j] %= MOD;
    return B;
  }
};

Mat matpow(Mat A, int n) {
  int s = A.size();
  Mat B(s);
  rep(i, 0, s-1) B.set(i, i, 1);
  while(n > 0) {
    if(n & 1) B = B * A;
    A = A * A;
    n >>= 1;
  }
  return B;
}