#include "tongxunlu.h"

int main(int argc, char const *argv[])
{
    linklist *head = LinkCreate();
    int k;
    while (1)
    {
        show();
        printf("请输入你要选择的功能：");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            Func1SeqInsert(head);
            break;
        case 2:
            Func2SeeSeq(head);
            break;
        case 3:
            Func3SearchSeq(head);
            break;
        case 4:
            Func4DeleteSeq(head);
            break;
        case 5:
            Func5UpdataSeq(head);
            break;
        case 6:
            func6();
            break;
        default:
            printf("input error!\n");
            break;
        }
    }
    return 0;
}
