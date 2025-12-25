
#include <stdbool.h>
#include <stdio.h>
#define MAX_SIZE 30

// Define a structure forthe stack
typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

// A fucntion to intialize the stack
void initialize(Stack *stack) { stack->top = -1; }

// A function to check whether the stack is empty
bool isEmpty(Stack *stack) { return stack->top == -1; }

// A function to check if the stack is full or not
bool isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

// A fucntion to push values to stack
void push(Stack *stack, int value) {
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[++stack->top] = value;
  printf("Pushed %d onto the stack\n", value);
}

// A fucntion to pop  values from stack
int pop(Stack *stack) {

  if (isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  int poped = stack->arr[stack->top];
  stack->top--;
  printf("Poped %d from  the stack\n", poped);
  return poped;
}

int peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
  }
  return stack->arr[stack->top];
}

int main() {

  Stack stack;
  initialize(&stack);

  push(&stack, 3);
  printf("Top element: %d \n", peek(&stack));

  push(&stack, 5);
  printf("Top element: %d \n", peek(&stack));

  push(&stack, 2);
  printf("Top element: %d \n", peek(&stack));

  push(&stack, 8);
  printf("Top element: %d \n", peek(&stack));

  while (!isEmpty(&stack)) {
    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
  }
  return 0;
}
