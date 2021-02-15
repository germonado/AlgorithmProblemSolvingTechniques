//2017092770 yunhee_seo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getMax(int x, int y) {
		return (x > y) ? x : y;
}
int main() {
		char X[500];
			char Y[500];
				char C[501][501] = { 0, };

					scanf("%s", X);
						scanf("%s", Y);
							int xy[2], lenx, leny, i, j;
								lenx = strlen(X);
									leny = strlen(Y);
										int l, s;
											if (lenx > leny) {
														l = lenx;
																s = leny;
																	}
												else {
															l = leny;
																	s = lenx;
																		}

													for (i = 0; i < s; i++) {
																for (j = 0; j < l; j++) {
																				if (lenx < leny) {
																									if (X[i] == Y[j]) {
																															C[i + 1][j + 1] = C[i][j] + 1;
																																			}
																													else {
																																			if (C[i][j + 1] > C[i + 1][j]) {
																																										C[i + 1][j + 1] = C[i][j + 1];
																																															}
																																								else {
																																															C[i + 1][j + 1] = C[i + 1][j];
																																																				}

																																												}
																																}
																							else {
																												if (Y[i] == X[j]) {
																																		C[i + 1][j + 1] = C[i][j] + 1;
																																						}
																																else {
																																						if (C[i][j + 1] > C[i + 1][j]) {
																																													C[i + 1][j + 1] = C[i][j + 1];
																																																		}
																																											else {
																																																		C[i + 1][j + 1] = C[i + 1][j];
																																																							}

																																															}
																																			}
																									}
																	}

														char * answer = (char*)malloc((s + 1) * sizeof(char));
															int t = 0;
																for (i = s, j = l; i > 0 && j > 0;) {
																			if (C[i][j] == C[i - 1][j]) {
																							i--;
																									}

																					else if (C[i][j] == C[i][j - 1]) {
																									j--;
																											}

																							else if (C[i][j] - 1 == C[i - 1][j - 1]) {
																											if (lenx > leny) {
																																answer[t++] = X[j - 1];
																																			}
																														else
																																			answer[t++] = Y[j - 1];

																																	i--; j--;
																																			}
																								}
																	int aa = t - 1;
																		char bb[500];
																			for (i = 0; i < t; i++) {
																						bb[aa--] = answer[i];
																							}
																				for (i = 0; i < t; i++) {
																							printf("%c", bb[i]);
																								}
																					printf("\n");

																						return 0;
}
