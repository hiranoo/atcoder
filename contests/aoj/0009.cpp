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
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

int main(){
  vector<int> input(0);
  int in;
  while(!cin.eof()){
    cin >> in;
    input.push_back(in);
    if(in == 0) break;
  }

  for(int n : input){
    vector<bool> is_prime(n+1, true);
    for(int i = 2; i * i <= n; i++){
      for(int j = 2*i; j <= n; j += i){
        is_prime[j] = false;
      }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
      if(is_prime[i]) ans++;
    }
    
    cout << ans << endl;
  }
}