#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1);

    for (int i = 0; i < reserve.size(); ++i)
        students[reserve[i] - 1] = 2;
    
    for (int i = 0; i < lost.size(); ++i) {
        if (students[lost[i] - 1] == 2)
            students[lost[i] - 1] = 1;
        else
            students[lost[i] - 1] = 0;
    }
        
    
    int i = 0;
    while (i < n) {
        
        if (students[i] >= 1) {
            ++answer;
        }
        else if (students[i] == 0) {
            if (i != 0 && students[i - 1] == 2) {
                ++answer;
            }
            else if (i != n - 1 && students[i + 1] == 2) {
                --students[i + 1];
                ++answer;
            }
        }
        
        ++i;
    }
    
    return answer;
}
