#include <iostream>

using namespace std;

int main()
{
    string sentence;
    int P, S;
    cin >> P >> S;
    cin >> sentence;

    int A, C, G, T;
    cin >> A >> C >> G >> T;

    int start_idx = 0;
    int end_idx = start_idx + S - 1;

    int cnt_A = 0, cnt_C = 0, cnt_G = 0, cnt_T = 0;
    int rest = 0;
    for(int i = 0; i<S; i++)
    {
        if(sentence[i] == 'A') cnt_A++;
        else if(sentence[i] == 'C') cnt_C++;
        else if(sentence[i] == 'G') cnt_G++;
        else if(sentence[i] == 'T') cnt_T++;
        else rest++;
    }

    int answer = 0;
    for(int i =0; i< P-S+1; i++)
    {
        if(A <= cnt_A && C <= cnt_C && G <= cnt_G && T <= cnt_T && rest == 0) answer++;
        
        if(sentence[start_idx] == 'A') cnt_A--;
        else if(sentence[start_idx] == 'C') cnt_C--;
        else if(sentence[start_idx] == 'G') cnt_G--;
        else if(sentence[start_idx] == 'T') cnt_T--;
        else rest--;
        
        start_idx++;
        end_idx++;

        if(sentence[end_idx] == 'A') cnt_A++;
        else if(sentence[end_idx] == 'C') cnt_C++;
        else if(sentence[end_idx] == 'G') cnt_G++;
        else if(sentence[end_idx] == 'T') cnt_T++;
        else rest++;
    }

    cout << answer << "\n";
    return 0;
}