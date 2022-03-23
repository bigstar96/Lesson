#include<iostream>


// self referenced structure
struct Monster
{
	int HP;
	int MP;
	
	Monster* pNext;
};

int main()
{
	Monster* monA = new Monster{ 10,10,nullptr };
	Monster* monB = new Monster{ 100,0,nullptr };

	monA->pNext = monB;
}