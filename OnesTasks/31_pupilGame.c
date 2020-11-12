/*　　有n个小朋友围成一圈玩游戏，小朋友从1至n编号，2号小朋友坐在1号小朋友的顺时针方向，3号小朋友坐在2号小朋友的顺时针方向，……，1号小朋友坐在n号小朋友的顺时针方向。
　　游戏开始，从1号小朋友开始顺时针报数，接下来每个小朋友的报数是上一个小朋友报的数加1。若一个小朋友报的数为k的倍数或其末位数（即数的个位）为k，则该小朋友被淘汰出局，不再参加以后的报数。当游戏中只剩下一个小朋友时，该小朋友获胜。
　　例如，当n=5, k=2时：
　　1号小朋友报数1；
　　2号小朋友报数2淘汰；
　　3号小朋友报数3；
　　4号小朋友报数4淘汰；
　　5号小朋友报数5；
　　1号小朋友报数6淘汰；
　　3号小朋友报数7；
　　5号小朋友报数8淘汰；
　　3号小朋友获胜。

　　给定n和k，请问最后获胜的小朋友编号为多少？

输入格式

　　输入一行，包括两个整数n和k，意义如题目所述。

输出格式

　　输出一行，包含一个整数，表示获胜的小朋友编号。

样例输入

5 2

样例输出

3

样例输入

7 3

样例输出

4

数据规模和约定

　　对于所有评测用例，1 ≤ n ≤ 1000，1 ≤ k ≤ 9。
*/


#include <stdio.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int count;
	int number=0;
	int a[1010];
	int i,j,winner;
	for(i=1;i<=n;i++)
	{
		a[i]=1;
	} 
	if(k==1)//最后一个小朋友获胜 
	{
		printf("%d",n);
	}
	else
	{
		while(1)
		{
			count=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]!=0)
				{
					a[i]=number+1;
					number=a[i];
					if(a[i]%k==0||(a[i]%10)==k)//淘汰条件 
					{
						a[i]=0;
					}
				}
				
			}
			for(j=1;j<=n;j++)//判断还有几个小朋友 
			{
				if(a[j]!=0) 
				{
					count++;
					winner=j;
				}
				
			}
			if(count==1)
			{
				break;
			}
		}
		printf("%d\n",winner);
	}
	
	return 0;
}
//原文链接：https://blog.csdn.net/piapiapia2333/article/details/84944386