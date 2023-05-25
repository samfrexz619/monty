#ifndef MONTY
#define MONTY
#define _POSIX_C_SOURCE 200809L
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
 * struct globals - global struct
 * @lifo: stack or queue
 * @curr: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buff: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct globals
{
	int lifo;
	unsigned int curr;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buff;
} global_v;

/**
 * struct instruction_s - opcode and its function
 * @opcode: opcode
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

extern global_v global;

/* opcode functions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int nline);
void _pop(stack_t **stack, unsigned int nline);
void _swap(stack_t **stack, unsigned int nline);
void _queue(stack_t **stack, unsigned int nline);
void _stack(stack_t **stack, unsigned int nline);
void _add(stack_t **stack, unsigned int nline);
void _nop(stack_t **stack, unsigned int nline);
void _sub(stack_t **stack, unsigned int nline);
void _div(stack_t **stack, unsigned int nline);
void _mul(stack_t **stack, unsigned int nline);
void _mod(stack_t **stack, unsigned int nline);
void _pchar(stack_t **stack, unsigned int nline);
void _pstr(stack_t **stack, unsigned int nline);
void _rotl(stack_t **stack, unsigned int nline);
void _rotr(stack_t **stack, unsigned int nline);

/*get function*/
void (*get_opc(char *opc))(stack_t **stack, unsigned int line_number);

/* functions*/
int _srch(char *str, char ch);
char *_strtokn(char *str, char *d);
void *_realloc(void *ptr, unsigned int old, unsigned int new);
void *_calloc(unsigned int num, unsigned int sz);
int _strcmp(char *str1, char *str2);

/* doubly linked list functions */
stack_t *add_node_end(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
void free_list(stack_t *stack);

/* main */
void free_glov(void);

#endif
