#include <iostream>

#define MAX_NODE 10000

using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
} node[MAX_NODE];

Node* head;
Node* tail;
Node* tempHead;
Node* tempNow;

int nodeCnt;
int x, y, s;
int codeLen, code, opNum;
char op;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}

void addNode(int data)
{
    Node* newNode = getNode(data);
    tail->prev->next = newNode;
    newNode->prev = tail->prev;
	tail->prev = newNode;
    newNode->next = tail;    	
}

void makeInsertCode(int data) 
{
	Node* newNode = getNode(data);
	newNode->prev = tempNow;
	tempNow->next = newNode;
	tempNow = tempNow->next;
}

void insertNode(int idx) 
{
    Node *now = head;
	for (int i = 0; i < idx; i++) {
		now = now->next;
	}
	now->next->prev = tempNow;
    tempNow->next = now->next;
	now->next = tempHead;
    tempHead->prev = now;
}

void deleteNode(int idx, int num) 
{
    Node *now = head;
	Node *temp;

	for (int i = 0; i < idx; i++) now = now->next;
	temp = now;
	for (int i = 0; i < num; i++) now = now->next;
	
	now->next->prev = temp;
    temp->next = now->next;
}

void printNode()
{
	int idx = 0;
	Node *now = head;
	while (true) {
		if (idx == 10 || now->next->data == -1)
			break;
		
		cout << now->next->data << ' ';
		now = now->next;
		++idx;
	}
	cout << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;

	// freopen("input.txt", "r", stdin);
	// cin >> T;

	for (test_case = 1; test_case <= 10; ++test_case) {
		init();		
        cin >> codeLen;
		for (int i = 0; i < codeLen; ++i) {
			cin >> code;
			addNode(code);
		}
		cin >> opNum;
		for (int i = 0; i < opNum; ++i) {
			cin >> op;
			switch (op) {
				case 'I':
					tempNow = getNode(-1);
					cin >> x >> y;
					for (int j = 0; j < y; ++j) {
						cin >> code;
						makeInsertCode(code);
						if (j == 0) {
							tempHead = tempNow;
						}
					}
					insertNode(x);
					break;

				case 'D':
					cin >> x >> y;
					deleteNode(x, y);
					break;

				case 'A':
					cin >> y;
					for (int j = 0; j < y; ++j) {
						cin >> code;
						addNode(code);
					}
					break;
			}
		}

		cout << '#' << test_case << ' ';
		printNode();
	}
	return 0;
}