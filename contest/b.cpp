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
typedef long long ll;
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005

typedef pair<int, int> Pii;

int main(){
  string s; cin >> s;

  reverse(s.begin(), s.end());

  rep(i, 0, s.size()-1){
    if(s[i] == '6') s[i] = '9';
    else if(s[i] == '9') s[i] = '6';
  }

  cout << s << endl;

  return 0;
}