#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    
    int i, j;
    i = j = 0;
    while(i < dartResult.size()) {
        
        if ('0' <= dartResult[i] && dartResult[i] <= '9') {
            if (dartResult[i + 1] == '0') {
                score.push_back(10);
                ++i;
            }
            else {
                score.push_back(dartResult[i] -'0');
            }
        }
        else if (dartResult[i] == 'S') {
            score[j] = pow(score[j], 1);
            ++j;
        }
        else if (dartResult[i] == 'D') {
            score[j] = pow(score[j], 2);
            ++j;
        }
        else if (dartResult[i] == 'T') {
            score[j] = pow(score[j], 3);
            ++j;
        }
        else if (dartResult[i] == '*') {
            if (i > 3)
                score[j - 2] *= 2;
                
                        score[j - 1] *= 2;
        }
        else if (dartResult[i] == '#') {
            score[j - 1] *= (-1);
        }
        
        ++i;
    }
    
    for (int i = 0; i < 3; ++i)
        answer += score[i];
        
    return answer;
}
