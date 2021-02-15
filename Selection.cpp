// 2017029770_Yunhee_Seo
#include <stdio.h>
int n,m;
int arr[30001];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(int j=0;j<m;j++){
		int minind = j;
		for(int k=j+1;k<n;k++){
			if(arr[k]<arr[minind]){
			minind = k;
			}
		}
		int temp = arr[minind];
		arr[minind] = arr[j];
		arr[j] = temp;
	}
	for(int l=0;l<n;l++){
		printf("%d\n",arr[l]);
	}
	return 0;
}



