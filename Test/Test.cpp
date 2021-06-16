#include<stdio.h>
#include<malloc.h>
#define INT int

INT A = 0, B = 0, a[100] = { 0 }, b[100] = { 0 }, line[100][100] = { 0 }, used[100] = { 0 }, Object[100] = { 0 };

typedef struct node
{
	INT n;
	struct node* next;
};

typedef struct vertex
{
	INT color;
	INT n;
	struct node* head;
};

typedef struct graph
{
	struct vertex a[100];
	INT numNodes, numEdges;
};

struct graph* creat_graph()
{
	graph* G;
	G = (graph*)malloc(sizeof(graph));
	INT m, n, a, b;
	scanf("%d%d", &m, &n);//m个人，n个关系
	G->numNodes = m, G->numEdges = n;
	for (INT i = 0; i < m; i++)//m个节点初始化
	{
		G->a[i].n = i + 1;//a[0]存的节点是1
		G->a[i].color = 0;
		G->a[i].head = NULL;
	}
	for (INT i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);//头插法
		node* NEW_1 = (node*)malloc(sizeof(node));
		NEW_1->n = b;
		NEW_1->next = G->a[a - 1].head;
		G->a[a - 1].head = NEW_1;

		node* NEW_2 = (node*)malloc(sizeof(node));
		NEW_2->n = a;
		NEW_2->next = G->a[b - 1].head;
		G->a[b - 1].head = NEW_2;
	}
	return G;
}

INT judge(graph* G)
{
	//0无色，1红色，2蓝色
	INT right_color = 0;
	if (G->numNodes < 2)
		return 0;
	for (INT i = 0; i < G->numNodes; i++)
	{
		if (G->a[i].color == 0)//若无色则给初始点赋色
			G->a[i].color = 1;
		if (G->a[i].color == 1)//确定相邻的点的颜色
			right_color = 2;
		else
			right_color = 1;
		node* temp = G->a[i].head;
		while (temp != NULL)
		{
			if (G->a[temp->n - 1].color == 0 || G->a[temp->n - 1].color == right_color)//减一因为a[i]存的是i+1点
				G->a[temp->n - 1].color = right_color;
			else
				return 0;
			temp = temp->next;
		}
	}
	return 1;
}

int main()
{
	freopen("C:\\Users\\11739\\Desktop\\test.txt", "r", stdin);
	graph* G;
	G = creat_graph();
	if (judge(G))
	{
		//是二分图
		INT* x = a, * y = b;
		for (INT i = 0; i < G->numNodes; i++)
		{
			if (G->a[i].color == 1)
			{
				A++;
				*x = G->a[i].n;
				x++;
			}
			else
			{
				B++;
				*y = G->a[i].n;
				y++;
			}
		}

		for (INT i = 0; i < A; i++)
		{
			node* temp = G->a[a[i]-1].head;
			printf("%d", temp->n);
			while (temp != NULL)
			{

			}
		}

		for (INT i = 0; i < A; i++)
		{
			for (INT k = 0; k < B; k++)
			{
				printf("%d ", line[i][k]);
			}
			printf("\n");
		}

		/*
		for (INT i = 0; i < A; i++)
			printf("%d ", a[i]);
		printf("\n");
		for (INT i = 0; i < B; i++)
			printf("%d ", b[i]);
		*/
		//		printf("Yes\n");
	}
	else
		printf("NO\n");


	fclose(stdin);
}
