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

/**
 * dog_t - Typedef for dog structure
 */

typedef struct dog my_dog;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
#endif
