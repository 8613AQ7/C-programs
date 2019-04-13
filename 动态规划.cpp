#include<stdio.h>

int main()
{
	int capacity,num;
	scanf("%d %d",&capacity,&num);
	int weight[num+1],value[num+1];
	int max[num+1][capacity+1];
	for(int i=1;i<=num;i++)
		scanf("%d %d",weight+i,value+i);
	for(int i=0;i<=num;i++)
		for(int j=0;j<=capacity;j++)
		{
			if(0==i||0==j)max[i][j]=0;
			else
			{
				if(j<weight[i])max[i][j]=max[i-1][j];
				else max[i][j]=max[i-1][j]>max[i-1][j-weight[i]]+value[i]?max[i-1][j]:max[i-1][j-weight[i]]+value[i];
			}
		}
	int ans=max[num][capacity];
	printf("%d",ans);
	return 0;
}
