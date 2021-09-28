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


bool is_prime(ll n){
  if(n <= 1) return false;
  for(ll i = 2; i * i <= n; i++){
    if(n % i == 0) return false;
  }
  return true;
}

int main(){
  string s; cin >> s;

  set<char> kinds;
  rep(i, 0, s.size()-1) kinds.insert(s[i]);
  if(kinds.size() > 5){
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> labels;
  for(int i = 0; i < s.size(); i++){
    int num = distance(kinds.begin(), kinds.find(s[i]));
    labels.emplace_back(num);
  }

  vector<int> array(5);
  array[0] = 1; array[1] = 3; array[2] = 5; array[3] = 7; array[4] = 9;

  //cout << "labels: "; for(auto l : labels) cout << l; cout << endl;

  do {
    //cout << "array: "; for(auto a : array) cout << a; cout << endl;
    ll sum = 0;
    for(auto v : labels){
      sum *= 10;
      sum += array[v];
    }
    if(is_prime(sum)){
      cout << sum << endl;
      return 0;
    }
  } while(next_permutation(array.begin(), array.end()));

  cout << -1 << endl;
  
} 