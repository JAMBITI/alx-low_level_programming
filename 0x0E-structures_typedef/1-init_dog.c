#include <stdlib.h>
#include "dog.h"

/**
 * init_dog -init the dog structure
 * @d: dog struct
 * @name: the name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: alwayse 0
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
