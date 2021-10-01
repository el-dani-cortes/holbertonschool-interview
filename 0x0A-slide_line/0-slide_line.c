#include "slide_line.h"

/**
* move_left - move left
* @size: array size
* @line: array
* Return: 1 ok, 0 no
**/
void move_left(int *line, size_t size)
{
	size_t i = 0, j = 0, k = 0;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			for (; line[i] == 0;)
				i++;
		if (i == (size - 1))
			break;
		j = i + 1;
		if (line[j] == 0)
			for (; line[j] == 0;)
				j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];
	while (k < size)
		line[k++] = 0;
}

/**
* move_right - move right
* @size2: array size
* @line: array
* Return: 1 ok, 0 no
**/
void move_right(int *line, int size2)
{
	int i, j = size2 - 1, sw = 0;

	for (i = size2 - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	if (j >= 0)
		line[j] = 0;
	for (i = size2 - 1; i >= 0; i--)
	{
		if (i > j && line[i] == line[i - 1])
		{
			sw = 1;
			line[i] += line[i - 1];
			line[i - 1] = 0;
		}
		else if (i <= j)
		{
			line[i] = 0;
		}
	}
	if (sw == 1 && j >= 0)
		line[0] = 0;
	j = size2 - 1;
	for (i = size2 - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[j] = line[i];
			j--;
		}
	}
	for (i = 0; i <= j; i++)
		line[i] = 0;
}
/**
* slide_line - entry point
* @size: array size
* @direction: direction
* @line: array
* Return: 1 ok, 0 no
**/
int slide_line(int *line, size_t size, int direction)
{
	int size2 = size;

	if (direction == SLIDE_LEFT)
	{
		move_left(line, size2);
	}
	else if (direction == SLIDE_RIGHT)
	{
		move_right(line, size2);
	}
	return (1);
}