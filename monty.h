#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global struct
 * @lfo: stack or queue
 * @curr: current line
 * @arg:  param
 * @head: doubly linked list
 * @fd: file descriptor
 * @buff: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lfo;
	unsigned int curr;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buff;
} global_v;

extern global_v glob_v;

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **hd, unsigned int lnum);
void _pop(stack_t **hd, unsigned int lnum);
void _swap(stack_t **hd, unsigned int lnum);


int _srch(char *str, char ch);
char *_strtokn(char *str, char *d);
void *_realloc(void *pt, unsigned int old, unsigned int new_sz);
void *_calloc(unsigned int num_e, unsigned int sz);
int _strcmp(char *str, char *str2);

stack_t *add_dnode_end(stack_t **head, const int data);
stack_t *add_dnode(stack_t **head, const int data);
void free_dlist(stack_t *head);

void free_glov(void);

#endif
