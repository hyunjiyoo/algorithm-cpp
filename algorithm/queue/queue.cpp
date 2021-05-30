#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main (int argc, const char * argv []) {
    queue<int64_t> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    
    cout << queue.front() << endl;
    cout << queue.back() << endl;
    cout << queue.size() << endl;
    cout << queue.empty() << endl;
    
    
    return 0;
}
