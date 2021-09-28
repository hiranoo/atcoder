#define _GLIBCXX_DEBUG
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
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;


int main(){
  int n; cin >> n;
  vector<int> next(n+1);
  rep(i, 1, n){
    cin >> next[i];
  }

  int b = 1;
  rep(i, 1, n+5){
    b = next[b];
    if(b == 2){
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
