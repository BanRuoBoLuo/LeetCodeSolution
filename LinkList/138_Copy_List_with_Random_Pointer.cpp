/******************************************************************************************
138. Copy List with Random Pointer
Medium

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

 

Example 1:

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

******************************************************************************************/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *curr = head;
        while(curr != nullptr) {
            Node* copy = new Node(curr->val, nullptr, nullptr);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        curr = head;
        while(curr != nullptr) {
            if(curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        Node dummy(0, nullptr, nullptr);
        Node* new_curr = &dummy;
        curr = head;
        while(curr != nullptr) {
            new_curr->next = curr->next;
            new_curr = new_curr->next;
            
            curr->next = new_curr->next;
            curr = curr->next;
        }
        
        return dummy.next;
    }
};