#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * reversethelinklist(ListNode * head){
        ListNode * ptr=head;
        ListNode * temp=NULL;
        ListNode * rev=NULL;
        while(ptr!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
            if(!rev)
            {
                temp->next=NULL;
                rev=temp;
            }
           else{
                temp->next=rev;
                rev=temp;   
           }     
           

        }
        
    return  rev;
}

//middle of linklist 

int getMiddle(ListNode *head)
{
    // Your code here
    if(!head || !head->next) return head->val;
            ListNode * fast=head;
            ListNode *slow=head;
            while(slow!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow->val;
        
}