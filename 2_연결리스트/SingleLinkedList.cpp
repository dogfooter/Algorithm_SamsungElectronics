#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
Node* head;
int nodeCnt;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD:
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL:
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM:
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case REMOVE:
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT:
			cnt = getList(output);
			i = 0;
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case END:
			return;
		}
	}
}

int main(void) {
	//setbuf(stdout, NULL);
	//freopen("sll_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		init();
		run();
		printf("\n");
	}

	return 0;
}

// 초기화
void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

// 맨 앞에 노드 추가
void addNode2Head(int data) 
{
	Node* newNode = getNode(data);
	newNode->next = head->next ;
	head->next = newNode;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
	Node* now = head;
	Node* newNode = getNode(data);
	while (now->next != nullptr) {
		now = now->next;
	}
	now->next = newNode;
}

// 지정된 순서(num)에 노드 추가 (1 - 2 - 3 - 4 - 5 - ...)
void addNode2Num(int data, int num) 
{
	Node *now = head;
	Node *newNode = getNode(data);
	for (int i = 1; i < num; i++) {
		now = now->next;
	}
	newNode->next = now->next;
	now->next = newNode;
}

// 주어진 data 값을 가진 노드 삭제
void removeNode(int data) 
{
	Node *now = head;
	while (now->next->data != data) {
		now = now->next;
		if (now->next == nullptr)
			return;
	}
	now->next = now->next->next;
}

// output[] 배열에 리스트 노드의 data를 차례대로 넣고, 총 노드 갯수를 리턴
int getList(int output[MAX_NODE]) 
{
	int idx = 0;
	Node *now = head;
	while (now->next != nullptr) {
		output[idx++] = now->next->data;
		now = now->next;
	}
	return idx;
}