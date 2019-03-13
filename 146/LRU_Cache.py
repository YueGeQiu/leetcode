class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.head = Node(-1, -1)
        self.map = {}
        cur = self.head
        for x in range(capacity - 1):
            cur.next = Node(-1, -1)
            cur.next.prev = cur
            cur = cur.next

        cur.next = self.head
        self.head.prev = cur

    def move2Head(self, cur: Node) -> None:
        if self.head == cur:
            self.head = self.head.next
        else:
            cur.prev.next = cur.next
            cur.next.prev = cur.prev

            cur.next = self.head
            cur.prev = self.head.prev
            self.head.prev = cur
            cur.prev.next = cur

    def get(self, key: int) -> int:
        if key in self.map:
            cur = self.map.get(key)
            self.move2Head(cur)
            return cur.value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            cur = self.map.get(key)
            cur.value = value
            self.move2Head(cur)
        else:
            if self.head.key != -1:
                self.map.pop(self.head.key)
            self.head.key = key
            self.head.value = value
            self.map[key] = self.head
            self.head = self.head.next
        print(self.head.value)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
