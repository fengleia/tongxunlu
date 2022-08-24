#include "tongxunlu.h"

void show()
{
    printf("------------欢迎使用通讯录管理系统------------\n");
    printf("------------1.添加用户 2.查看用户------------\n");
    printf("------------3.搜索用户 4.删除用户------------\n");
    printf("------------5.修改用户 6.退出系统------------\n");
}

linklist *LinkCreate()
{
    linklist *head = (linklist *)malloc(sizeof(linklist));
    head->next = NULL;
    return head;
}
void Func1SeqInsert(linklist *head)
{
    char ch;
    linklist *p = head;
    linklist *tmp = (linklist *)malloc(sizeof(linklist));
    tmp->next = NULL;

    printf("请输入id号:");
    scanf("%d", &tmp->user.id);
    printf("请输入姓名:");
    scanf("%s", tmp->user.name);
    printf("请输入年龄:");
    scanf("%d", &tmp->user.age);
    printf("请输入电话:");
    scanf("%s", tmp->user.tele);
/*
    while(p->next!=NULL && strcmp(p->user.name,tmp->user.name)<0)
    {
        p = p->next;
    }
*/
    tmp->next = head->next;
    head->next = tmp;
    printf("保存成功！\n");

    printf("是否需要继续添加:Y/N ");
    getchar();
    scanf("%c", &ch);
    switch (ch)
    {
    case 'Y':
    case 'y':
        Func1SeqInsert(head);
        break;
    case 'N':
    case 'n':
        return;
    default:
        printf("输入格式错误!\n");
        return;
    }
}

void Func2SeeSeq(linklist *head)
{
    linklist *p = head->next;
    while (p != NULL)
    {
        printf("id:%-5d  姓名:%-10s  年龄:%-5d  电话:%-13s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
        p = p->next;
    }
}

void Func3SearchSeq(linklist *head)
{
    int choice;
    int id;
    char name[32];
    printf("请选择你要搜索用户的方式:1.id 2.姓名\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入你要搜索用户的id:");
        scanf("%d", &id);
        linklist *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            if (p->user.id == id)
            {
                printf("id:%d  姓名:%s  年龄:%d  电话:%s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
            }
        }
    }
    else if (choice == 2)
    {
        printf("请输入你要搜索用户的姓名:");
        scanf("%s", name);
        linklist *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(name, p->user.name) == 0)
            {
                printf("你搜索的用户如下：\n");
                printf("id:%d  姓名:%s  年龄:%d  电话:%s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
            }
        }
    }
}

void Func4DeleteSeq(linklist *head)
{
    int choice;
    printf("请输入你要删除用户的方式:1.id 2.姓名\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int id;
        printf("请输入要删除用户的id:");
        scanf("%d", &id);
        linklist *p = head;
        linklist *q = NULL;
        linklist *tmp = (linklist *)malloc(sizeof(linklist));
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            if (id == p->user.id)
            {
                tmp = p;
                q->next = p->next;
                free(tmp);
                tmp = NULL;
                printf("删除成功!\n");
            }
        }
    }
    else if (choice == 2)
    {
        char name[32];
        printf("请输入要删除用户的姓名：");
        scanf("%s", name);
        linklist *p = head;
        linklist *q = NULL;
        linklist *tmp = (linklist *)malloc(sizeof(linklist));
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            if (strcmp(name, p->user.name) == 0)
            {
                tmp = p;
                q->next = p->next;
                free(tmp);
                tmp = NULL;
                printf("删除成功!\n");
            }
        }
    }
}

void Func5UpdataSeq(linklist *head)
{
    int id;
    printf("请输入你要修改用户的id:");
    scanf("%d", &id);
    linklist *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        if (id == p->user.id)
        {
            printf("请输入你要修改的信息:\n");
            printf("id >> ");
            scanf("%d", &p->user.id);
            printf("姓名 >> ");
            scanf("%s", p->user.name);
            printf("年龄 >> ");
            scanf("%d", &p->user.age);
            printf("电话 >> ");
            scanf("%s", p->user.tele);
            printf("用户信息修改成功!\n");
        }
    }
}

void func6()
{
    printf("欢迎下次使用\n");
    exit(1);
}
