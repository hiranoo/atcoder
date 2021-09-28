vector<int> f(vector<int> &a) {
  int n = a.size();
  vector<int> dp(n, INF); // dp[i]:= 長さi+1の増加部分列のとりうる末尾の最小値
  vector<int> b(n); // a[i]を末尾とする増加部分列の最大長をメモする

  rep(i, 0, n-1) {
    int j = lower_bound(all(dp), a[i]) - dp.begin();
    b[i] = j+1;
    dp[j] = a[i];
  }
  return b;
}