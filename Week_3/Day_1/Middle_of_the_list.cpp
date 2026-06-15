#include<iostream>
using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x){
    val=x;
    next=NULL;
  }
};
ListNode* middleNode(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast != NULL && fast->next !=NULL){
        slow= slow->next;
        fast=fast->next->next;
       }
       return slow;
    }
int main(){
    ListNode* head = new ListNode(1);
ListNode* temp = head;

for (int i = 2; i <= 5; i++) {
    temp->next = new ListNode(i);
    temp = temp->next;
}
ListNode* result=middleNode(head);
cout<<"The Middle Node is: "<<result->val;
}