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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstIdx= -1 , prevIdx = -1;
        int idx = 1;

        ListNode* prev = head;    
        ListNode* curr = head -> next;

        int mn = INT_MAX;

        while(curr -> next != NULL && curr != NULL){
            bool maxima = (curr -> val > prev -> val && curr -> next -> val < curr -> val);

            bool minima = (curr -> val < prev -> val && curr -> val < curr -> next -> val);

            if(maxima || minima){
                if(firstIdx == -1){
                    firstIdx = idx;
                    prevIdx= firstIdx;
                }
                else{

                    mn = min(mn , idx - prevIdx );
                    prevIdx = idx;
                }
            }

            idx++;
            prev = curr;
            curr = curr -> next;
        }

        if(firstIdx == -1 || prevIdx == firstIdx) return {-1,-1};

        return {mn , prevIdx - firstIdx};
    }
};