#include <iostream>
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
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


int main(){
  int n, m, k;
  cin >> n >> m >> k;
  sum = comb[n+m][n];
  rep(i, 0, n+m-1){
    if((i)%k == 0) sum -= total_comb[i+1][i/k];
  }

  cout << max(0, sum) << endl;
  return 0;
}