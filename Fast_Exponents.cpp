#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main()
{
    long long N, M;
    cin >> N;

    for(int i = 0; i < N; i ++){
        scan(M);

        if((M & (M - 1)) == 0)
            cout << "T\n";
        else
            cout << "F\n";
    }
}
