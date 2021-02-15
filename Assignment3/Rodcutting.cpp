//2017029770 yunhee_seo
#include <stdio.h>
int r[200];
int s[200];
int p[200];
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int j=1;j<=n;j++){
		int q=-987654321;
		for(int k=1;k<=j;k++){
			if(q<p[k]+r[j-k]){
				q=p[k]+r[j-k];
				s[j]=k;
			}
			r[j]=q;
		}
	}
	printf("%d\n",r[n]);
	while(n>0){
		printf("%d ",s[n]);
		n-=s[n];
	}
	return 0;
}



