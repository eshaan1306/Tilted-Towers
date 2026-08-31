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
        if (!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* front = head->next->next;
        vector<int> cps;
        int indx = 1;
        while(front){
            if ((cur->val > prev->val) && (cur->val > front->val)){
                cps.push_back(indx);
            }
            else if ((cur->val < prev->val) && (cur->val < front->val)){
                cps.push_back(indx);
            }
            indx++;
            prev = prev->next;
            cur = cur->next;
            front = front->next;
        }
        if (cps.size()<=1){
            return {-1,-1};
        }
        int maxDistance = cps.back()-cps[0];
        int minDistance = INT_MAX;
        for(int i=1;i<cps.size();i++){
            minDistance = min(minDistance,cps[i]-cps[i-1]);
        }
        return {minDistance,maxDistance};
    }
};
