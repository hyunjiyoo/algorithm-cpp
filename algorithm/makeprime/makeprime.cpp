#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    int sum;
    bool flag;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                
                flag = true;
                sum = nums[i] + nums[j] + nums[k];
                
                for (int m = 2; m < sum; ++m) {
                    if (sum % m == 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ++answer;
            }
        }
    }
    
    

    return answer;
}
