#include <cstdio>

int func_subtree(int* p,int u,int v);

int main()
{   
    int l,m,u,v,L;
    int sum = 0;
    scanf("%d %d",&l,&m);
    L = l + 1;
    int* p = new int[L];
    //遍历初始化数组为0
    for (int i = 0; i < L; i++)
    {
        p[i] = 1;
    }
    //m个区域的输入
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        func_subtree(p,u,v);
    }
    //数组内所有的区域树木求和
    for (int i = 0; i < L; i++)
    {
        sum += p[i];
    }
    delete p;
    //总数目减去区域内的数目得到剩余的树木
    printf("%d",sum);
    return 0;
}

int func_subtree(int* p,int u,int v)
{
    for ( ; u <= v; u++)
    {
        p[u] = 0;
    }
    return 1;
}