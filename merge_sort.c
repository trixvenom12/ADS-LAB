#include<stdio.h>
int main()
{
int arr1[50],arr2[50],arr3[100],n,m,i,j,k=0;
printf("Enter the Size of first array");
scanf("%d",&m);
printf("Enter the elements in first array");
for(int i=0;i<m;i++)
{
	scanf("%d",&arr1[i]);
}
printf("Enter the Size of second array");
scanf("%d",&n);
printf("Enter the elements in second array");
for(int j=0;j<n;j++)
{
	scanf("%d",&arr2[j]);
}
i=0,j=0;
while(i<m && j<n)
{
	if(arr1[i]<arr2[j])
	{
	arr3[k]=arr1[i];
	i++;
	}
else
{
	arr3[k]=arr2[j];
	j++;
}
k++;

}
while(i<m)

{
	arr3[k]=arr1[i];
	i++;
	k++;
}
while(j<n)
{
arr3[k]=arr2[j];
j++;
k++;
}

printf("Array after merging");
for(k=0;k<m+n;k++)
{
	printf("%d",arr3[k]);
}

}
