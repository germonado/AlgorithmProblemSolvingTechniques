//2017029770 yunhee_seo
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int parent[1001];
struct kru {
		int w;
			int l;
				int r;
};
bool cmp(const kru &p1, const kru &p2) {
		if (p1.w < p2.w) {
					return true;
						}
			else if (p1.w == p2.w) {
						if (p1.l < p2.l) {
										return true;
												}
								else if (p1.l == p2.l) {
												return p1.r < p2.r;
														}
										else {
														return false;
																}
											}
				else {
							return false;
								}
}
int Find(int x) {
		if (parent[x] == x) {
					return x;
						}
			return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
		x = Find(x);
			y = Find(y);
				if (x != y)
							parent[y] = x;
}
int main() {
		struct kru k[510000];
			int n;
				scanf("%d", &n);
					int a, b, c;
						for (int i = 0; i <= n; i++) {
									parent[i] = i;
										}
							int j = 1;
							  while (scanf("%d %d %d", &a, &b, &c) != EOF) {
								  		if (a<b) {
														k[j].l = a;
																	k[j].r = b;
																			}
												else {
																k[j].l = b;
																			k[j].r = a;
																					}
														k[j].w = c;
																j++;
																	}
							  	int cnt = 0;
									sort(k + 1, k + j+1, cmp);
										struct kru ans[1001];
											for (int i = 1; i <= j; i++) {
														if (Find(k[i].l) != Find(k[i].r)) {
																		cnt++;
																					Union(k[i].l, k[i].r);
																								ans[cnt].l = k[i].l;
																											ans[cnt].r = k[i].r;
																														ans[cnt].w = k[i].w;
																																}
															}
												printf("%d\n", cnt);
													for (int i = 1; i <= cnt; i++) {
																printf("%d %d %d\n", ans[i].l, ans[i].r, ans[i].w);
																	}

}
