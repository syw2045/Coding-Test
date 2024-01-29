#include <iostream>

using namespace std;

int main(){

    int N { 0 };
    cin >> N;
    
    int score;
    int total {0};
    int max_score {0};

    for(int i {0}; i<N; i++)
    {
        cin >> score;
        if(max_score < score) max_score = score;
        total += score;
    }
    float answer {0.0};
    answer = total * 100 / static_cast<float>(max_score) / static_cast<float>(N);
    cout << answer << "\n";

    return 0;
}