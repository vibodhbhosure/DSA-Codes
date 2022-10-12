#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low, int high){
	int x,i,j,t;
	x=a[low];
	i=low;
	j=high;
	while(i<=j){
		while(a[i]<=x)
		i++;
		while(a[j]>x)
		j--;
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[low];
	a[low]=a[j];
	a[j]=t;
	return j;
}
void quicksort(int a[],int low, int high){
	int pos;
	if(low<high){
		pos=partition(a,low,high);
		quicksort(a,low,pos-1);
		quicksort(a,pos+1,high);
	}
		
}
int main(){
int *inp,i,j;
	FILE *input,*output;
	float total;
	clock_t start,end;
	printf("Quick sort\n");
	input = fopen("input.txt","w");
	output = fopen("output.txt","w");
	for(i=5000;i<=25000;i=i+5000)
	{
		inp = (int*)(malloc(i*sizeof(int)));
		printf("\nFor n = %d\n",i);
			for(j=0;j<i;j++)
			{
			fprintf(input,"%d  ",rand()%i);
			}
		fclose(input);
		input = fopen("input.txt","r");
		for(j=0;j<i;j++)
		{
			fscanf(input,"%d",&inp[j]);
		}
		start=clock();
		quicksort(inp,0,i-1);
		end=clock();
		total=(float)(end-start)/CLOCKS_PER_SEC;
		for(j=0;j<i;j++)
		{
			fprintf(output,"%d ",inp[j]);
		}
		printf("Total Time : %f\n\n",total);
	}
	fclose(input);
	fclose(output);
	return 0;
}
