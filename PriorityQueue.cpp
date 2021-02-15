//2017029770_Yunhee_Seo
#include <stdio.h>
int arr[200005];
int de[200005];
int n,k;
int s, ds;
int size;
int in,sub;
void heapify(int in);
void increase(int ind,int k);
int main(){
	int i=-1;
	while(i!=0){
		scanf("%d",&i);
		if(i==0){
			continue;
		}
		else if(i==1){
		scanf("%d",&s);
		size++;
		arr[size]=s;
		increase(size,s);
		}
		else if(i==2){
			de[ds++]=arr[1];
			int p =arr[1];
			arr[1]= arr[size];
			arr[size]=p;
			size--;
			heapify(1);
		}
		else if(i==3){
			scanf("%d %d",&in,&sub);
			arr[in]=sub;
			if(in!=1&&(arr[in]>arr[in/2])){
				increase(in,sub);
			}
			else{

			heapify(in);
			}
		}
	}
	for(int i=0;i<ds;i++){
		printf("%d ",de[i]);
	}
	printf("\n");
	for(int i=1;i<=size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
void heapify(int in){
int lchild,rchild,largest;
lchild=in*2;
rchild=in*2+1;
if((rchild<=size)&&(arr[rchild]>arr[in])){
	largest=rchild;
}
else{
	largest=in;
}
if((lchild<=size)&&(arr[lchild]>arr[largest])){
	largest=lchild;
}
if(largest!=in){
	int p = arr[in];
	arr[in]=arr[largest];
	arr[largest]=p;
	heapify(largest);
}
}
void increase(int ind, int k){

	while(ind>1&&(arr[ind/2]<arr[ind])){
		int p =arr[ind/2];
		arr[ind/2]=arr[ind];
		arr[ind]=p;
		ind/=2;
	}
}

