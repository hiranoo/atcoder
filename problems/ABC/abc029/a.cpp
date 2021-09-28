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

int main(){
	int n;
	cin >> n;
	int t[n];
	rep(i, 0, n-1){
		cin >> t[i];
	}

	int ans = 10000;
	for(int msk=0; msk < (1 << n); msk++){
		bitset<4> s(msk);
		cout << "bitset: " << s << endl;
		int tmp1 = 0;
		int tmp2 = 0;
		for(int i = 0; i < n; i++){
			if(msk & (1 << i)){
				tmp1 += t[i];
			}else{
				tmp2 += t[i];
			}
		}
		ans = min(ans, max(tmp1, tmp2));
	}

	cout << ans << endl;

	return 0;
}
