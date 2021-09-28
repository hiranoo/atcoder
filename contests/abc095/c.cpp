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

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if(A < B) {
    swap(A, B);
    swap(X, Y);
  }

  if(2*C >= A+B) {
    cout << A*X + B*Y << endl;
    return 0;
  }

  int ans = 0;
  if(X == Y) {
    ans = 2*C * X;
  }
  if(X > Y) {
    ans = 2*C * Y;
    ans += min(A*(X-Y), 2*C*(X-Y));
  }
  if(Y > X) {
    ans = 2*C * X;
    ans += min(B*(Y-X), 2*C*(Y-X));
  }
  cout << ans << endl;
}