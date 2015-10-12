#include <iostream>
#include <stack>
using namespace std;

void queuePush(stack<int> *s1, stack<int> *s2, int node)
{
	int tempVal = 0;
	if ((*s1).empty())
	{
		while (!(*s2).empty())
		{
			tempVal = (*s2).top();
			(*s2).pop();
			(*s1).push(tempVal);
		}
		(*s1).push(node);
		return;
	}
	else
	{
		(*s1).push(node);
		return;
	}
}

int queuePop(stack<int> *s1, stack<int> *s2)
{
	int tempVal = 0;
	if ((*s2).empty())
	{
		while (!(*s1).empty())
		{
			tempVal = (*s1).top();
			(*s1).pop();
			(*s2).push(tempVal);
		}
		tempVal = (*s2).top();
		(*s2).pop();
		return tempVal;
	}
	else
	{
		tempVal = (*s2).top();
		(*s2).pop();
		return tempVal;
	}
}

int main()
{
	stack<int> s1;
	s1.push(1);	s1.push(3);	s1.push(4);	s1.push(8);	s1.push(6);	s1.push(5);	s1.push(2);	s1.push(8);
	stack<int> s2;

	int tempValue;
	queuePop(&s1, &s2);
	queuePush(&s1, &s2, 5);


	getchar();
	return 0;
}