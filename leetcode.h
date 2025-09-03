
int removeDuplicates(int* nums, int numsSize) {
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (index < 2 || nums[i] != nums[index - 2]) {
            nums[index++] = nums[i];
        }
    }

    return index;
}


Node* rotateRight(Node* head, long long k) {
    if (!head || !head->next || k == 0) return head;

    // 1) length and tail
    int n = 1;
    Node* tail = head;
    while (tail->next) { tail = tail->next; n++; }

    // 2) reduce k
    k %= n;
    if (k == 0) return head;

    // 3) circle
    tail->next = head;

    // 4) find new tail at position n - k - 1 (0-based)
    int steps = n - k - 1;
    Node* new_tail = head;
    while (steps--) new_tail = new_tail->next;

    // 5) slice
    Node* new_head = new_tail->next;
    new_tail->next = NULL;
    return new_head;
}