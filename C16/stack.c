
#include <stdlib.h>

struct stack_element
{
	int element;
	struct stack_element* prev;
};
typedef struct stack_element* stack;

int push(stack* _stack, int _element)
{
	stack newStack;
	if (*_stack == NULL)
	{
		if (!(*_stack = (stack)malloc(sizeof(stack))))
		{
			return -1;
		}

		(*_stack)->element = _element;
		(*_stack)->prev = NULL;
		return 0;
	}

	if (!(newStack = (stack)calloc(1, sizeof(stack))))
	{
		return -1;
	}

	newStack->element = _element;
	newStack->prev = *_stack;
	*_stack = newStack;
	return 0;
}

int pop(stack* _stack)
{
	stack newStack = *_stack;
	int ejectedElement;

	if (*_stack == NULL)
	{
		return 0;
	}
	if (newStack->prev == NULL)
	{
		ejectedElement = newStack->element;
		free(*_stack);
		*_stack = NULL;
	}
	else
	{
		ejectedElement = (*_stack)->element;
		newStack = (*_stack)->prev;
		free(*_stack);
		*_stack = newStack;
	}

	return ejectedElement;
}

void delete_stack(stack* _stack)
{
	while (pop(_stack)) {}
	return;
}