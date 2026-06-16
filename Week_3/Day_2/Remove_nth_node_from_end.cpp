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
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        temp=head;
         ListNode* nextNode;
        if(size-n==0){
            return temp->next;
        }
        
       else{
            for(int i=0;i<size-n-1;i++){
                temp=temp->next;
            }
            nextNode=temp->next->next;
            temp->next=nextNode;
            return head;
       }
    }
void printList(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"  ";
        temp= temp->next;
    }
    cout<<endl;
}
int main(){
    ListNode* head=new ListNode(1);
    ListNode* n1=new ListNode(3);
    ListNode* n2=new ListNode(4);
    head->next=n1;
    n1->next=n2;
    n2->next=NULL;
    cout<<"Before Deletion: ";
    printList(head);
    int n=2;
    ListNode* newhead=removeNthFromEnd(head,n);
    cout<<"After Deletion: ";
    printList(newhead);

}