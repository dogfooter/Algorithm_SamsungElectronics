#include <iostream>

#define MAX_NODE 2000

using namespace std;

struct Node {
    int data;
    Node* prev;
	Node* next;
} node[MAX_NODE];

int nodeCnt;
Node* head;
Node* tail;

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

void insertNode(int idx, int data) 
{
    Node *now = head;
	Node *newNode = getNode(data);
	for (int i = 0; i < idx; i++) {
		now = now->next;
	}
    now->next->prev = newNode;
    newNode->next = now->next;
	now->next = newNode;
    newNode->prev = now;
}

void deleteNode(int idx) 
{
	Node *now = head;
	for (int i = 0; i <= idx; i++) {
		now = now->next;
	}
	now->next->prev = now->prev;
    now->prev->next = now->next;
}

void changeNode(int idx, int data) 
{
	Node *now = head;
	for (int i = 0; i <= idx; i++) {
		now = now->next;
	}
	now->data = data;
}

int printNode(int idx) 
{
	Node *now = head;
	for (int i = 0; i <= idx; i++) {
        if (now->next == nullptr)
            return -1;
		now = now->next;
	}
	
    return now->data;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M, L, num, x, y;
    char op;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
        init();
        
        cin >> N >> M >> L;
        for (int i = 0; i < N; ++i) {
            cin >> num;
            addNode(num);
        }

        for (int i = 0; i < M; ++i) {
            cin >> op;
            switch (op) {
                case 'I':
                    cin >> x >> y;
                    insertNode(x, y);
                    break;
                
                case 'D':
                    cin >> x;
                    deleteNode(x);
                    break;
                
                case 'C':
                    cin >> x >> y;
                    changeNode(x, y);
                    break;
            }
        }
        

        cout << '#' << test_case << ' ' << printNode(L) << '\n';
	}
	return 0;
}