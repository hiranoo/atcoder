// 正方行列のライブラリ

struct Matrix{
  ll MOD = 1000000007;
  int sz;
  vector< vector<ll> > x;
  
  Matrix (int n) : sz(n), x(n, vector<ll>(n, 0)) {}

  // Matrix Aについて、A[i][j]を可能にする
  inline const vector< T > &operator[](int k) const {
    return (A.at(k));
  }

  inline vector< T > &operator[](int k) {
    return (A.at(k));
  }
  
  // 掛け算 O(N^3)
  Matrix operator* (Matrix &b){
    Matrix mul(sz);
    rep(i, 0, sz-1) rep(j, 0, sz-1) rep(k, 0, sz-1) {
      mul.x[i][j] += x[i][k] * b.x[k][j];
      mul.x[i][j] %= MOD;
    }
    return mul;
  }

  // 行列のN乗をO(log(n))で計算　(1e18) 乗までOK
  Matrix powers(ll n){
    vector<Matrix> p(63, Matrix(sz));
    Matrix res(sz); rep(i, 0, sz-1) res.x[i][i] = 1;

    p[0].x = x;
    rep(i, 1, 62) p[i] = p[i-1] * p[i-1];
    
    rep(i, 0, 62){
      if(n & 1LL << i) res = res * p[i];
    }

    return res;
  }
};