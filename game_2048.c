#include <stdio.h>
#include <stdlib.h>
#define ALEN(p) sizeof(p)/sizeof(int)

int y,x;


void init();


void main()
{
	init();
	
} 

void init ()
{
	x=0,y=0;
	int n,m;
	int (*p)[2],(*q)[2];
	int i;
	
	printf("请自行构建游戏方块，输入任意数字外的字符为完成\n");
	
	
	
	while(scanf("%d%d",&n,&m))
	{
		if(n<1 || m<1)
		{
			printf("输入的值不允许为负数或0请重新输入\n");
			continue;
		}
		if((n > p[y-1][0] + p[y-1][1] || n + m < p[y-1][0]) && (p[y-1][0] != 0 || p[y-1][1] != 0) && y != 0)
		{
			printf("输入的格子与上行没有交集，清重新输入\n");	
			continue;
		}
			
		if(n + m > x)
			x = n + m;
		
		y++;
		
		q = (int (*)[2])malloc(ALEN(p)*2*sizeof(int));
		
		for(i=0;i < strlen(p);i++)
		{
			q[i][0] = p[i][0];
			q[i][1] = p[i][1];
		};
		
		free(p);
		
	    p = (int (*)[2])malloc(y*2*sizeof(int));
	    
		for(i=0;i < ALEN(q);i++)
		{
			p[i][0] = q[i][0];
			p[i][1] = q[i][1];
		};
		
		p[y-1][0] = n;
		p[y-1][1] = m;
		
		for(i=0;i < ALEN(p);i++)
		{
			printf("%d\n%d\n%d\n",p[i][0],p[i][1],strlen(p));
		};
		
	}
	system("cls");
} 