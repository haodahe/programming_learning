/*
This programe is made by Haoda He
The solution for CCC '16 S4 - Combining Riceballs
https://dmoj.ca/problem/ccc16s4
*/
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int N;

    cin >> N;

    int chart[N][N] = {};

    for(int i = 0; i < N; i ++)
        cin >> chart[i][i];
    while(1){
        int test = 0;

        for(int i = 0; i < N; i ++){
            for(int j = i; j < N; j ++){
                if(chart[i][j] != 0)
                    for(int k = j; k < N; k ++)
                        if(chart[j + 1][k] != 0){
                            if(chart[i][j] == chart[j + 1][k] && chart[i][k] == 0){
                                chart[i][k] = chart[i][j] * 2;
                                test = 1;
                            }

                            for(int l = k; l < N; l ++)
                                if(chart[i][j] == chart[k + 1][l] && chart[i][l] == 0){
                                    chart[i][l] = chart[i][j] * 2 + chart[j + 1][k];
                                    test = 1;
                                }
                        }
            }
        }

/*
        for(int i = 0; i < N; i ++){
            for(int j = i; j < N; j ++)
                cout << chart[i][j] << " ";
            cout << "\n";
        }

        cout << "\n";
*/
        if(test == 0)
            break;
    }

    int max_number = 0;

    for(int i = 0; i < N; i ++)
        for(int j = i; j < N; j ++)
            if(max_number < chart[i][j])
                max_number = chart[i][j];

    cout << max_number;
}
