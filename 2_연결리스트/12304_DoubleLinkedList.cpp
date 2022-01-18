#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NODE 10000

enum { ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

extern void init();
extern void addNode2Head(int data);
extern void addNode2Tail(int data);
extern void addNode2Num(int data, int num);
extern int findNode(int data);
extern void removeNode(int data);
extern int getList(int output[MAX_NODE]);
extern int getReversedList(int output[MAX_NODE]);

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

static void run() {
	while (1) {
		int cmd, data, num, cnt, i = 0;
		int output[MAX_NODE] = { 0 };

		scanf("%d", &cmd);
		switch (cmd) {
		case ADD_HEAD: // 1
			scanf("%d", &data);
			addNode2Head(data);
			break;
		case ADD_TAIL: // 2
			scanf("%d", &data);
			addNode2Tail(data);
			break;
		case ADD_NUM: // 3
			scanf("%d %d", &data, &num);
			addNode2Num(data, num);
			break;
		case FIND: // 4
			scanf("%d", &data);
			num = findNode(data);
			printf("%d\n", num);
			break;
		case REMOVE: // 5
			scanf("%d", &data);
			removeNode(data);
			break;
		case PRINT: // 6
			cnt = getList(output);
			while (cnt--)
				printf("%d ", output[i++]);
			printf("\n");
			break;
		case PRINT_REVERSE: // 7
			cnt = getReversedList(output);
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
	//freopen("dll_input.txt", "r", stdin);

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
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}

// 맨 앞에 노드 추가
void addNode2Head(int data) 
{
    Node* newNode = getNode(data);
    head->next->prev = newNode;
    newNode->next = head->next;
	head->next = newNode;
    newNode->prev = head;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
    Node* newNode = getNode(data);
    tail->prev->next = newNode;
    newNode->prev = tail->prev;
	tail->prev = newNode;
    newNode->next = tail;    
}

// 지정된 순서(num)에 노드 추가 (1 - 2 - 3 - 4 - 5 - ...)
void addNode2Num(int data, int num) 
{
    Node *now = head;
	Node *newNode = getNode(data);
	for (int i = 1; i < num; i++) {
		now = now->next;
	}
    now->next->prev = newNode;
    newNode->next = now->next;
	now->next = newNode;
    newNode->prev = now;
}

// data를 가진 노드의 순서를 리턴
int findNode(int data) 
{
    int idx = 1;
    Node *now = head;
    while (now->next->data != data) {
        now = now->next;
        idx++;
        if (now->next == nullptr)
			return -1;
    }
    return idx;
}

// data를 가진 노드를 삭제
void removeNode(int data) 
{
	Node *now = head;
	while (now->data != data) {
		if (now->next == nullptr)
			return;

		now = now->next;
	}
	now->next->prev = now->prev;
    now->prev->next = now->next;
}

// 노드의 data 정보를 차례대로 output[] 배열에 저장하고 노드 갯수를 리턴
int getList(int output[MAX_NODE]) 
{
	int idx = 0;
	Node *now = head;
	while (now->next != nullptr && now->next->data != -1) {
		output[idx++] = now->next->data;
		now = now->next;
	}
	return idx;
}

// 노드의 data 정보를 역순으로 output[] 배열에 저장하고 노드 갯수를 리턴
int getReversedList(int output[MAX_NODE]) 
{
	int idx = 0;
	Node *now = tail;
	while (now->prev != nullptr && now->prev->data != -1) {
		output[idx++] = now->prev->data;
		now = now->prev;
	}
	return idx;
}