typedef struct {
    int *stack;
    int *min_stack;
    unsigned int stactLen;
    unsigned int minStackLen;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *ret = (MinStack *)malloc(sizeof(MinStack));
    if (!ret) return NULL;
    int *stack = (int *)malloc(maxSize * sizeof(int));
    if (!stack) return NULL;

    int *min_stack = (int *)malloc(maxSize * sizeof(int));
    if (!min_stack) return NULL;

    ret->stack = stack;
    ret->min_stack = min_stack;
    ret->stactLen = -1;
    ret->minStackLen = -1;
    return ret;
}

void minStackPush(MinStack* obj, int x) {
    if (!obj) return;

    obj->stack[++obj->stactLen] = x;
    if (obj->minStackLen == -1 || obj->min_stack[obj->minStackLen] >= x) {
        obj->min_stack[++obj->minStackLen] = x;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if (!obj || obj->stactLen < 0) return;

    if (obj->min_stack[obj->minStackLen] == obj->stack[obj->stactLen]) {
        obj->minStackLen--;
    }
    obj->stactLen--;

    return;
}

int minStackTop(MinStack* obj) {
    if (!obj || obj->stactLen < 0) return -1;
    return obj->stack[obj->stactLen];
}

int minStackGetMin(MinStack* obj) {
    if (!obj || obj->minStackLen < 0) return -1;
    return obj->min_stack[obj->minStackLen];
}

void minStackFree(MinStack* obj) {
    if (!obj) return;
    if (obj->stack) free(obj->stack);
    if (obj->min_stack) free(obj->min_stack);
    free(obj);
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */