#include <vector>
#include <iostream>

using namespace std;

struct LinkNode {
    int val;
    struct LinkNode *next;
    LinkNode(){};
    LinkNode(int val):val(val){};
};

LinkNode *partition(LinkNode *head, LinkNode *start, LinkNode *tail) {

    LinkNode *k = start;
    int pivot = start->val;
    for (LinkNode *i = start->next;  i != tail; i = i->next) {
        if (i->val <= pivot) {
            k = k->next;
            swap(k->val, i->val);
        }
    }
    swap(start->val, k->val);
    return k;
}

void quickSort(LinkNode *head, LinkNode *start, LinkNode *tail) {

    if (start != tail && start->next != tail) {
        LinkNode *k = partition(head, start, tail);
        quickSort(head, start, k);
        quickSort(head, k, tail);
    }
}


void createLink(vector<int> &arr, LinkNode *start) {

    for (int i = 1; i < arr.size(); i++) {
        start->next = new LinkNode(arr[i]);
        start = start->next;
    }
}

LinkNode *reverse (LinkNode *head) {

    int k = 2;
    int start = k;
    LinkNode *p = head;
    LinkNode *newHead = new LinkNode(), *q = newHead;

    LinkNode *curEnd = nullptr;

    while (p != nullptr) {
        if (start == k) {
            curEnd = p;
        }
        LinkNode *temp = p->next;
        p->next = q->next;
        q->next = p;
        p = temp;
        start--;

        if (start <= 0) {
            q = curEnd;
            start = k;
        }
    }

    LinkNode *ans = newHead->next;
    delete newHead;

    return ans;

}

int main1() {

    vector<int> arr = {3, 7, 8, 1, 2, 3, 6, 3};
    LinkNode *begin = new LinkNode(arr[0]), *k = begin;

    createLink(arr, begin);

    while (k != nullptr) {
        cout << "k: " << k->val << " ,";
        k = k->next;
    }

    /*
    Data data = Data{};
    Data & data1 = data;
    Data & data2 = Data{};
    Data && data3 = Data{};
    Data && data4 = data;
    Data && data5 = std::move(data);
    */
    return 0;
}
