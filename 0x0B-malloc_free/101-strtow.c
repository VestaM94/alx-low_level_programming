#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words in the string.
 */
static int count_words(char *str)
{
	int count = 0;
	char *p = str;

	while (*p) {
		if (*p != ' ' && (*(p + 1) == ' ' || *(p + 1) == '\0'))
			count++;
		p++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int words = count_words(str);
	char **arr = malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);

	int i = 0;
	char *p = strtok(str, " ");
	while (p != NULL) {
		arr[i] = strdup(p);
		if (arr[i] == NULL) {
			while (i-- >= 0)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
		p = strtok(NULL, " ");
	}
	arr[i] = NULL;

	return (arr);
}

