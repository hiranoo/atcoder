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
  int p[3] = {0, 0, 0};
  int x, y;
  cin >> x >>y;
  p[x]++; p[y]++;

  if(x == y) {
    cout << x << endl;
    return 0;
  }
  rep(i, 0, 2){
    if(p[i] == 0){
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}