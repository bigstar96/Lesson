#include <iostream>

enum Command
{
    ENQUEUE = 1,
    DEQUEUE = 2,
    EXIT = 3
};

const int QUEUE_SIZE{ 10 };

struct Queue
{
    int array[QUEUE_SIZE]{};
    int topIndex{ -1 };
};

void PrintQueue()
{
    std::cout << "  <QUEUE>  " << std::endl;
    std::cout << "[1] ENQUEUE" << std::endl;
    std::cout << "[2] DEQUEUE" << std::endl;
    std::cout << "[3]  EXIT  " << std::endl;
    std::cout << "-----------" << std::endl;
}

void PrintQueue(Queue& queue)
{
    if (queue.topIndex < 0)
    {
        std::cout << "EMPTY" << std::endl;
    }

    for (int i = 0; i <= queue.topIndex; ++i)
    {
        std::cout << queue.array[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-----------" << std::endl;

}

void EnQueue(Queue& queue, int value)
{
    if (queue.topIndex >= QUEUE_SIZE - 1)
    {
        std::cout << "줄이 꽉 찼습니다." << std::endl;
        return;
    }
    queue.array[++queue.topIndex] = value;
}

void DeQueue(Queue& queue)
{
    if (queue.topIndex < 0)
    {
        std::cout << "줄이 비어 있습니다. 더 이상 나갈 사람이 없어요..." << std::endl;
        return;
    }

    std::cout << queue.array[0] << "가 나갔습니다." << std::endl;
    queue.topIndex--;

    for (int i = 0; i < queue.topIndex; ++i)
    {
        int temp = queue.array[i + 2];
        queue.array[i] = queue.array[i + 1];
        queue.array[i + 1] = temp;
    }
}

void ProcessUserInput(Queue& queue)
{
    int command{};
    bool isExit{ false };

    while (command != EXIT)
    {
        PrintQueue(queue);
        std::cout << std::endl << "> ";
        std::cin >> command;
        switch (command)
        {
        case ENQUEUE:
        {
            int value{};
            std::cout << "   Value>>";
            std::cin >> value;
            EnQueue(queue, value);
            break;
        }

        case DEQUEUE:
            DeQueue(queue);
            break;

        case EXIT:
            isExit = true;
            break;

        default:
            std::cout << "잘못된 명렁어 입니다." << std::endl;
            break;
        }

        if (isExit)
        {
            break;
        }
    }
}


int main()
{
    Queue myQueue;

    PrintQueue();
    ProcessUserInput(myQueue);
}