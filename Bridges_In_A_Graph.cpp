#include <bits/stdc++.h>
using namespace std;

void find_path(bool input[][101], bool visit[], int number, int number2, int N, int (*conection)[101][101]){
    visit[number] = true;

    bool visit2[N + 1] = {};
    (*conection)[number2][number] ++;
/*
    for(int i = 1; i <= N; i ++)
        cout << visit[i] << " ";
    cout << "\n";
    cout << "\n";
*/

    //cout << number << "\n";

    for(int i = 1; i <= N; i ++){
        if(input[number][i] && !visit[i]){
            for(int j = 1; j <= N; j ++)
                visit2[j] = visit[j];

            //(*conection)[number][i] ++;
            find_path(input, visit2, i, number2, N, conection);
        }
    }
/*
    for(int i = 1; i <= N; i ++)
        cout << visit[i] << " ";
    cout << "\n";
    cout << "\n";
*/
}



int main()
{
    int N, M, input1, input2, answer;

    for(int loop = 0; loop < 5; loop ++){
        answer = 0;

        cin >> N >> M;

        bool input[N + 1][101] = {};
        int input_array[M][2];

        for(int i = 0; i < M; i ++){
            cin >> input1 >> input2;
            input_array[i][0] = input1;
            input_array[i][1] = input2;
            input[input1][input2] = true;
            input[input2][input1] = true;
        }

        int conection[101][101] = {};
    /*
        for(int i = 1; i <= N; i ++){
            queue<int> chart;
            chart.push(i);

            bool visit[N + 1] = {};
            visit[i] = true;

            while(!chart.empty()){
                j = chart.front();
                chart.pop();

                for(int k = 1; k <= N; k ++){
                    if(input[j][k]){
                        if(!visit[k]){
                            cout << j << " " << k << "\n";
                            chart.push(k);
                            visit[k] = true;
                        }

                        conection[i][k] ++;
                    }
                }
            }
            cout << "OVER\n";
        }
    */

        for(int i = 1; i <= N; i ++){
            bool visit[N + 1] = {};
            find_path(input, visit, i, i, N, &conection);
        }

        /*
        for(int i = 1; i <= N; i ++){
            for(int j = 1; j <= N; j ++)
                cout << conection[i][j] << " ";
            cout << "\n";
        }
*/

        for(int i = 0; i < M; i ++){
            if(conection[input_array[i][0]][input_array[i][1]] == 1)
                answer ++;
        }

        cout << answer << "\n";
    }
}
