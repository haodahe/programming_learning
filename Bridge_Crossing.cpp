#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int M, Q;

    cin >> M >> Q;

    string input_name[Q];
    int input_speed[Q];

    for(int i = 0; i < Q; i ++){
        cin >> input_name[Q - i - 1];
        cin >> input_speed[Q - i - 1];
    }

    int answer[Q];
    int answer2[Q];

    answer[0] = input_speed[0];
    answer2[0] = 1;

    for(int i = 1; i < Q; i ++){
        int max_number = input_speed[i];
        answer[i] = input_speed[i] + answer[i - 1];
        int min_number = 99999999;
        int min_number2;
        answer2[i] = 1;

        for(int j = 1; j < min(M, i + 1); j ++){
            if(input_speed[i - j] > max_number){
                max_number = input_speed[i - j];
            }
            if(i - j - 1 >= 0 && answer[i - j - 1] + max_number < min_number){
                min_number = answer[i - j - 1] + max_number;
                min_number2 = j + 1;
            }
            if(i - j == 0 && max_number < min_number){
                min_number = max_number;
                min_number2 = j + 1;
            }
        }
        answer[i] = min(min_number, answer[i]);
        if(answer[i] == min_number)
            answer2[i] = min_number2;
    }

    cout << "Total Time: " << answer[Q - 1] << "\n";
    /*
    for(int i = 0; i < Q; i++)
        cout << answer2[i] << " ";
*/

    int i = Q - 1;

    while(i >= 0) {
        for(int j = 0; j < answer2[i]; j++)
            cout << input_name[i - j] << " ";
        cout << "\n";

        i = i - answer2[i];
    }
}
