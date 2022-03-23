#include<iostream>

enum Command
{
    PUSH = 1,
    POP = 2,
    EXIT = 3
};

const int STACK_SIZE{ 10 };

struct Stack
{
    int array[STACK_SIZE]{};
    int topIndex{ -1 };
};

void Queue_PrintInfo()
{
    std::cout << "<STACK>" << std::endl;
    std::cout << "[1] push" << std::endl;
    std::cout << "[2] pop" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-------------" << std::endl;
}

void PrintStack(Stack& stack)
{
    std::cout << "<STACK>" << std::endl;
    if (stack.topIndex < 0)
    {
        std::cout << "EMPTY" << std::endl;
    }

    for (int i = stack.topIndex; i >= 0; --i)
    {
        std::cout << stack.array[i] << std::endl;
    }
    std::cout << "-----------------";
}

void PushStack(Stack& stack, int value)
{
    if (stack.topIndex >= STACK_SIZE - 1)
    {
        std::cout << "������ ���� á���ϴ�! �� �̻� �߰��� �� �����!" << std::endl;
        return;
    }
    stack.array[++stack.topIndex] = value;
}

void PopStack(Stack& stack)
{
    if (stack.topIndex < 0)
    {
        std::cout << "������ ��� �ֽ��ϴ�! �� �̻� ���� �� �����!" << std::endl;
        return;
    }

    std::cout << stack.array[stack.topIndex--] << "�� ���½��ϴ�." << std::endl;

}

void ProcessUserInput(Stack& stack)
{
    int command{};
    bool isExit{ false };

    while (command != EXIT)
    {
        PrintStack(stack);
        std::cout << std::endl << "> ";
        std::cin >> command;
        switch (command)
        {
        case PUSH:
        {
            int value;
            std::cout << "    Value>>";
            std::cin >> value;
            PushStack(stack, value);
            break;
        }

        case POP:
            PopStack(stack);
            break;

        case EXIT:
            isExit = true;
            break;

        default:
            std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
            break;
        }

        if (isExit)
        {
            break;
        }
    }
}

//int main()
//{
//    Stack myStack;
//
//    PrintInfo();
//    ProcessUserInput(myStack);
//}