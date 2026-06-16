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
ListNode* mergeList(ListNode* head1,ListNode* head2){
    if(head1==NULL||head2==NULL){
        return head1==NULL ? head2:head1;
    }
    if(head1->val < head2->val){
        head1->next=mergeList(head1->next,head2);
        return head1;
    }
    else{
        head2->next=mergeList(head1,head2->next);
        return head2;
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
    ListNode* head1=new ListNode(1);
    ListNode* n1=new ListNode(3);
    ListNode* n2=new ListNode(4);
    head1->next=n1;
    n1->next=n2;
    n2->next=NULL;
    cout<<"1st sorted list: "<<head1->val<<" ";
    cout<<n1->val<<" ";
    cout<<n2->val<<endl;
    ListNode* head2=new ListNode(1);
    ListNode* n3=new ListNode(5);
    ListNode* n4=new ListNode(6);
    head2->next= n3;
    n3->next=n4;
    n4->next=NULL;
    cout<<"2nd sorted list: "<<head2->val<<" ";
    cout<<n3->val<<" ";
    cout<<n4->val<<endl;
    ListNode* mainHead = mergeList(head1,head2);
    cout<<"Merged List: ";
    printList(mainHead);
 return 0;
}