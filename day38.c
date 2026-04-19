#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int count = 0;

void push_front(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;
    if (front == NULL) rear = temp;
    else front->prev = temp;
    front = temp;
    count++;
}

void push_back(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;
    if (rear == NULL) front = temp;
    else rear->next = temp;
    rear = temp;
    count++;
}

int pop_front() {
    if (front == NULL) return -1;
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front != NULL) front->prev = NULL;
    else rear = NULL;
    free(temp);
    count--;
    return val;
}

int pop_back() {
    if (rear == NULL) return -1;
    int val = rear->data;
    struct Node* temp = rear;
    rear = rear->prev;
    if (rear != NULL) rear->next = NULL;
    else front = NULL;
    free(temp);
    count--;
    return val;
}

int front_val() {
    if (front == NULL) return -1;
    return front->data;
}

int back_val() {
    if (rear == NULL) return -1;
    return rear->data;
}

int empty() {
    return front == NULL;
}

int size() {
    return count;
}

void clear() {
    while (front != NULL) pop_front();
}

void reverse() {
    struct Node* curr = front;
    struct Node* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL) {
        temp = temp->prev;
        rear = front;
        front = temp;
    }
}

void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int N, x;
    char op[20];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            printf("%d\n", pop_front());
        } else if (strcmp(op, "pop_back") == 0) {
            printf("%d\n", pop_back());
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", front_val());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", back_val());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "display") == 0) {
            display();
        }
    }
    return 0;
}
