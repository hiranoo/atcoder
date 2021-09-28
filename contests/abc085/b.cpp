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
#define INF 100000

int main(){
  int n; cin >> n;
  set<int> d;
  rep(i, 0, n-1){
    int buf; cin >> buf;
    d.insert(buf);
  }

  cout << d.size() << endl;

  return 0;
}