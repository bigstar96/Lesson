#include<iostream>

const int Circular_QUEUE_SIZE{ 10 };

enum Command
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

void Circular_PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl
		<< "[1] enqueue" << std::endl
		<< "[2] dequeue" << std::endl
		<< "[3] exit" << std::endl
		<< "-----------" << std::endl;
}

void Circular_PrintQueue(Circular_Queue& queue)
{
	std::cout << "---- queue ----" << std::endl;

	if (queue.head == queue.tail)
	{
		std::cout << "EMPTY!" << std::endl;
		return;
	}

	int i = queue.head;
	while (i != queue.tail)
	{
		i = (i + 1) % Circular_QUEUE_SIZE;
		std::cout << queue.container[i] << " ";
	}
	std::cout << std::endl << "--------" << std::endl;
}

void Circular_Enqueue(Circular_Queue& queue, int value)
{
	if ((queue.tail + 1) % Circular_QUEUE_SIZE == queue.head)
	{
		std::cout << "Queue is FULL!" << std::endl;
		return;
	}

	queue.tail = (queue.tail + 1) % Circular_QUEUE_SIZE;
	queue.container[queue.tail] = value;
}

void Circular_Dequeue(Circular_Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "Queue is EMPTY!" << std::endl;
		return;
	}

	queue.head = (queue.head + 1) % Circular_QUEUE_SIZE;
	std::cout << queue.container[queue.head] << " is Dequeue!" << std::endl;
}

void Circular_ProcessUserInput(Circular_Queue& queue)
{
	int command{ -1 };
	bool isExit{ false };
	while (true)
	{
		Circular_PrintQueue(queue);

		std::cout << std::endl << "> ";
		std::cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "   value>> ";
			std::cin >> value;
			Circular_Enqueue(queue, value);

		}
			break;

		case DEQUEUE:
			Circular_Dequeue(queue);
			break;

		case EXIT:
			isExit = true;
			break;

		default:
			std::cout << "Inbalid Command!!" << std::endl;
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
	Circular_Queue myQueue;

	Circular_PrintInfo();
	Circular_ProcessUserInput(myQueue);
}