#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> solution(std::vector<int> arr) {
    int count;
    int i = 0;
    int num = arr[0];
    std::vector<int> R;
    
    while (i < arr.size()) {
        count = 0;
        while (num == arr[i]) {
            ++count;
            ++i;
        }
        
        if (count > 1)
            R.push_back(count);
        
        ++num;
    }
    
    if (R.empty()) R.push_back(-1);
    
    return R;
}

int main (int argc, const char * argv []) {
    
    int num = 0;
    std::vector<int> arr;
    
    while (num != -1) {
        std::scanf("%d", &num);
        arr.push_back(num);
    }
    
    std::sort(arr.begin(), arr.end());
    
    std::vector<int> R;
    R = solution(arr);
    
    for (int i = 0; i < R.size(); ++i)
        std::printf("%d ", R[i]);
    
    return 0;
}

