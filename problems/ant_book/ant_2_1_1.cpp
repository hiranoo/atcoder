#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

int n, k;
int a[20] = {};

bool dfs(int i, int sum){
	// すべて見た結果
	if (i == n) return sum==k;
	
	// sum > k
	if(sum > k) return false;

	// sum == k
	if(sum ==k) return true;

	// sum < k
	// a[i] を含むとき
	return dfs(i+1, sum + a[i]) || dfs(i+1, sum);
}

int main(){
	cin >> n >> k;
	rep(i, 0, n-1){
		cin >> a[i];
	}

	cout << dfs(0,0) << endl;

	return 0;
}
