//2017029770 yunhee_seo
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <vector<int> > fs;
int chk[1001];
int blk = 1;
int groupnum[1001];
void dfs(int x) {
		chk[x] = 1;
			groupnum[x] = blk;
				for (int i = 0; i < fs[x].size(); i++) {
							if (chk[fs[x][i]] != 1) {
											dfs(fs[x][i]);
													}
								}
					return;
}
int main() {
		int n;
			scanf("%d", &n);
				fs.resize(n + 1);
					int a, b;
						while(scanf("%d %d", &a, &b)!=EOF){
									fs[a].push_back(b);
											fs[b].push_back(a);
												}
							for (int i = 1; i <= n; i++) {
										if (chk[i] == 0) {
														dfs(i);
																	blk++;
																			}
											}
								printf("%d\n",blk-1);
									for (int i = 1; i <= n; i++) {
												printf("%d\n", groupnum[i]);
													}
										return 0;
}
