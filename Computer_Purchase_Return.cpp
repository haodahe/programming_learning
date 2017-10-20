// This program is made by Haoda He
// 2017/10/19
// Solution Computer Purchase Return
// https://dmoj.ca/problem/cco10p4

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    int T, N, B, input_number, input_number2, input_number3, number1;

    cin >> T >> N;

    int input[3001][5] = {};

    for(int i = 0; i < N; i ++){
        cin >> input_number >> input_number2 >> input_number3;
        input_number3 --;
        if(input_number2 > input[input_number][input_number3])
            input[input_number][input_number3] = input_number2;
    }

    cin >> B;

    int chart[B + 1][T] = {};

    for(int j = 1; j < B + 1; j ++){
        chart[j][0] = max(input[j][0], chart[j - 1][0]);
    }

    for(int i = 1; i < T; i ++){
        for(int j = 1; j < B + 1; j ++){
            number1 = 0;

            for(int k = 1; k <= j; k ++){
                if(input[k][i] != 0 && number1 < input[k][i] + chart[j - k][i - 1]){
                    number1 = input[k][i] + chart[j - k][i - 1];
                }
            }
                chart[j][i] = number1;
        }
    }

/*
    for(int i = 0; i < T; i ++){
        for(int j = 0; j < B + 1; j ++){
            cout << chart[j][i] << " ";
        }
        cout << "\n";
    }
*/
    cout << chart[B][T - 1];
}
