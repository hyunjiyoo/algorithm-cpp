#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> A, B;

void input() {
    std::cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i)
        std::cin >> A[i];
    
    std::sort(A.begin(), A.end());
    std::cin >> M;
}


void solve() {
    
    for (int i = 0; i < M; ++i) {
        int num;
        std::cin >> num;
        
        bool found = false;
        int64_t left = 0;
        int64_t right = N - 1;
        int64_t mid = (left + right) / 2;

        while (left <= right) {
            
            
            if (num == A[mid]) {
                found = true;
                break;
            }
            else if (num > A[mid]) {
                left = mid + 1;
            }
            else  {
                right = mid - 1;
            }

            mid = (left + right) / 2;
        }

        std::cout << found << '\n';
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    input();
    solve();
    
    return 0;
}
