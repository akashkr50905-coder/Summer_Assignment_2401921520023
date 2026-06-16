#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x){
    val=x;
    next=NULL;
  }
};
bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int>v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
       vector<int> rev(v);                 
       reverse(rev.begin(), rev.end());       
        for(int i=0;i<v.size();i++){
            if(rev[i]!=v[i]){
                return false;
            }
        }
        return true;
    }
 

    int main(){
    ListNode* head=new ListNode(1);
    ListNode* n1=new ListNode(2);
    ListNode* n2=new ListNode(1);
    head->next=n1;
    n1->next=n2;
    n2->next=NULL;
    cout<<isPalindrome(head);
    }