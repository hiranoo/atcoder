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
#define INF 1000000

int myceil(float t){
  return (int)ceil(t);
}

int main(){
  int n; cin >> n;
  vector<int> t(n);
  int total = 0;
  rep(i, 0, n-1){
    cin >> t[i];
    total += t[i];
  }
  sort(all(t), greater<int>());
  
  int l = -1, r = 100005;
  while(r-l > 1){
    int x = (l+r)/2;
    bool c = false;

    if(x >= myceil(total/2.0)){
      
    }

    if(c) r = x;
    else l = x;
  }

  return 0;
}