#include <iostream>

#define HEAP_MAX_SIZE 10000
struct int_min_heap {
    int count = 0;
    int storage[HEAP_MAX_SIZE];
    
    bool empty() {
        return count == 0;
    }
    
    void push(int value) {
        if (count > HEAP_MAX_SIZE)
            return;
            
        storage[count] = value;
        int index = count;
        ++count;
        
        while (true) {
            if (index == 0)
                break;
            
            int& current = storage[index];
            int& parent = storage[(index - 1) / 2];
            
            if (current > parent)
                break;
            
            std::swap(current, parent);
            index = (index - 1) / 2;
        }
    }
    
    void pop() {
        if (count == 0)
            return;
        
        storage[0] = storage[count];
        --count;
        
        int index = 0;
        
        while (true) {
            if (index * 2 + 1 > count) // 자식이 없으면 끝
                break;
            
            int& current = storage[index];
            
            int& leftchild = storage[index * 2 + 1];
            int& rightchild = storage[index * 2 + 2];
            
            
            if (index * 2 + 2 > count) { // 오른쪽 자식이 없음
                if (current > leftchild) { // leftchild 가 더 작으므로 바꿈
                    std::swap(current, leftchild);
                    index = index * 2 + 1;
                    continue;
                } else { // 더이상 안바꿔도 됨
                    break;
                }
            } else { // 자식이 둘다 있음
                if (leftchild < rightchild) { // 왼쪽이 더 작음
                    if (current > leftchild) { // leftchild 가 더 작으므로 바꿈
                        std::swap(current, leftchild);
                        index = index * 2 + 1;
                        continue;
                    } else {
                        break;
                    }
                } else {
                    if (current > rightchild) { // leftchild 가 더 작으므로 바꿈
                        std::swap(current, rightchild);
                        index = index * 2 + 1;
                        continue;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    int top() {
        return storage[0];
    }
    
    void print() {
        int line_change = 2 - 1;
        for (int i = 0; i < count; ++i) {
            if (i == line_change) {
                line_change = (line_change + 1) * 2 - 1;
                std::printf("\n");
            }
            std::printf("[%2d] ", storage[i]);
        }
        std::printf("\n");
    }
};

int main(int argc, const char* argv[]) {
    int_min_heap a;
    
    while (true) {
        int input;
        std::printf("input: ");
        std::scanf("%d", &input);
        
        if (input == -1)
            break;
        
        a.push(input);
        a.print();
    }
    
    while (!a.empty()) {
        a.pop();
        a.print();
    }
    
    
    return 0;
}
