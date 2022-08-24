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
    scanf("%s", tmp->user.id);
    printf("请输入姓名:");
    scanf("%s", tmp->user.name);
    printf("请输入年龄:");
    scanf("%s", tmp->user.age);
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
        printf("id:%-5s  姓名:%-10s  年龄:%-5s  电话:%-13s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
        p = p->next;
    }
}

void Func3SearchSeq(linklist *head)
{
    int choice;
    char id[4];
    char name[32];
    printf("请选择你要搜索用户的方式:1.id 2.姓名\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入你要搜索用户的id:");
        scanf("%s", id);
        linklist *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            if (strcmp(id,p->user.id)==0)
            {
                printf("id:%s  姓名:%s  年龄:%s  电话:%s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
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
                printf("id:%s  姓名:%s  年龄:%s  电话:%s \n", p->user.id, p->user.name, p->user.age, p->user.tele);
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
        char  id[4];
        printf("请输入要删除用户的id:");
        scanf("%s", id);
        linklist *p = head;
        linklist *q = NULL;
        linklist *tmp = (linklist *)malloc(sizeof(linklist));
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            if (strcmp(id,p->user.id)==0)
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
    char id[4];
    printf("请输入你要修改用户的id:");
    scanf("%s", id);
    linklist *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        if (strcmp(id,p->user.id)==0)
        {
            printf("请输入你要修改的信息:\n");
            printf("id >> ");
            scanf("%s", p->user.id);
            printf("姓名 >> ");
            scanf("%s", p->user.name);
            printf("年龄 >> ");
            scanf("%s", p->user.age);
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

void Read(linklist *head)
{
    User ptr;
    bzero(&ptr,sizeof(ptr));
    int fd = open("./1.txt",O_RDONLY|O_CREAT,0664);
    if(-1 == fd)
    {
        perror("open");
        return;
    }
    while(1)
    {
        int ret = read(fd,&ptr,sizeof(ptr));

        if(ret == 0)
        {
            printf("读取到文件尾部!\n");
            break;
        }
        else if(-1 == ret)
        {
            perror("read");
            return;
        }
        else
        {
            printf("读取成功!\n");
        }
        LinklistInsertTail(head,ptr);
    }
}

void Write(linklist *head)
{
    int fd = open("./1.txt",O_WRONLY|O_CREAT,0664);
    if(-1 == fd)
    {
        perror("open");
        return;
    }
    linklist *tmp = head->next;
    while(tmp!=NULL)
    {
        if(-1 == write(fd,&tmp->user,sizeof(tmp->user)))
        {
            perror("write");
            return;
        }
        tmp = tmp->next;
    }
    close(fd);
}

void LinklistInsertTail(linklist *head,User value)
{
	linklist *tmp = (linklist *)malloc(sizeof(linklist));
	
	tmp->next = NULL;
	tmp->user = value;

	linklist *p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	tmp->next = p->next;
	p->next = tmp;
	return;
}