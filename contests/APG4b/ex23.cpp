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
  ll max_a = 0;
  int max_num = 0;

  map<ll, int> cnt;
  rep(i, 0, n-1){
    ll a; cin >> a;
    if(cnt.count(a)){
      cnt[a]++;
    }else{
      cnt[a] = 1;
    }
    if(cnt[a] > max_num){
      max_a = a;
      max_num = cnt[a];
    }
  }

  cout << max_a << " " << max_num << endl;
}