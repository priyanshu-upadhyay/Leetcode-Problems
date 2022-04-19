// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    Node *less = NULL, *equals = NULL, *greater = NULL;
    Node *lessCurr = NULL, *equalsCurr = NULL, *greaterCurr = NULL;
    
    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->data < x)
        {
            if(lessCurr == NULL)
            {
                less = new Node(curr->data);
                lessCurr = less;
            }
            else
            {
                lessCurr->next = new Node(curr->data);
                lessCurr = lessCurr->next;
            }
        }
        else if(curr->data == x)
        {
            if(equalsCurr == NULL)
            {
                equals = new Node(curr->data);
                equalsCurr = equals;
            }
            else
            {
                equalsCurr->next = new Node(curr->data);
                equalsCurr = equalsCurr->next;
            }
        }
        else
        {
            if(greaterCurr == NULL)
            {
                greater = new Node(curr->data);
                greaterCurr = greater;
            }
            else
            {
                greaterCurr->next = new Node(curr->data);
                greaterCurr = greaterCurr->next;
            }
        }
        curr = curr->next;
    }
    
    if(less == NULL && equals == NULL)
    {
        return greater;
    }
    else if(less == NULL && greater == NULL)
    {
        return equals;
    }
    else if(equals == NULL && greater == NULL)
    {
        return less;
    }
    else if(less == NULL)
    {
        equalsCurr->next = greater;
        return equals;
    }
    else if(equals == NULL)
    {
        lessCurr->next = greater;
        return less;
    }
    else if(greater == NULL)
    {
        lessCurr->next = equals;
        return less;
    }
    else
    {
        lessCurr->next = equals;
        equalsCurr->next = greater;
        return less;
    }
    
    
}