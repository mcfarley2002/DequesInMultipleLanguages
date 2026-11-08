from generic_queue import Queue

def main():
    q: Queue[int] = Queue()


    for i in range(6):
        q.enqueue(i)

    for i in range(6):
        x = q.dequeue()
        print(f"Dequeued: {x}")
        assert(x == i)

    assert(q.is_empty() == True)

if __name__ == "__main__":
        main()