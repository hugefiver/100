#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

time_t ts,te,tb,tf;

int rd()
{
    return (rand()%100);
}


void change(int &x,int &y)
{
     int c;
     c=x;
     x=y;
     y=c;
     }


int wait()
{
       printf("3......\n");
       Sleep(1000);
       printf("2......\n");
       Sleep(1000);
       printf("1......\n");
       Sleep(1000);
       return 0;
       }


int he(int x)
{
    int a,b,s,n=1,r=0;
    time(&ts);
    while (n<=x)
               {a=rd();b=rd();n++;
               printf("%d+%d=",a,b);
               scanf("%d",&s);
               if(s==a+b)
                         {printf("\t正确\n");r++; }
                         else printf("\t%d\n",a+b);
}
               time(&te);
               return (r);
               }


int cha(int x)
{
    int a,b,s;
    int n=1,r=0;
    time(&ts);
    while(n<=x)
              {a=rd();b=rd();n++;
              if(a<b) change(a,b);
               printf("%d-%d=",a,b);
               scanf("%d",&s);
                if(s==a-b)
                        {printf("\t正确\n");r++; }
                        else printf("\t%d\n",a-b);
}
               time(&te);
               return (r);

              }


int che(int x)
{
    int a,b,s,n=1,r=0;
    time(&ts);
    while(n<=x)
               {a=rd();b=rd();n++;
               printf("%d*%d=",a,b);
               scanf("%d",&s);
               if(s==a*b)
                         {printf("\t正确\n");r++; }
                         else printf("\t%d\n",a*b);
}
               time(&te);
               return (r);
               }


int mix(int x)
{
    int n=1,r=0;
    time(&tb);
    while(n<=x)
    {n++;
    switch(rd()%3)
    {
     case 0:r+=he(1);break;
     case 1:r+=cha(1);break;
     case 2:r+=che(1);break;
     }
     }
     time(&tf);
     return (r);
     }
int main()
{
    system("title 百以内口算训练");
	srand((unsigned)time(0));
    system("color f");
    printf("欢迎使用100以内口算训练\n");
    int m,t,c,tm;
    while (1)
    {
          printf("【1】加法\n【2】减法\n【3】乘法\n【4】混合运算\n");
          printf("请选择：");
          scanf("%d",&c);
          printf("请输入题量：");
          scanf("%d",&tm);
          printf("\n\n");
          switch(c)
          {
                   case 1:wait();m=he(tm);t=te-ts;break;
                   case 2:wait();m=cha(tm);t=te-ts;break;
                   case 3:wait();m=che(tm);t=te-ts;break;
                   case 4:wait();m=mix(tm);t=tf-tb;break;
                   default:return (0);
                   }
                   printf("%d题中正确%d题,正确率：%lf%%。\n用时：%d秒（%d分%d秒）。\n",tm,m,(double)m*100/tm,t,t/60,t%60);
                   printf("1...继续\t其他...退出：");
                   scanf("%d",&c);
                   if(c!=1) break;
                   }
                   system("pause");
                   return 0;
                   }
