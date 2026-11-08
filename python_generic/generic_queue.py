class Queue[T]:
    def __init__(self):
        self.items: list[T] = []

    def enqueue(self, item: T) -> None:
        self.items.append(item)

    def dequeue(self) -> T:
        if not self.is_empty():
            return self.items.pop(0)
        raise IndexError("dequeue from empty queue")

    def is_empty(self) -> bool:
        return len(self.items) == 0

    def peek(self) -> T:
        if not self.is_empty():
            return self.items[0]
        raise IndexError("peek from empty queue")