#include <iostream>

void DoSomething(int n)
{
	if (n == 0)
	{
		return;
	}
	// recursive case
	DoSomething(n - 1);
	DoSomething(n - 1);
}

int main()
{
	
}
