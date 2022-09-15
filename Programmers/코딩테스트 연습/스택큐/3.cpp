#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;

    int truck_num = 0;
    int total = 0;
    while (1)
    {
        if (q.size() == bridge_length)
        {
            total -= q.front();
            q.pop();
        }
        if (truck_num >= truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        if (q.size() < bridge_length && truck_weights[truck_num] + total <= weight)
        {
            q.push(truck_weights[truck_num]);
            total += truck_weights[truck_num];
            truck_num++;
        }
        else q.push(0);
        
        answer++;
    }
    return answer;
}