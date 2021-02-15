//2017029770 yunhee_seo
#include <stdio.h>
int n;
int e1,e2;
int x1,x2;
int arr[3][200];
int arrt[3][200];
int res[3][200];
int l[3][200];
int chul[200];
int main(){
	scanf("%d",&n);
	scanf("%d %d",&e1,&e2);
	scanf("%d %d",&x1,&x2);
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[1][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[2][i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d", &arrt[1][i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d", &arrt[2][i]);
	}
	res[1][1]=arr[1][1]+e1;
	res[2][1]=arr[2][1]+e2;
	for(int j=2;j<=n;j++){
		if(res[1][j-1]+arr[1][j]<=res[2][j-1]+arrt[2][j-1]+arr[1][j]){
			res[1][j]=res[1][j-1]+arr[1][j];
			l[1][j]=1;
		}
		else{
			res[1][j]=res[2][j-1]+arrt[2][j-1]+arr[1][j];
			l[1][j]=2;
		}
		if(res[2][j-1]+arr[2][j]<=res[1][j-1]+arrt[1][j-1]+arr[2][j]){
			res[2][j]=res[2][j-1]+arr[2][j];
			l[2][j]=2;
		}
		else{
			res[2][j]=res[1][j-1]+arrt[1][j-1]+arr[2][j];
			l[2][j]=1;
		}
	}
	int max=-1;
	int lm = -1;
	if(res[1][n]+x1<=res[2][n]+x2){
		max = res[1][n]+x1;
		lm=1;
	}
	else{
		max= res[2][n]+x2;
		lm=2;
	}
	int i=lm;
	printf("%d\n",max);
	chul[n]=lm;
	for(int j=n;j>1;j--){
		i=l[i][j];
		chul[j-1]=i;
	}
	for(int j=1;j<=n;j++){
		printf("%d %d\n",chul[j],j);
	}
}



	
	
