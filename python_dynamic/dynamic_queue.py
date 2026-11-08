from collections import deque

class Queue:
    def __init__(self):
        self._storage = deque()

    def enqueue(self, item):
        self._storage.append(item)

    def dequeue(self):
        if self.is_empty():
            raise IndexError("deque is empty")
        return self._storage.popleft()

    def is_empty(self):
        return len(self._storage) == 0