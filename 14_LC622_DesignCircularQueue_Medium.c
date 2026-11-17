typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *queue = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));
    queue->capacity = k;
    queue->front = -1;
    queue->rear = -1;
    queue->elements = (int *) calloc(k, sizeof(int));
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->front == 0 && obj->rear == obj->capacity - 1) || obj->rear == obj->front - 1;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    if (myCircularQueueIsEmpty(obj)) {
        obj->front = 0;
    }
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->elements[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    if (obj->front == obj->rear) {
        obj->front = -1;
        obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->elements[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->elements[obj->rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->elements);
    free(obj);
}
