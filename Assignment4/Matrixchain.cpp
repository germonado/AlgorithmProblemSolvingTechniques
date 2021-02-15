//2017029770_Seoyunhee
#include <stdio.h>
#define MAXINT 2147483647
int n;
int mat[105][105];
int m[105];
int s[105][105];
int porder(int i,int j){
		if(i==j) printf("%d ",i);
			else{
					int k = s[i][j];
						printf("( ");
							porder(i,k);
								porder(k+1,j);
									printf(") ");
										}
}
int main(){
		scanf("%d",&n);
			for(int i=0;i<n+1;i++){
						scanf("%d",&m[i]);
							}

				for(int l=2;l<=n;l++){
							for(int i=1;i<=n-l+1;i++){
											int j = i+l-1;
														mat[i][j]=MAXINT;
																	for(int k=i;k<=j-1;k++){
																						int cost = mat[i][k]+mat[k+1][j]+m[i-1]*m[k]*m[j];
																										if(cost<mat[i][j]){
																																mat[i][j]=cost;
																																					s[i][j]=k;
																																									}
																														}
																				}
									}
					printf("%d\n",mat[1][n]);
						porder(1,n);
							return 0;
}
