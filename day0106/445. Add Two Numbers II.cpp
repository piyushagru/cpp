/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1,v2;
        while(l1){//
            v1.push_back(l1->val);
            l1 = l1->next;
        }//
        while(l2){//
            v2.push_back(l2->val);
            l2 = l2->next;
        }//
        int n = v1.size(); int m = v2.size();
        int sum = 0;
        int carry = 0;
        // vector<int> sol;
        ListNode *solList = nullptr;
        ListNode *p = nullptr;
        
        for(int i = n-1,j = m-1; i>=0 or j>=0 or carry > 0;){//carry > 0 works for single digit number for ex if we have 5 + 5 it will give 0 as answer without carry >0 cause it will not get inside the loop.
        if(i>=0){// 
        sum += v1[i];
        i--;
        }//
        if(j>=0){//
        sum += v2[j];
        j--;
        }//
            
        solList = new ListNode(sum%10);
            solList->next = p;
            p = solList;
            // sol.push_back(sum%10);
        carry = sum/10;
        sum = carry;
    }//
//         auto it = sol.end()-1;
//         ListNode *solList = nullptr;
//         int temp = *it;
//         solList = new ListNode(temp);
//         it--;
//         // solList = solList -> next;
        
//             for(; it>=sol.begin();it--){//
                
//                 temp = *it;
//                 solList->next = new ListNode(temp);
//                 // solList = solList -> next;
                
//             }// 
         return solList;   
    }
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    