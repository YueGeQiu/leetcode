struct LRUCache {
    int key;
    int value;
    struct LRUCache *prev;
    struct LRUCache *next;
};

typedef struct LRUCache LRUCache;

LRUCache *lru_head = NULL;

void move2head(LRUCache *cur) {
    if (lru_head == cur) {
        lru_head = lru_head->next;
        return;
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    cur->next = lru_head;
    cur->prev = lru_head->prev;
    lru_head->prev->next = cur;
    lru_head->prev = cur;

    return ;
}

LRUCache* lRUCacheCreate(int capacity) {
    if (capacity <= 0) return NULL;

    lru_head = (LRUCache *)malloc(sizeof(LRUCache));
    if (!lru_head) return NULL;

    lru_head->key = -1;
    lru_head->value = -1;
    LRUCache *cur = lru_head;

    while(capacity > 1) {
        cur->next = (LRUCache *)malloc(sizeof(LRUCache));
        if (!cur->next) return NULL;
        cur->next->key = -1;
        cur->next->value = -1;

        cur->next->prev = cur;
        cur = cur->next;

        capacity--;
    }
    cur->next = lru_head;
    lru_head->prev = cur;

    return lru_head;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (!obj) return -1;

    LRUCache *cur = lru_head;
    do {
        if (cur->key == key) {
            move2head(cur);

            return cur->value;
        }
        cur = cur->next;
    } while (cur != lru_head);

    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (!obj) return;

    LRUCache *cur = lru_head;
    do {
        if (cur->key == key) {
            cur->value = value;
            move2head(cur);

            return;
        }
        cur = cur->next;
    } while (cur != lru_head);

    lru_head->key = key;
    lru_head->value = value;
    lru_head = lru_head->next;

    return;
}

void lRUCacheFree(LRUCache* obj) {
    if (!obj) return;

    LRUCache *cur, *tmp = obj;

    do {
        cur = tmp;
        tmp = tmp->next;
        free(cur);
    } while (tmp && tmp != obj);
    obj = NULL;
    return;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * struct LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 * lRUCachePut(obj, key, value);
 * lRUCacheFree(obj);
 */
