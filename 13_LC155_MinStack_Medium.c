#include <stdlib.h>
#define MAX 30000
typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}
void minStackPush(MinStack* obj, int value) {
    obj->top++;
    obj->stack[obj->top] = value;
    if(obj->top == 0 || value< obj->minStack[obj->top - 1])
    obj->minStack[obj->top] = value;
    else
    obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

void minStackPop(MinStack* obj) {
    obj->top--;
}
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];    
}
void minStackFree(MinStack* obj) {
    free(obj);
}
