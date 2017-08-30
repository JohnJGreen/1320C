/*
    Darin Brezeale
    CSE 1320, hw #8
    Sat Mar 30 18:29:45 CDT 2013

    pseudocode:
      create 3 queues
      while string not "stop"
        get string
        if enqueue
          finish tokenizing string
            add student to appropriate line (queue)
        if dequeue
          finish tokenizing string
          remove student from line
        if stop
          remove remaining students from lines
*/

#define MAX_CLASS 5
#define QUEUE_COUNT 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw09-header.h"

struct node {
    char course[10];
    char name[15];
    struct node* next;
};

struct tokens {
    char task[10];
    int line;
    char course[10];
    char name[15];
};

struct node * enqueue(struct tokens* t);
struct node * dequeue(struct node* head);
void printClasses(void);
struct tokens tokenizeString(char value[]);
void printQueue(struct node* head);

int main(int argc, char* argv[])
{
    int i = 0, key;
    char* value = "go";
    int index;
    struct node *head[QUEUE_COUNT] = {NULL};
    struct node *tail[QUEUE_COUNT] = {NULL};
    struct node *temp;
    struct tokens t;

    if(argc != 2)
    {
        printf("  usage:  program_name positive_integer\n");
        printf("example:  ./brezeale-hw09 123\n");
        exit(1);
    }

    /*  do exactly once  */
    key = atoi(argv[1]);
    initialize(key);
    /*********************/

    while(strcmp(value, "stop") != 0)
    {
        value = getString();
        t = tokenizeString(value);

        if(strcmp(t.task, "enqueue") == 0)
        {
            index = t.line - 1;
            temp = enqueue(&t);
            if(head[ index ] == NULL)
                head[ index ] = temp;
            else
                tail[ index ]->next = temp;

            tail[ index ] = temp;

            printf("%s enters line %d to register for %s\n", t.name, t.line, t.course);
          
        }
        else if(strcmp(t.task, "dequeue") == 0)
        {
            index = t.line - 1;

            if( head[ index ] != NULL )
            {
                printf("%s leaves line %d\n", head[index]->name, t.line);
                head[ index ] = dequeue(head[ index ]);
            }
            else
                printf("line %d is currently empty\n", t.line);
        }
    }

    printf("stop received; processing remaining students\n");
    for(i = 0; i < QUEUE_COUNT; i++)
        while(head[i] != NULL)
        {
            printf("%s leaves line %d\n", head[i]->name, i+1);
            head[ i ] = dequeue(head[ i ]);
        }

    return 0;
}

void printQueue(struct node* head)
{
    while(head != NULL)
    {
        printf("%s, %s\n", head->name, head->course);
        head = head->next;
    }
}


struct node * enqueue(struct tokens* t)
/*
      input:  structure of tokens
     output:  new node to be added to tail
*/
{
    struct node* temp = malloc( sizeof(struct node) );
    strcpy(temp->name, t->name);
    strcpy(temp->course, t->course);
    temp->next = NULL;

    return temp;
}


struct node * dequeue(struct node* head)
/*
      input:  beginning of queue
     output:  new head of queue
*/
{
    struct node* temp = head->next;
    free( head );
    return temp;
}

struct tokens tokenizeString(char value[])
/*
      input:  string to be tokenized
     output:  structure of tokens
*/
{
    struct tokens temp;
    char *token, *del = ",";

    strcpy( temp.task, strtok(value, del) );

    if( strcmp(temp.task, "enqueue") == 0 )
    {
        temp.line = atoi(strtok(NULL, del));
        strcpy( temp.course, strtok(NULL, del) );
        strcpy( temp.name, strtok(NULL, del) );
    }
    else if( strcmp(temp.task, "dequeue") == 0 )
    {
        temp.line = atoi(strtok(NULL, del));
    }

    return temp;
}
