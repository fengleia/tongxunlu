#include "tongxunlu.h"
//extern User user[1024];
//extern int count;
int main()
{
    show();
    while(1)
    {
        int num;
        printf("输入你要实现的功能：");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            func1();
            break;
        case 2:
            func2();
            break;
        case 3:
            func3();
            break;
        case 4:
            func4();
            break;
        case 5:
            func5();
            break;
        case 6:
            func6();
            break;
        default:
            printf("input error");
            break;
        }
    }
    

    return 0;
}
