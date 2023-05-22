#include<stdio.h>

int safety(int allocation[][10],int need[][10],int avilable[],int n,int m)
{
	int work[m],finish[n],i,j,flag;
	for(i=0;i<n;i++)
	    finish[i]=0;
	for(i=0;i<m;i++)
	    work[i]=avilable[i];
	do
	{
	 flag=0;    
	 i=0;
	while(i<n)
	{
	   if(finish[i]==0)
	   {
	   	for(j=0;j<m;j++)
	   	  if(work[j]<need[i][j])
	   	     break;
	   	if(j==m)
	   	 {
	   		for(j=0;j<m;j++)
	   		   work[j]+=allocation[i][j];
	   		finish[i]=1;
	   	//	printf("Process %d is completed\n",i);
	   		flag=1;
	      } 
	      
		}
		i=i+1;
			
	}
}while(flag);
for(i=0;i<n;i++)
	if(finish[i]==0)
	  return 0;
	  
return 1;
}

int main()
{
	int i,j,k,n,m,allocation[10][10], max[10][10], need[10][10], avilable[10],request[10],pn;
	//("Enter the values of n and m");
	scanf("%d%d",&n,&m);
	////printf("Enter the max matrix");
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	      scanf("%d",&max[i][j]);
	//printf("Enter Allocation Matrix");
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	      scanf("%d",&allocation[i][j]);
    for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	      need[i][j]=max[i][j]-allocation[i][j];
	      
	
//	printf("Enter The avilable vector:");
	for(i=0;i<m;i++)
	  scanf("%d", &avilable[i]);
	  
//	printf("The need matrix is");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		   printf("%d\t",need[i][j]);
		printf("\n");
	}
//	printf("Enter Process number: ");
	scanf("%d",&pn);
//	printf("Enter Request Vector\n");
	for(i=0;i<m;i++)
	   scanf("%d",&request[i]);
	for(i=0;i<m;i++)
	  if(request[i]>need[pn][i])
	     break;
	if(i<m)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<m;i++)
	{
		if(request[i]>avilable[i])
		   {
		   	 printf("1\n");
		   	 return 0;
	      }
	}
	for(i=0;i<m;i++)
	{
		avilable[i]=avilable[i]-request[i];
		allocation[pn][i]=allocation[pn][i]+request[i];
		need[pn][i]=need[pn][i]-request[i];
	}
	
/*	printf("The need matrix is");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		   printf("%d\t",need[i][j]);
		printf("\n");
	}
	
	printf("The allocation matrix is");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		   printf("%d\t",allocation[i][j]);
		printf("\n");
	}
	
	
	printf("The avilable vector is");
		for(j=0;j<m;j++)
		   printf("%d\t",avilable[j]);
		printf("\n");
	
	
	*/
		  	  
	i=safety(allocation,need,avilable,n,m);
	if(i==1)
	   printf("2\n");
	else
	   printf("3\n");
	   
	
	return 0;
	 }
