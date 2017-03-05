#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

#define scan(x); do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main()
{
    //ios_base::sync_with_stdio (false);
    //cin.tie(0);
    int N, T, K, D, i, j, k;

    scan(N);

    int C[N + 1][N + 1] = {};

    //cin >> T;
    scan(T);

    for(i = 0; i < T; i ++){
        //cin >> j;
        //cin >> k;
        //cin >> C[j][k];
        scan(j);
        scan(k)
        scan(C[j][k]);

        C[k][j] = C[j][k];
    }

    //cin >> K;
    scan(K);

    int P[N + 1] = {};

    for(i = 0; i < K; i ++){
        //cin >> j;
        //cin >> P[j];
        scan(j);
        scan(P[j]);
    }

    //cin >> D;
    scan(D);
/*
    if(P[D] > 0){
        cout << "===" << P[D] << "===";
    }
*/
    queue<int> chart;
    int distance1[N + 1];

    fill_n(distance1, N + 1, 120000000);
    distance1[D] = 0;

    chart.push(D);

    int small = 120000000;

    if(P[D] > 0 && distance1[D] < small){
        small = P[D];
    }

//#if 0
    while(chart.size()){
        i = chart.front();

        for(j = 0; j < N + 1; j ++){
            if(C[i][j] > 0 && distance1[j] > distance1[i] + C[i][j]){
                distance1[j] = distance1[i] + C[i][j];
                //C[i][j] = 0;
                chart.push(j);

                if(P[j] > 0 && distance1[j] + P[j] < small){
                    small = distance1[j] + P[j];
                }

            }
        }

        chart.pop();
    }
//#endif
/*
    for(i = 0; i < N + 1; i ++){
        if(P[i] > 0){
            distance1[i] += P[i];
            if(distance1[i] < small){
                small = distance1[i];
            }
        }
    }
*/
    cout << small;
}
