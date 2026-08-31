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
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head -> val);
            head = head -> next;
        }

        vector<int> dis;

        for(int i = 0 ; i < arr.size() ; i++){
            if(i > 0 && i < arr.size() - 1){

                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    dis.push_back(i+1);
                }
                if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
                    dis.push_back(i+1);
                }
            }
        }


        if(dis.size() < 2) return {-1,-1};

        if(dis.size() == 2) return {abs(dis[0] - dis[1]),abs(dis[0] - dis[1])};

        vector<int> ans(2);
        
        int mn = INT_MAX;
        for(int i = 1 ; i < dis.size() ; i++){

            mn = min(mn ,dis[i] -  dis[i-1] );
        }
        ans[0] = mn;
        ans[1] = dis[dis.size() - 1] - dis[0];
        return ans;
     }
};