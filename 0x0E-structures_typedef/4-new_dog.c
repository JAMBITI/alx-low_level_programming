#include <stdlib.h>
#include "dog.h"

int _strlen(char *str);
char *_strcpy(char *dest, char *src);

/**
  * new_dog - new dog
  * @name: name of dog
  * @age: dog age
  * @owner: dog s owner
  *
  * Return: null if function faills
  *
  */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (len2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}



/**
 *_strlen - gets a lenth of string
 * @str: string
 * Return: lenth of string
 */
int _strlen(char *str)
{
	int c = 0;

	for (; *str != '\0'; str++)
	{
		c++;
	}

	return (c);
}


/**
 * _strcpy - copies string from string to destination
 * @src: string
 * @dest: destination
 * Return: destin
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';

	return (dest);
}
