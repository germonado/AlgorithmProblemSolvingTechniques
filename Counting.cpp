//2017029770_Yunhee_Seo
#include <stdio.h>
int a[100005];
int b[100005];
int c[100005];
int n,m,k;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++){
		int num=0;
		scanf("%d",&num);
		c[num]++;
	}
	for(int i=0;i<m;i++){
		c[i+1]=c[i+1]+c[i];
	}
	for(int i=0;i<k;i++){
		printf("%d\n",c[b[i]]-c[a[i]-1]);
	}
	return 0;
}



 


