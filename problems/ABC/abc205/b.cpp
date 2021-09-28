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
  int n; cin >> n;
  vector<int> a(n);
  rep(i, 0, n-1) cin >> a[i];
  
  sort(all(a));
  
  rep(i, 0, n-1){
    if(a[i] != i + 1){
      cout << "No" << endl;
      return 0;
    } 
  }

  cout << "Yes" << endl;
  
  return 0;
}