#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

int N, M, minvalue, maxvalue;
std::vector<int> lesson;

void input() {
    
    minvalue = std::numeric_limits<int>::min();
    maxvalue = 0;
    
    std::cin >> N >> M;
    lesson.resize(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> lesson[i];
        maxvalue += lesson[i];
        minvalue = std::max(minvalue, lesson[i]);
    }
}


void solve() {
    
    int left = minvalue;
    int right = maxvalue;
    int mid = (left + right) / 2;
    int blueray = maxvalue;
    
    while (left <= right) {
        
        int sum, count;
        sum = count = 0;

        for (int i = 0; i < N; ++i) {
            sum += lesson[i];
            
            if (i == N - 1 && sum < mid)
                count += 1;
            
            if (sum >= mid) {
                if (sum > mid)
                    --i;
            
                count += 1;
                sum = 0;
            }
            
            if (count > M) break;
        }
        
//        if (count == M)
//            blueray = std::min(blueray, mid);
        
        if (count > M) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            blueray = std::min(blueray, mid);
        }
            
        mid = (left + right) / 2;
    }
    
    std::cout << blueray;
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    solve();
    
    return 0;
}
