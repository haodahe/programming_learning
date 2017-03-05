//The answer for CCC '09 S4 - Shop and Ship
//https://dmoj.ca/problem/ccc09s4

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
 int N, T, K, D, i, j, k, m;

    ios_base::sync_with_stdio (false);

    scan(N);

    vector<pair<int, int>> adj[N+1];

    scan(T);

    for(i = 0; i < T; i ++){
        scan(j);
        scan(k);
        scan(m);

        adj[j].push_back(make_pair(k, m));
        adj[k].push_back(make_pair(j, m));
    }

    scan(K);

    int P[N + 1] = {};

    ios_base::sync_with_stdio (false);
    for(i = 0; i < K; i ++){
        scan(j);
        scan(P[j]);
    }

    scan(D);

    queue<int> chart;
    int distance1[N + 1];

    fill_n(distance1, N + 1, 120000000);
    distance1[D] = 0;

    chart.push(D);

    int small = P[D]?P[D]:120000000;

    while(!chart.empty()){
        i = chart.front();

        for(k=0; k<adj[i].size(); k++) {
            j = adj[i][k].first;
            if(distance1[j] > distance1[i] + adj[i][k].second) {
                distance1[j] = distance1[i] + adj[i][k].second;
                chart.push(j);

                if(P[j] > 0 && distance1[j] + P[j] < small){
                    small = distance1[j] + P[j];
                }

            }
        }

        chart.pop();
    }

    cout << small;
}
