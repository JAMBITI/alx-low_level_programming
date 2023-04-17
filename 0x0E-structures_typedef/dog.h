#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog info
 * @name: 1er info
 * @age: second info
 * @owner: third info
 *
 * Description: description
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog my_dog;

#endif
