#include<stdio.h>
#include<stdlib.h>
 struct file{
 int p;
 int start;
 int num;  
}f[30];

void main()
{
int n,fnum,i,j,size;
printf("Enter the number of blocks available: ");
scanf("%d",&n);
int exist[n];
for(i=0;i<n;i++)
{
exist[i]=0;
}
printf("Enter the number of files: ");
scanf("%d",&fnum);
int b[fnum];
for(i=0;i<fnum;i++)
{
b[i]=0;
f[i].p=i+1;
printf("Enter the starting block of file %d: ",f[i].p);
scanf("%d",&f[i].start);
printf("Enter the number of blocks in the file %d: ",f[i].p);
scanf("%d",&f[i].num);
for(j=0;j<f[i].num;j++)
{
if(exist[f[i].start+j]==1)
{
 printf("This block %d is already allocated . Please choose another block!!\n",(f[i].start+j));
 i--;
 break;
}
}
for(j=0;j<f[i].num;j++)
{
 exist[f[i].start+j]=1;
 b[i]=1;
}
}

printf("File No.\tStart Block\tNo.of Blocks\t Block occupied\n");
for(i=0;i<fnum;i++)
{
if(b[i]==1)
{
printf("%d\t\t%d\t\t%d\t\t\t",f[i].p,f[i].start,f[i].num);
for(j=0;j<f[i].num;j++)
{
 printf("%d ",f[i].start+j);
}
printf("\n");
}
else
{
printf("%d\t\tNot allocated\t\t---\t\t\t---\n",f[i].p);
}
}

}
