#include <iostream>
#include <string>

int N;
int tree[26][2];
std::string result;

enum {
    endindex = '.' - 'A',
    left = 0,
    right = 1,
    preorder,
    inorder,
    postorder,
};

void input() {
    std::cin >> N;
    
    char root, left, right;
    for (int i = 0; i < N; ++i) {
        std::cin >> root >> left >> right;
        tree[root - 'A'][0] = left - 'A';
        tree[root - 'A'][1] = right - 'A';
    }
}

void output() {
    std::cout << result << std::endl;
    result = "";
}

void traversal(int order = preorder, int root = 0) {
    
    if (root == endindex)
        return;
    
    switch (order) {
        case preorder: {
            result += (root + 'A');
            traversal(order, tree[root][left]);
            traversal(order, tree[root][right]);
        }
            break;
        case inorder: {
            traversal(order, tree[root][left]);
            result += (root + 'A');
            traversal(order, tree[root][right]);
        }
            break;
        case postorder: {
            traversal(order, tree[root][left]);
            traversal(order, tree[root][right]);
            result += (root + 'A');
        }
            break;
    }
}


int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    
    input();
    for (int order = preorder; order <= postorder; ++order) {
        traversal(order);
        output();
    }
    
    return 0;
}
