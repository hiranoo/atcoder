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

bool correct(string s){
  int n = s.size();
  vector<bool> used(n, false);
  for(int i = 0; i < n; i++){
    if(s[i] == '(' || used[i]) continue;
    int j = i-1;
    bool found = false;
    while(j >= 0){
      if(s[j] == ')' || used[j]) {
        j--; continue;
      }
      used[j] = true;
      found = true;
      break;
    }
    if(found) continue;
    if(j < 0) return false;
  }
  return true;
}

int main(){
  int n; cin >> n;
  
  if(n % 2 != 0) {
    //cout << endl;
    return 0;
  }

  vector<string> total;
  for(int i = 0; i < (1 << n); i++){
    string s = "";
    int tmp = 0;
    for(int j = n-1; j >= 0; j--){
      if(i & (1 << j)) {
        s.push_back(')');
        tmp++;
      }
      else s.push_back('(');
    }
    if(tmp*2 == n && correct(s)) total.push_back(s);
  }

  for(auto s : total){
    cout << s << endl;
  }
}