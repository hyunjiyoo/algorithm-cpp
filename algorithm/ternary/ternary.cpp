#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> ternary;
    while (n > 0) {
        ternary.push_back(n % 3);
        n /= 3;
    }
    
    int i = (int)ternary.size() - 1;
    int j = 0;
    while (i >= 0)
        answer += (ternary[i--] * pow(3, j++));
    
    return answer;
}
