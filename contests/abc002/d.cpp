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
	int n, m;
	int rel[12] = {0};
	rep(i, 0, m-1){
		int x,y;
		cin >> x >> y;
		rel[x-1] |= (1 << (y-1));
	}

	rep(i, 0, n-1){
		while(rel[i] != rel[rel[i]] )
		rel[i] |= rel[rel[i]];
	}


	return 0;
}
