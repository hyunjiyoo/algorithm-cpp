#include <iostream>
using namespace std;

#define MAX_SIZE 100
int heap[MAX_SIZE];

void push (int item, int* n) {
    int i = 0;
    i = ++(*n); // [질문1] n의 역할
    
    /*
     (1) i == 1 까지 while문 반복.
     (2) 새로들어온 item과 heap[i/2] 비교
         (자식노드와 부모노드 비교) i가 2,3일때 인덱스 1에 있는 부모와 비교 */
    while ((i != 1) && item < heap[i / 2]) {
        heap[i] = heap[i / 2]; // 원래 자식이 들어갈 자리에 부모값 저장
        i = i / 2; // 새로 들어올 자식이 기존 부모자리에 들어갈 것을 대비해 i를 반 줄임
    }
    heap[i] = item; // 비어있는 칸에 넣어줌
}


int delque (int *n) {
    int first, tmp, parent, child;
    
    first = heap[1];
    tmp = heap[(*n)--]; // 맨 마지막 노드를 담아준다.
    
    cout << "\nfirst: " << first << "  tmp: " << tmp << endl;
    cout << "*n: " << *n << endl;
    
    parent = 1;
    child = 2;
    
    // 가장 상위 노드(부모노드)부터 아래로 자식노드 비교하면서 탐색
    while (child <= *n) {
        /* 쳣번째 자식노드(heap[child])와 두번째 자식노드(heap[child+1]) 비교해서
           두번째 자식노드가 더 작으면 child를 두번째 자식노드로 만들어줌 */
        if ((child < *n) && (heap[child] > heap[child + 1]))
            child++;
        
        // 가장 끝에 있는 노드를 담은 tmp가 자식노드들보다 모두 작으면 나온다.
        if (tmp <= heap[child])
            break;
        
        heap[parent] = heap[child]; // 자식노드를 부모 노드에 담는다.
        parent = child; // 한단계 아래로 내려간다.
        child *= 2; // 자식노드도 *2 해줌으로써 한단계 내려간다.
    }
    
    heap[parent] = tmp;
    
    return first;
}


int main (int argc, const char * argv []) {
    
    int input;
    int n = 0;
    int count = 0;
    
    printf("Min Heap 구현 - 숫자입력하세요.\n");
    printf("***** 숫자 입력 (-1을 입력하면 입력 종료) *****\n");
    
        // PQ에 노드 push
    while (1) {
        scanf("%d", &input);
        
        if (input == -1)
            break;
        
        push(input, &n);
        count++;
    }
    
    for (int i = 1; i <= count; ++i)
        printf("%d ", heap[i]);
    
    
        // 우선순위 가장 높은 루트노드 삭제
    printf("\n\n최상위 노드 삭제값: %d\n", delque(&count));
    for (int i = 1; i <= count; ++i)
        printf("%d ", heap[i]);
    
    return 0;
}
