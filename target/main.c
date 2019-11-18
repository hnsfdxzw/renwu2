#include<stdio.h>
#include<memory.h>
#include<stdbool.h>
//stack
int a[9]={0};//a[0]--a[0][0] a[1]--a[0][1] and so on  simulate stack
int len=0;
//dfs
int visited[10]={0};
bool judge()//行列相等
{
    int i,j;
    int tmp[6]={0};
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tmp[i]+=a[3*i+j];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tmp[3+i]+=a[i+3*j];
    int jud=tmp[0];
    for(i=1;i<6;i++)
    {
        if(jud!=tmp[i])
            return false;
    }
    return true;
}
bool judge1()//行列相等 对角线也相等
{
    int i,j;
    int tmp[8]={0};
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tmp[i]+=a[3*i+j];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            tmp[3+i]+=a[i+3*j];
    tmp[7]=a[0]+a[4]+a[8];
    tmp[6]=a[2]+a[4]+a[6];
    int jud=tmp[0];
    for(i=1;i<8;i++)
    {
        if(jud!=tmp[i])
            return false;
    }
    return true;
}
void printa()
{
    int t,p;
    for(t=0;t<3;t++)
    {
        for(p=0;p<3;p++)
        {
            printf("%d ",a[3*t+p]);
        }
        printf("\n");
    }
}
void dfs(int i,int v[])
{
    if(i==10)//find one solution
    {
        if(judge1())//给你写了两个判断函数 如果对角线也相等那么用judge1()即可判断
            printa();
        return;
    }

    int j;
    for(j=1;j<=9;j++)
    {
        int tmp[10];
        memcpy(tmp,v,10*sizeof(int));
        if(tmp[j]==0)
        {
            tmp[j]=1;
            a[len++]=j;
            //printf("%d %d\n",len-1,a[len-1]);
            dfs(i+1,tmp);
            len--;
        }

    }


}
int main(void)
{
    dfs(1,visited);
    return 0;
}
