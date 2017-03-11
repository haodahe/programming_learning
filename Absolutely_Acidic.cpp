#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int N, number, i;

    cin >> N;

    int R[1002] = {};

    for(int i = 0; i < N; i ++){
        cin >> number;
        R[number] ++;
    }

    int big = 0;
    int big2 = 0;
    int index, index2;

    for(i = 0; i < 1002; i ++){
        if(big < R[i]){
            big = R[i];
            index = i;
        }
    }

    for(i = 0; i < 1002; i ++){
        if(big2 < R[i] && i != index)
            big2 = R[i];
    }

    for(i = 0; i < 1002; i ++){
        if(big == R[i])
            index = i;
    }

    for(i = 1001; i > 0; i --){
        if(big2 == R[i] && i != index)
            index2 = i;
    }

    int answer1 = index - index2;

    for(i = 1001; i > 0; i --){
        if(big == R[i])
            index2 = i;
    }

    for(i = 0; i < 1002; i ++){
        if(big2 == R[i] && i != index2)
            index = i;
    }

    int answer2 = index - index2;

    if(answer1 < answer2)
            answer1 = answer2;
    cout << answer1;
}
