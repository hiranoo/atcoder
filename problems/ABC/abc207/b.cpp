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

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  if(b >= c*d) {
    cout << -1 << endl;
    return 0;
  }

  int x = c*d -b;
  if(a % x == 0) {
    cout << a/x << endl;
  }else{
    int ans = a/x + 1;
    cout << ans << endl;
  }
}