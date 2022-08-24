#ifndef _TONGXUNLU_H_
#define _TONGXUNLU_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

typedef int DataType;

typedef struct User
{
    char id[4];
    char name[32];
    char age[3];
    char tele[12];
}User;

typedef struct linklist
{
    User user;
    struct linklist *next;
}linklist;

void show();
linklist* LinkCreate();
void Func5UpdataSeq(linklist *head);
void Func4DeleteSeq(linklist *head);
void Func3SearchSeq(linklist *head);
void Func2SeeSeq(linklist *head);
void Func1SeqInsert(linklist *head);
void func6();
void Read(linklist *head);
void Write(linklist *head);
void LinklistInsertTail(linklist *head,User value);

#endif