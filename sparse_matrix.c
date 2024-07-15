#include<stdio.h>
#include<stdlib.h>
void sp_transpose(int **esparse,int r,int c,int t,int **esparset, int x)
{
	int k=1,i,j;
	*(*(esparset+0)+0)=c;
	*(*(esparset+0)+1)=r;
	*(*(esparset+0)+2)=t;
	for(i=0;i<r;i++){
		for(j=1;j<=t;j++){
			if(esparse[j][1]==i){
				esparset[k][0]=i;
				esparset[k][1]=esparse[j][0];
				esparset[k][2]=esparse[j][2];
				k++;
			}
		}
	}
}
int main(){
		int **sparse,r,c,i,j,sparse_counter=0,**esparse,k,**esparset;
		printf("Enter the order or the matrix:");
		scanf("%d %d",&r,&c);
		sparse=(int **)malloc(r*sizeof(int*));
		for(i=0;i<r;i++)
			sparse[i]=(int *)malloc(c*sizeof(int));
		printf("Enter the elements of the matrix:\n");
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%d",sparse[i]+j);
				if(*(*(sparse+i)+j)==0)
					sparse_counter++;
			}
		}
		
	esparse=(int **)malloc(((r*c)-sparse_counter+1)*sizeof(int*));
	for(i=0;i<(r*c)-sparse_counter+1;i++)
			esparse[i]=(int *)malloc(3*sizeof(int));
	*(*(esparse+0)+0)=r;
	*(*(esparse+0)+1)=c;
	*(*(esparse+0)+2)=(r*c)-sparse_counter;
	k=1;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(*(*(sparse+i)+j)!=0){
				*(*(esparse+k)+0)=i;
				*(*(esparse+k)+1)=j;
				*(*(esparse+k)+2)=*(*(sparse+i)+j);
				k++;
			}
		}
	}
	printf("Efficient Sparse Representation:\n");
	for(i=0;i<=(r*c)-sparse_counter;i++){
		printf("%d\t%d\t%d\n",*(*(esparse+i)+0),*(*(esparse+i)+1),*(*(esparse+i)+2));
	}
	esparset=(int **)malloc(((r*c)-sparse_counter+1)*sizeof(int*));
	for(i=0;i<((r*c)-sparse_counter+1);i++)
			esparset[i]=(int *)malloc(3*sizeof(int));
	

			
	sp_transpose(esparse,esparse[0][0],esparse[0][1],esparse[0][2],esparset,(r*c)-sparse_counter+1);
	printf("Sparse Transpose is :\n");
	for(i=0;i<=(r*c)-sparse_counter;i++){
		printf("%d\t%d\t%d\n",*(*(esparset+i)+0),*(*(esparset+i)+1),*(*(esparset+i)+2));
	}
	return 0;
}