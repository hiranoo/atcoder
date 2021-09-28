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
#include <fstream>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1e9+7;


int main(){
  ifstream ifs("output");
  string str;
  if(ifs.fail()){
    cerr << "failed to open file." << endl;
    return -1;
  }

  while(getline(ifs, str)){
    for(auto s : str){
      if(s == '(') cout << 0;
      else cout << 1;
    }
    cout << endl;
  }
  return 0;
}