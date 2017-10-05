#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int N, Q, input, input2, input3, test;

    cin >> N;

    test = 1;
    input3 = N - 1;

    int K[N] = {};
    int chart[N] = {};

    for(int i = 0; i < N; i ++)
        cin >> K[i];

    cin >> Q;
    /*
    for(int j = N - 1; j >= 0; j --)
        if(j + K[j] < N)
            chart[j] = chart[j + K[j]] + 1;
        else
            chart[j] = 1;
*/
    for(int i = 0; i < Q; i ++){
        cin >> input;
        //scan(input);

        if(input == 1){
            cin >> input;
            //scan(input);

            if(test == 1){
                for(int j = input3; j >= 0; j --)
                    if(j + K[j] < N)
                        chart[j] = chart[j + K[j]] + 1;
                    else
                        chart[j] = 1;
                test = 0;
            }

            input3 = 0;
            cout << chart[input] << "\n";
        }
        else{
            //cin >> input >> input2;
            //scan(input3);
            cin >> input >> input2;
            //scan(input2);
            K[input] = input2;

            if(input3 < input)
                input3 = input;


            test = 1;
        }
    }
}
