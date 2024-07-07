#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int weight = 0, height = 0;

    for(int i=0; i<sizes.size(); i++){
        weight = max(weight, max(sizes[i][0], sizes[i][1]));
        height = max(height, min(sizes[i][0], sizes[i][1]));
    }
    answer = weight * height;
    return answer;
}