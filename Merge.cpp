//2017029770 yunhee seo
#include <stdio.h>
int arr[100000];
int in;
int i;
int j;
int merge(int p, int q, int r){
		int a = q-p+1;
			int b = r-q;
				int arL[a+1];
					int arR[b+1];
						for(i=1;i<=a;i++){
									arL[i]=arr[p+i-1];
										}
							for(j=1;j<=b;j++){
										arR[j]=arr[q+j];
											}
								arL[a+1]=arR[b+1]=987654321;
									i=j=1;
										for(int k=p;k<=r;k++){
													if(arL[i]<=arR[j]){
																	arr[k]=arL[i];
																				i+=1;
																						}
															else{
																			arr[k]=arR[j];
																						j+=1;
																								}
																}
											return 0;
}
int merge_s(int p, int r){
		int q;
			if(p<r){
						q=(p+r)/2;
								merge_s(p,q);
										merge_s(q+1,r);
												merge(p,q,r);
													}
				return 0;
}
int main(){
		scanf("%d",&in);
			for(i=0;i<in;i++){
						scanf("%d",&arr[i]);
							}
				merge_s(0,in-1);
					 for(i=in-1;i>=0;i--){
						 		 printf("%d\n",arr[i]);
								 	 }
					 	 return 0;
}
