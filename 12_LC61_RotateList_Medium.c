int lenList(struct ListNode* head)
{
    int count;

    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

struct ListNode* prevLastNode(struct ListNode* head)
{
    struct ListNode* node;

    node = head;
    while (head->next)
    {
        node = head;
        head = head->next;
    }
    return (node);
}

struct ListNode* lastNode(struct ListNode* head)
{
    while (head->next)
        head = head->next;
    return (head);
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode*    node;
    struct ListNode*    tail;
    struct ListNode*    prev;

    if (!head)
        return (NULL);
    if (!k)
        return (head);
    k = k % lenList(head);
    while(k > 0)
    {
        prev = prevLastNode(head);
        tail = lastNode(head);
        tail->next = head;
        head = tail;
        prev->next = NULL;
        k--;
    }
    return (head);
}
