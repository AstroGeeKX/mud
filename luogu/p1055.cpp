#include<cstdio>
using namespace std;
int main()
{
    int ISBN[10] = {0};
    int s = 0;
    int ii = 0; // ISBN的下标
    int tchar;
    int mod;
    
    // 输入的ISBN码是一个字符串
    // 遍历整个ISBN码 遇到-跳过 X变为10 共9个数字存入数组
    for(int i = 0 ; i < 13 ; i++)
    {
        tchar = getchar();
        if(tchar == '-' )
            continue;
        if(tchar == 'X')
            ISBN[ii++] = 10;
        else
            ISBN[ii++] = tchar - '0'; // 这里- '0'是为了ascii转数字
    }

    for (int i = 0 ; i < 9 ; i++)
    {
        s += ISBN[i] * (i+1); // -'0'变成真正的数字
    }
    
    mod = s % 11;
    
    if (mod == ISBN[9])
        printf("Right");
    else 
    {
        printf("%d-%d%d%d-%d%d%d%d%d-",ISBN[0],ISBN[1],ISBN[2],ISBN[3],ISBN[4],ISBN[5],ISBN[6],ISBN[7],ISBN[8]);
        printf("%c", mod == 10 ? 'X' : mod + '0');
    }
    
    // 打印标识码
    
        //printf("%d-%d%d%d-%d%d%d%d%d-%d",ISBN[0]- '0',ISBN[1]- '0',ISBN[2]- '0',ISBN[3]- '0',ISBN[4]- '0',ISBN[5]- '0',ISBN[6]- '0',ISBN[7]- '0',ISBN[8]- '0',s%11);
    return 0;
}
