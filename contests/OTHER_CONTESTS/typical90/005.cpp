#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
using mint = modint1000000007;

template< class T >
struct Matrix {
  int MOD = 1000000007;
  vector< vector< T > > A;

  Matrix() {}

  Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)) {}

  Matrix(size_t n) : A(n, vector< T >(n, 0)) {};

  size_t height() const {
    return (A.size());
  }

  size_t width() const {
    return (A[0].size());
  }

  inline const vector< T > &operator[](int k) const {
    return (A.at(k));
  }

  inline vector< T > &operator[](int k) {
    return (A.at(k));
  }

  static Matrix I(size_t n) {
    Matrix mat(n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }

  Matrix &operator+=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
        (*this)[i][j] += B[i][j] % MOD;
        (*this)[i][j] %= MOD;
      }
    return (*this);
  }

  Matrix &operator-=(const Matrix &B) {
    size_t n = height(), m = width();
    assert(n == B.height() && m == B.width());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
        (*this)[i][j] -= B[i][j] % MOD;
        (*this)[i][j] %= MOD;
      }
    return (*this);
  }

  Matrix &operator*=(const Matrix &B) {
    size_t n = height(), m = B.width(), p = width();
    assert(p == B.height());
    vector< vector< T > > C(n, vector< T >(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        for(int k = 0; k < p; k++){
          C[i][j] = (C[i][j]+ (*this)[i][k] * B[k][j]) % MOD;
        }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) C[i][j] %= MOD;
    A.swap(C);
    return (*this);
  }

  Matrix operator+(const Matrix &B) const {
    return (Matrix(*this) += B);
  }

  Matrix operator-(const Matrix &B) const {
    return (Matrix(*this) -= B);
  }

  Matrix operator*(const Matrix &B) const {
    return (Matrix(*this) *= B);
  }

  Matrix operator^(const long long k) const {
    return (Matrix(*this) ^= k);
  }
  
  friend ostream &operator<<(ostream &os, Matrix &p) {
    size_t n = p.height(), m = p.width();
    for(int i = 0; i < n; i++) {
      os << "[";
      for(int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }
};

int main();
int main1();
int main2();

int main(){
  main2();
}

int main1(){
  ll N; int B, K;
  cin >> N >> B >> K;
  vector<int> c(K);
  rep(i, 0, K-1) cin >> c[i];

  vector<vector<int>> dp(N+1, vector<int>(B, 0));
  

  dp[0][0]=1;
  rep(i, 0, N-1){
    rep(j, 0, B-1){
      rep(k, 0, K-1){
        int nj = (10*j + c[k])%B;
        dp[i+1][nj] += dp[i][j];
        dp[i+1][nj] %= MOD;
      }
    }
  }
  cout << dp[N][0] << endl;
  return 0;
}

int main2(){
  ll N; int B, K;
  cin >> N >> B >> K;
  vector<int> c(K);
  rep(i, 0, K-1) cin >> c[i];

  Matrix<ll> A(B);
  rep(r, 0, B-1){
    rep(k, 0, K-1){
      A[(10*r+c[k])%B][r]++;
    }
  }

  // AA[i]: A^(i)
  vector<Matrix<ll>> AA(62, Matrix<ll>(B));
  AA[0] = A;
  rep(i, 1, 61) AA[i] = AA[i-1] * AA[i-1];

  Matrix<ll> mul(B);
  rep(i, 0, B-1) mul[i][i] = 1;
  cout << N << " = ";
  for(int i = 0; i < 61; i++){
    if(N < 1 << i) break;
    if(N & 1 << i) {
      printf("2^%d + ", i);
      mul *= AA[i];
    }
  }cout << endl;

  cout << (MOD + mul[0][0]) % MOD << endl;

  rep(i, 0, 6) cout << "A[2^" << i << "]\n" << AA[i] << endl;
  return 0;
}