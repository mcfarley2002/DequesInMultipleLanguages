#include <iostream>
#include <cassert>
#include "queue.hpp"

int main()
{
    Queue<int> q;

    assert(q.empty() == true);

    for (int i = 0; i < 7; i++)
        q.enqueue(i);

    assert(q.empty() == false);

    while(q.empty() == false)
    {
        static int i = 0;
        int val = q.dequeue();
        assert(val == i);
        i++;
        std::cout << "Dequeued " << val << '\n';
    }

    std::cout << "All sunny-day tests passed!" << std::endl;
}