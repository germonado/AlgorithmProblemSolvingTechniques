//2017029770_Seoyunhee
#include<stdio.h>
#include<stdlib.h>
int N, num, S, i, k;
char name[5];
int huff_size;
int esize;
typedef struct Element {
		int value;
			struct Element *left_child;
				struct Element *right_child;
}Element;
Element hufftree[35000];
Element tem[30001];
void Insert(Element e) {
		i = ++esize;

			while ((i != 1) && (e.value < hufftree[i / 2].value)) {
						hufftree[i] = hufftree[i / 2];
								i = i / 2;
									}

				hufftree[i] = e;
}
void CreateHeap(int size) {
		int i;
			esize = 0;
				for (i = 0; i < size; i++) {
							if (tem[i].value) {
											Insert(tem[i]);
													}
								}
}
Element *Delete() {
		int parent = 1, child = 2;
			Element *e = (Element*)malloc(sizeof(Element));
				Element tmp;

					*e = hufftree[parent];
						tmp = hufftree[esize--];

							while (child <= esize) {
										if ((child < esize) && (hufftree[child].value > hufftree[child + 1].value)) {
														child++;
																}

												if (tmp.value < hufftree[child].value) {
																break;
																		}

														hufftree[parent] = hufftree[child];
																parent = child;
																		child *= 2;
																			}

								hufftree[parent] = tmp;

									return e;
}
Element *HuffmanTree() {

		Element *e1, *e2;
			Element tmp;

				while (esize > 1) {
							e1 = Delete();
									e2 = Delete();
											tmp.value = e1->value + e2->value;
													tmp.left_child = e1;
															tmp.right_child = e2;
																	Insert(tmp);
																		}

					return &(hufftree[1]);
}
void CheckHuff(Element *e, int size) {

		if (e->left_child) {
					CheckHuff(e->left_child, size + 1);
						}
			if (e->right_child) {
						CheckHuff(e->right_child, size + 1);
							}

				if (!(e->left_child) && !(e->right_child)) {
							huff_size += e->value * size;
								}
}
int main() {
		Element *e;
			scanf("%d", &N);
				for (i = 0; i < N; i++) {
							scanf("%s %d", name, &num);
									tem[i].value = num;
											tem[i].left_child = NULL;
													tem[i].right_child = NULL;
														}
					scanf("%d", &S);
						CreateHeap(N);
							e = HuffmanTree();
								CheckHuff(e, 0);
									N--;
										while (N > 0) {
													k++;
															N /= 2;
																}
											if (k == 0) {
														k++;
															}
												printf("%d\n%d\n", k * S, huff_size);
													return 0;
}
