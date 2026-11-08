#include <iostream>
#include <cassert>
#include "queue.hpp"

int main()
{
    Queue<int> q;

    assert(q.empty() == true);

    for (int i = 0; i < 6; i++)
        q.enqueue(i);

    std::string hello = "hello";
    q.enqueue(hello);

    assert(q.empty() == false);

    int i = 0;
    while(q.empty() == false)
    {
        int val = q.dequeue();
        if(i < 6)
        {
            int val = q.dequeue();
            assert(val == i);
            std::cout << "Dequeued " << val << '\n';
        }
        i++;
    }

    assert(q.empty() == true);
}