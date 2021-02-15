//2017029770 yunhee seo
#include <stdio.h>
#include <iostream>
int arr[30001];
int n;
int i;
int main(){
	  scanf("%d", &n);
	    for(i=1;i<=n;i++){
			     scanf("%d", &arr[i]);
				    }
		   int key=0;
			  int b=0;
			    for(int j=2;j<=n;j++){
					 	  key = arr[j];
						  	  b = j-1;
							  	  while(b>0 && arr[b]>key){
									  		  arr[b+1]=arr[b];
											  		  b-=1;
													  	  }
								  	  arr[b+1]=key;
				 }
				 for(int c =n;c>0;c--){
					 	printf("%d\n",arr[c]);
				 }
				 return 0;
}
