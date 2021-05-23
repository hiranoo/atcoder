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
    long d, g;
    cin >> d >> g;
    int p[11] = {0};
    long c[11] = {0};

    for(int i = 0; i < d; i++){
        cin >> p[i] >> c[i];
    }

    long minc = 10000000;

    // どの難易度の問題を完答するかの全探索
    for(long msk = 0; msk < (1 << d); msk++){
        long sum = 0;
        long cnt = 0;

        for(int i = 0; i < d; i++){
            if(msk & (1 << (d-1-i))){
                sum += 100*(i+1)*p[i] + c[i];
                cnt += p[i];
            }
        }
        //cout << bitset<10>(msk) << " sum:" << sum << " cnt:" << cnt << endl;
        if(sum >= g){
            minc = fmin(minc, cnt);
        }else{
            // 難易度が高い順に残りの問題を解く gまで
            bool flag = false;
            for(int i = d-1; i >=0 && !flag; i--){
                if(!(msk & (1 << (d-1-i)))){
                    /*
                    for(int k = 1; k < p[i]; k++){
                        sum += 100*(i+1);
                        cnt ++;
                        if(sum >= g){
                            minc = fmin(minc, cnt);
                            flag = true;
                        }
                    }*/
                    int ex = (g-sum)/(100*(i+1));
                    ex += (g-sum)%(100*(i+1)) != 0;
                    ex = min(p[i]-1, ex);
                    sum += ex*100*(i+1);
                    cnt += ex;
                    if(sum >= g){
                        minc = fmin(minc, cnt);
                        break;
                    }
                }
            }
        }
    }

    cout << minc << endl;
    return 0;
}