#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> counts(3, 0);
    
    vector<int> way1 = {1,2,3,4,5};
    vector<int> way2 = {2,1,2,3,2,4,2,5};
    vector<int> way3 = {3,3,1,1,2,2,4,4,5,5};
    
    int i = 0;
    int max = -1;
    while (i < answers.size()) {
        
        if (answers[i] == way1[i % way1.size()])
            ++counts[0];
        
        if (answers[i] == way2[i % way2.size()])
            ++counts[1];
        
        if (answers[i] == way3[i % way3.size()])
            ++counts[2];
        
        if (counts[0] >= max) max = counts[0];
        if (counts[1] >= max) max = counts[1];
        if (counts[2] >= max) max = counts[2];
        
        ++i;
    }
    
    for (int i = 0; i < 3; ++i) {
        if (counts[i] == max)
            answer.push_back(i + 1);
    }

    return answer;
}
