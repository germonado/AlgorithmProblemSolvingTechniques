//2017029770_Yunhee_Seo
#include <stdio.h>
int arr[200005];
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(i!=1){
			int bigyo=i;
			while(bigyo!=1){
				if(arr[bigyo]>arr[bigyo/2]){
					int p = arr[bigyo/2];
					arr[bigyo/2] = arr[bigyo];
					arr[bigyo]=p;
					bigyo/=2;
				}
				else{
					break;
				}
			}
		}
	}			
	int size=n;
	for(int i=1;i<=k;i++){
		int max = arr[1];
		printf("%d ",max);
		arr[1]= arr[size];
		arr[size]=max;
		size-=1;
		int bigyo=1;
		int jasik=2;
		while((arr[bigyo]<arr[jasik]||arr[bigyo]<arr[jasik+1])&&jasik+1<=size){
			max = arr[jasik]>arr[jasik+1]?arr[jasik]:arr[jasik+1];
			if(max==arr[jasik]) max=arr[jasik];
			else{
				max=arr[jasik+1];
				jasik+=1;
			}
			arr[jasik]=arr[bigyo];
			arr[bigyo]=max;
			bigyo = jasik;
			jasik*=2;
			/*if(jasik==size){
			if(arr[jasik]>arr[bigyo]){
			int temp = arr[jasik];
			arr[jasik]=arr[bigyo];
			arr[bigyo]=temp;
			}*/
		}	
		 if(jasik==size){
			if(arr[jasik]>arr[bigyo]){
			int temp = arr[jasik];
			arr[jasik]=arr[bigyo];
			arr[bigyo]=temp;
			}
		}		
	}                                                                                                      
	printf("\n");
	for(int l=1;l<=n-k;l++){
		printf("%d ",arr[l]);
	}
	return 0;
}

/*int heapify(int i){
	int l=i*2;
	int r=i*2+1;

*/

