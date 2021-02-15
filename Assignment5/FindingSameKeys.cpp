//2017029770 seoyunhee
#include <stdio.h>
#include <set>
using namespace std;
int num;
int main() {
		set <int> s;
			int a, b;
				scanf("%d %d", &a, &b);
					for (int i = 0; i < a; i++){
								int k;
										scanf("%d", &k);
												s.insert(k);
													}
						num = s.size();
							for (int i = 0; i < b; i++) {
										int l;
												scanf("%d",&l);
														s.insert(l);
															}
								printf("%d", a+b-s.size());
									return 0;
}
