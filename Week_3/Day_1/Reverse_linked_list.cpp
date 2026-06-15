#include<iostream>
#include<list>
using namespace std;
struct ListNode{
   int val;
   ListNode* next;
   ListNode(int x){
    val=x;
    next=NULL;
   }
};
ListNode* reverseList(ListNode* head){
ListNode* next=NULL;
ListNode* curr=head;
ListNode* prev=NULL;
 while(curr!=NULL){
    next= curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
 }
 return prev;
}
void printList(ListNode*head){
  ListNode* temp=head;
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
    ListNode* head = new ListNode(1);
ListNode* temp = head;

for (int i = 2; i <= 5; i++) {
    temp->next = new ListNode(i);
    temp = temp->next;
}
 cout<<"Original:";
 printList(head);
 ListNode* newhead= reverseList(head);
 cout<<"Reversed:";
 printList(newhead);
    return 0;
}