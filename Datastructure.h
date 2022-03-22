#pragma once
#include "DataStructure.h"

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

void PrintInfo();
void PrintStack(Stack& stack);
void PushStack(Stack& stack, int value);
void PopStack(Stack& stack);
void ProcessUserInput(Stack& stack);