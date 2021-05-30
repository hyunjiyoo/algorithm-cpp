#include <iostream>

int N;
int A[8];
int newA[8];
bool pick[8];
int result = -9999;

int calculate() {
    int ret = 0;
    for (int i = 0; i < N-1; ++i) {
        if (newA[i + 1] > newA[i]) {
            ret += newA[i + 1] - newA[i];
        } else {
            ret += newA[i] - newA[i + 1];
        }
    }
    
    return ret;
}

void maxdiff(int step = 0) {

    if (step == N) {
        result = std::max(result, calculate());
        return;
    }
    
    for (int i = 0; i < N; ++i) {
        if (pick[i] == false) {
            pick[i] = true;
            
            newA[step] = A[i];
            maxdiff(step + 1);
            
            pick[i] = false;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        pick[i] = false;
    }
    
    maxdiff();
    std::cout << result;
    
    return 0;
}
