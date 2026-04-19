#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue() {
    if (front == NULL) return -1;
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

struct Stack {
    int arr[1000];
    int top;
};

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int main() {
    int N, x;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    struct Stack s;
    s.top = -1;
    while (front != NULL) {
        push(&s, dequeue());
    }
    while (s.top != -1) {
        printf("%d ", pop(&s));
    }
    return 0;
}
