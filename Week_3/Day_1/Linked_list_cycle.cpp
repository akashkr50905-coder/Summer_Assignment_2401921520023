#include<iostream>
#include<list>
using namespace std;
struct ListNode{
      int val;
      ListNode* next;
      ListNode(int x){
        val=x;
        ListNode* next=NULL;
      }
    };
bool hasCycle(ListNode* head){
  ListNode* slow=head;
  ListNode* fast=head;
  while(fast!=NULL&& fast->next!=NULL){
       slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true; 
  }
  return false;
}
int main (){
    
    ListNode* n1= new ListNode(3);
    ListNode* n2= new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    ListNode* head=n1;
  cout<< hasCycle(head);
    return 0;
}