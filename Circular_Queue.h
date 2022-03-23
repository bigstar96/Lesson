#pragma once
#include "Circular_Queue.h"

const int Circular_QUEUE_SIZE{ 10 };

enum Circular_Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

struct Circular_Queue
{
	int container[Circular_QUEUE_SIZE]{};
	int head{};
	int tail{};
};

void Circular_PrintInfo();

void Circular_PrintQueue(Circular_Queue& queue);

void Circular_Enqueue(Circular_Queue& queue, int value);

void Circular_Dequeue(Circular_Queue& queue);

void Circular_ProcessUserInput(Circular_Queue& queue);
