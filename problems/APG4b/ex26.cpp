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


void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

int x_sum(map<string, int> &x, string s){
  int ans = 0;
  int e = 1; // + or -
  string num = "";
  for(int i = 0; i < s.size(); i++){
    if(s[i] != ' ' && s[i] != '+' && s[i] != '-') {
      num = num + s[i];
    }
    else if(s[i] == '+'){
      e = 1;
      num = "";
    }else if(s[i] == '-'){
      e = -1;
      num = "";
    }else{
      num = (string)num;
      if(x.count(num)) ans += e * x[num];
      else ans += e * stoi(num);
    }
  }
  return ans;
}

int main(){
  int n; cin >> n;

  map<string, int> x;
  map<string, vector<int>> v;

  rep(i, 0, n-1){
    string s; getline(cin, s);
    if(s.substr(0, 3) == "int"){
      string key = "" + s[4];
      int value = x_sum(x, s.substr(8, s.size()-9));
      cout << value << endl;
      x[key] = value;
    }else if(s.substr(0, 9) == "print int"){
      string equation = s.substr(10, s.size()-11);
    }else if(s.substr(0, 3) == "vec"){

    }else if(s.substr(0, 9) == "print_vec"){

    }
  }

  return 0;
}