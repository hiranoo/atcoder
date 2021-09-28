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
  priority_queue<int> a;
  rep(i, 0, n-1){
    int buf; cin >> buf;
    a.push(buf);
  }

  int ans = 0; int turn = 1;
  while(a.size()){
    int card = a.top(); a.pop();
    ans += card * turn;
    turn = -turn;
  }
  cout << ans << endl;
      
  return 0;
}
