#include "shell.h"
/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * This function duplicates a string dynamically using malloc.
 *
 * Return: A pointer to the duplicated string,
 *  or NULL if memory allocation fails
 */
char *_strdup(const char *str)
{
	char *ptr;
	size_t len = 0;
	size_t i = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	for (; *str != '\0'; len++, str++)
		;
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i <= len)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}
/**
 * _strcmp - Compares two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * This function compares two strings character by character.
 *
 * Return: An integer less than, equal to, or greater than zero
 *         if s1 is found, respectively, to be less than,
 *         to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	for (; *s1; s1++, s2++, cmp = (int)*s1 - (int)*s2)
	{
		if (*s1 != *s2)
		{
			break;
		}
	}
	return (cmp);
}
/**
 * _strlen - Calculates the length of a string
 * @s: The input string
 *
 * This function iterates through the characters of a string
 * to determine its length.
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	for (; s[len]; len++)
		;
	return (len);

}
/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to append
 *
 * This function appends the characters of the source string to
 * the end of the destination string.
 *
 * Return: A pointer to the destination string
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	for (; *p; p++)
		;
	for (; *src; p++, src++)
	{
		*p = *src;
	}
	*p = *src;
	return (dest);
}
/**
 * _strcpy - Copies a string
 * @dest: The destination string
 * @src: The source string to copy
 *
 * This function copies the characters from the source string
 * to the destination string.
 *
 * Return: A pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	size_t i = 0;

	for (; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
