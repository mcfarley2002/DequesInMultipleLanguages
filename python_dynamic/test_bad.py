from dynamic_queue import Queue

def main():
    q = Queue()

    for i in range(5):
        q.enqueue(i)

    q.enqueue("hello")

    for i in range(6):
        x = q.dequeue()
        print(f"Dequeued: {x}")
        if(i < 5):
            assert(x == i)
        else:
            assert(x == "hello")

    assert(q.is_empty() == True)

if __name__ == "__main__":
    main()