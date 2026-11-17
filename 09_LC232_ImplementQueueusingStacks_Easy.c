#define CAPACITY 100


typedef struct {
    int stack1[CAPACITY];
    int stack2[CAPACITY];

    int top1;
    int top2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = malloc(sizeof(MyQueue));

    if (obj == NULL) {
        printf("Queue creation failed!\n");
        return NULL;
    }

    obj->top1 = 0;
    obj->top2 = 0;

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[obj->top1] = x;
    obj->top1++;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->top1--;
            
            int value = obj->stack1[obj->top1];
            obj->stack2[obj->top2] = value;
            obj->top2++;
        }
    } 
    return obj->stack2[--obj->top2];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == 0) {
        while (obj->top1 > 0) {
            obj->top1--;

            int value = obj->stack1[obj->top1];
            obj->stack2[obj->top2] = value;
            obj->top2++;
        }
    }
    return obj->stack2[obj->top2 - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == 0 && obj->top2 == 0);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
