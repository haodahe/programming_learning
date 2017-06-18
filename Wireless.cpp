#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;


int main()
{
    int M, N, K, x, y, B, R, number, number2;

    cin >> M >> N >> K;

    int chart[M + 1][N + 1] = {};
    int answer[M + 1][N + 1] = {};

    for(int i = 0; i < K; i ++){
        cin >> y >> x >> R >> B;

        for(int j = max(y - R, 1); j <= min(y + R, N); j ++){
            number2 = y - j;

            if(number2 < 0)
                number2 *= -1;

            number2 *= number2;
            number = R * R;
            number -= number2;
            number = sqrt(number) / 1;

            chart[max(x - number, 1)][j] += B;
            if(x + number + 1 <= M)
                chart[x + number + 1][j] -= B;
        }
    }

    int max_number = 0;

    for(int i = 1; i < N + 1; i ++){
        for(int j = 1; j < M + 1; j ++){
            answer[j][i] = answer[j - 1][i] + chart[j][i];
            if(answer[j][i] > max_number)
                max_number = answer[j][i];
        }
    }

    int max_number2 = 0;

    for(int i = 1; i < M + 1; i ++){
        for(int j = 1; j < N + 1; j ++){
            if(answer[i][j] == max_number)
                max_number2 ++;
        }
    }

    cout << max_number << "\n" << max_number2;
}
