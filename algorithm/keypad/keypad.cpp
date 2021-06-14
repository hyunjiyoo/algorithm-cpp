#include <string>
#include <cmath>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int i = 0;
    int y, x, ly, lx, ry, rx;
    ly = ry = 3; lx = 0; rx = 2;
    
    while (i < numbers.size()) {
        if (numbers[i] == 0)
            numbers[i] = 11;
        
        y = (numbers[i] - 1) / 3;
        x = (numbers[i] - 1) % 3;
        
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            ly = y;
            lx = x;
        }
        
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            ry = y;
            rx = x;
        }
        
        else {
            int ldistance = abs(y - ly) + abs(x - lx);
            int rdistance = abs(y - ry) + abs(x - rx);
            
            if (ldistance < rdistance) {
                answer += 'L';
                ly = y;
                lx = x;
            }
            else if (ldistance > rdistance) {
                answer += 'R';
                ry = y;
                rx = x;
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    ry = y;
                    rx = x;
                }
                else {
                    answer += 'L';
                    ly = y;
                    lx = x;
                }
            }
        }
        
        ++i;
    }
    
    return answer;
}
