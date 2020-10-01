#include<stdio.h>
 
void  main()
{
    int n,z,i,j;
float awt=0,att=0;
    printf("total number of processes:");
    scanf("%d",&n);
    int p[20][6];
    int c,f;
for(i=0;i<n;i++)
    {
       for(j=0;j<6;j++)
        {	p[i][j]=0;

    	}
    }


 
    printf("\nEnter Burst Time\n");
    
	for(i=0;i<n;i++)
    {
	p[i][0]=i+1;
        printf("P[%d]:",i+1);
        scanf("%d",&c);
        p[i][1]=c;
    }

printf("\nEnter arrival Time\n");
    
	for(i=0;i<n;i++)
    {
	
        printf("P[%d]:",i+1);
        scanf("%d",&c);
        p[i][2]=c;
    }
	
	
for(i=0;i<n-1;i++)

{for(j=0;j<n-i-1;j++)
{if(p[j][2]>p[j+1][2])
{
f=p[j][0];
p[j][0]=p[j+1][0];
p[j+1][0]=f;

f=p[j][1];
p[j][1]=p[j+1][1];
p[j+1][1]=f;

f=p[j][2];
p[j][2]=p[j+1][2];
p[j+1][2]=f;



}

}


}
	printf("\n");
 	
	for(i=0;i<n;i++)
    {
        printf("%d:",p[i][0]);
        printf("%d\n",p[i][1]);

       
    }

	
	

       
    

	p[0][3]=p[0][1]+p[0][2];
p[0][5]=p[0][3]-p[0][2];
 p[0][4]=p[0][5]-p[0][1]; 
	for(i=1;i<n;i++)
    { 
	p[i][3]=p[i-1][3]+p[i][1];
  	p[i][5]=p[i][3]-p[i][2];
  	p[i][4]=p[i][5]-p[i][1];  

    }	printf("\n");
printf("PID	BT	AT	CT	WT	TAT");
printf("\n");

	for(i=0;i<n;i++)
    {
        printf("%d",p[i][0]);
        printf("	%d",p[i][1]);
        printf("	%d",p[i][2]);
        printf("	%d",p[i][3]);
	printf("	%d",p[i][4]);
	printf("	%d",p[i][5]);
	printf("\n");


       
    }int k;
printf("|");
for(i=0;i<n;i++)
{z=p[i][1];
printf("p%d",p[i][0]);

printf("\t");

printf("|");

}
printf("\n");
printf("%d",p[0][2]);


for(i=0;i<n;i++)
{z=p[i][1];
printf(" ");

printf("\t");

printf("%d",p[i][3]);

}

printf("\n");
for(i=0;i<n;i++)
{awt=awt+p[i][4];
att=att+p[i][5];}

printf("\n");
printf("awt=%f\n",awt/n);
printf("att=%f\n",att/n);


}

