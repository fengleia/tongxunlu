#include "tongxunlu.h"

typedef struct User
{
    int id;
    char name[32];
    int age;
    char tel[12];
}User;
User user[1024];
int count = 0;

void show()
{
    printf("----------欢迎使用通讯录管理----------\n");
    printf("--------1.添加用户  2.查看用户--------\n");
    printf("--------3.搜索用户  4.删除用户--------\n");
    printf("--------5.修改用户  6.退出系统--------\n");
}

int find_id(int id,int count)
{
    for(int i = 0;i<count;i++)
    {
        if(user[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int find_name(char *name,int count)
{
    for(int i = 0;i<count;i++)
    {
        if((strcmp(name,user[i].name))==0)
        {
            return i;
        }
    }
    return -1;
}

void func1()
{
    char ch;
    int flag = 1;
    do
    {
        printf("请输入添加用户的id：\n");
        scanf("%d",&user[count].id);
        printf("请输入添加用户的姓名：\n");
        scanf("%s",user[count].name);
        printf("请输入添加用户的年龄：\n");
        scanf("%d",&user[count].age);
NEXT:
        printf("请输入添加用户的电话：\n");
        scanf("%s",user[count].tel);
        if(strlen(user[count].tel) != 11)
        {
            printf("电话输入错误!\n");
            printf("请重新输入电话!\n");
            goto NEXT;

        }
        printf("用户添加成功！\n");
        count++;
        printf("是否需要继续添加用户[y/n]");
        scanf(" %c",&ch);
        if('y'==ch)
        {
            flag = 1;
        }
        else if('n'==ch)
        {
            flag = 0;
            return;        
        }
        else
        {
            printf("你输入的有误！\n");
            return;
        }
    }while(flag==1);
}

void func2()
{
    for(int i = 0;i<count-1;i++)
    {
        for(int j = 0;j<count-i-1;j++)
        {
            if((strcmp(user[j].name,user[j+1].name))>0)
            {
                User tmp = user[j];
                user[j] = user[j+1];
                user[j+1] = tmp;
            }
        }
    }
    for(int i = 0;i<count;i++)
    {
        printf("-----------------------------------------------------\n");
        printf("id:%-5d 姓名:%-10s 年龄:%-5d 电话:%-15s\n",user[i].id,user[i].name,user[i].age,user[i].tel);
    }
}

void func3()
{
    int k,num;
    char str[32];
    printf("请选择搜索用户的方式:\n 1.用户id  2.用户姓名\n");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
            printf("请输入搜索用户的id: ");
            scanf("%d",&num);
            int ret1 = find_id(num,count);
            if(ret1 == -1)
            {
                printf("搜索的用户不存在！\n");
            }
            else
            {
                printf("你搜索的用户如下：\n");
                printf("id:%-5d 姓名:%-10s 年龄:%-5d 电话:%-15s\n",user[ret1].id,user[ret1].name,user[ret1].age,user[ret1].tel);
            }
            break;
        case 2:
            printf("请输入搜索用户的姓名：\n");
            scanf("%s",str);
            int ret2 = find_name(str,count);
            if(ret2 == -1)
            {
                printf("你搜索的用户不存在！\n");
            }
            else
            {
                printf("你搜索的用户如下：\n");
                printf("id:%-5d 姓名:%-10s 年龄:%-5d 电话:%-15s\n",user[ret2].id,user[ret2].name,user[ret2].age,user[ret2].tel);
            }
            break;
        default:
            printf("你输入的方式错误！\n");
            break;

    }
    return;
}

void func4()
{
    int num;
    printf("请输入要删除用户的id:");
    scanf("%d",&num);
    int ret = find_id(num,count);
    if(ret == -1)
    {
        printf("查无此人\n");
    }
    else
    {
        for(int i = ret;i<count-1;i++)
        {
            user[i] = user[i+1];
        }
        count--;
        printf("删除成功！\n");
        return;
    }

}

void func5()
{
    int num,k;
    int new_id,new_age;
    char new_name[32],new_tel[32];
    printf("请输入要修改用户的id：");
    scanf("%d",&num);
    int ret = find_id(num,count);
    if(ret == -1)
    {
        printf("查无此人");
    }
    else
    {
        printf("请输入你要修改的选项:\n");
        printf("1.id 2.姓名 3.年龄 4.电话\n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
                printf("请输入新的id：");
                scanf("%d",&new_id);
                user[ret].id = new_id;
                printf("修改成功！\n");
                break;
            case 2:
                printf("请输入新的姓名：");
                scanf("%s",new_name);
                strcpy(user[ret].name,new_name);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入新的年龄：");
                scanf("%d",&new_age);
                user[ret].age = new_age;
                printf("修改成功！\n");
                break;
            case 4:
                printf("请输入新的电话：");
                scanf("%s",new_tel);
                strcpy(user[ret].tel,new_tel);
                printf("修改成功！\n");
                break;
            default:
                printf("你输入的选项有误!\n");
                break;
        }
    }
}

void func6()
{
    printf("欢迎下次使用！\n");
    exit(1);
}

