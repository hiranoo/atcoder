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


int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];

  int b4 = 0, nb2 = 0;
  for(auto v : a){
    if(v % 2 != 0) nb2++;
    else if(v % 4 == 0) b4++;
  }
  if(b4 >= nb2) cout << "Yes" << endl;
  else if(b4+1 == nb2 && b4+nb2==n) cout << "Yes" << endl;
  else cout << "No" << endl;
}