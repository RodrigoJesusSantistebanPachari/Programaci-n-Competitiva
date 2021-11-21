#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() <= 0)
		return NULL;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : lists){
        ListNode *tmp = i;
        while(tmp != NULL){
            pq.push(tmp->val);
            tmp = tmp->next;
        }
    }
    
    if(pq.empty())
        return NULL;
    
    ListNode *aux2 = new ListNode(pq.top());
    pq.pop();
    ListNode *aux3 = aux2;
    while(!pq.empty()){
        ListNode *n = new ListNode(pq.top());
        aux3->next = n;
        pq.pop();
        aux3 = aux3->next;
    }
    
    aux3->next = NULL;
    
    return aux2;
}

int main(){
	
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(4);
	ListNode *a4 = new ListNode(5);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	
	ListNode *b1 = new ListNode(1);
	ListNode *b2 = new ListNode(5);
	ListNode *b3 = new ListNode(9);
	b1->next = b2;
	b2->next = b3;
	
	vector<ListNode*> lists;
	lists.push_back(a1);
	lists.push_back(b1);

	//Muestra el merge
	ListNode * resultado = mergeKLists(lists);
	while(resultado->next != nullptr){
		cout<<resultado->val<<" ";
		resultado = resultado->next;
	}
	cout<<resultado->val<<" ";
	
	

	
	return 0;
}
