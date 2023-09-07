#include <iostream>
using namespace std;
#define N 4

int knows(int i, int j) {
    int matrix[N][N] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    return matrix[i][j];
}

struct Stack {
    int data[N];
    int top;
};

void initialize(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int element) {
    stack->data[++stack->top] = element;
}

int pop(Stack* stack) {
    return stack->data[stack->top--];
}

int findCelebrity(int n) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; i < n; i++) {
        push(&stack, i);
    }

    while (stack.top > 0) {
        int person1 = pop(&stack);
        int person2 = pop(&stack);

        if (knows(person1, person2)) {
            push(&stack, person2);
        } 
        else {
            push(&stack, person1);
        }
    }

    int celebrity = pop(&stack);

    for (int i = 0; i < n; i++) {
        if (i != celebrity && (knows(celebrity, i) || !knows(i, celebrity)))
            return -1;
    }

    return celebrity;
}

int main() {
    int celebrity = findCelebrity(N);

    if (celebrity == -1)
        cout << "No celebrity found." << endl;
    else
        cout << "Celebrity found at index " << celebrity << "." << endl;

    return 0;
}
