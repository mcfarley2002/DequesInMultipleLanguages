from collections import deque

class Queue:
        def __init__(self, type):
                self._type = type
                self._storage = deque()

        def enqueue(self, item):
                if not isinstance(item, self._type):
                        raise TypeError(f"Item must be of type {self._type.__name__}")
                self._storage.append(item)

        def dequeue(self):
                if self.is_empty():
                        raise IndexError("deque is empty")
                return self._storage.popleft()

        def is_empty(self):
                return len(self._storage) == 0