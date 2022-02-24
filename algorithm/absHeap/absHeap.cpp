#include <iostream>
#include <queue>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
std::priority_queue<int, std::vector<int>> mq;

int main (int argc, const char * argv []) {
    std::scanf("%d", &N);
    
    int num = 0;
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &num);
            
        if (num > 0)
            pq.push(num);
        
        else if (num < 0)
            mq.push(num);
    
        else if (num == 0) {
            
            int v = 0;
            
            if (pq.empty() && mq.empty()) {
                v = 0;
            }
            else {

                if (pq.empty()) {
                    v = mq.top();
                    mq.pop();
                }
                else if (mq.empty()) {
                    v = pq.top();
                    pq.pop();
                }
                else {
                    
                    if (pq.top() < (mq.top() * -1)) {
                        v = pq.top();
                        pq.pop();
                    }
                    else {
                        v = mq.top();
                        mq.pop();
                    }
                }
            }
           
            std::printf("%d\n", v);
        }
    }
    
    return 0;
}
