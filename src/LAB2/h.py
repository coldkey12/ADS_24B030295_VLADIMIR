class Node:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def insert(head, node, p):
    if p == 0:
        node.next = head
        return node
    cur = head
    idx = 0
    while idx < p - 1 and cur:
        cur = cur.next
        idx += 1
    node.next = cur.next
    cur.next = node
    return head

def remove(head, p):
    if p == 0:
        return head.next
    cur = head
    idx = 0
    while idx < p - 1 and cur:
        cur = cur.next
        idx += 1
    if cur and cur.next:
        cur.next = cur.next.next
    return head

def printAll(head):
    if not head:
        print(-1)
        return
    res = []
    cur = head
    while cur:
        res.append(str(cur.val))
        cur = cur.next
    print(' '.join(res))

def replace(head, p1, p2):
    if not head or p1 == p2:
        return head
    if p1 == 0:
        node = head
        head = head.next
    else:
        cur = head
        idx = 0
        while idx < p1 - 1 and cur:
            cur = cur.next
            idx += 1
        node = cur.next
        cur.next = node.next
    if p2 == 0:
        node.next = head
        return node
    cur = head
    idx = 0
    while idx < p2 - 1 and cur:
        cur = cur.next
        idx += 1
    node.next = cur.next
    cur.next = node
    return head

def reverse(head):
    prev = None
    cur = head
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev

def cyclic_left(head, x):
    if not head or not head.next or x == 0:
        return head
    tail = head
    length = 1
    while tail.next:
        tail = tail.next
        length += 1
    x %= length
    if x == 0:
        return head
    cur = head
    for _ in range(x - 1):
        cur = cur.next
    new_head = cur.next
    cur.next = None
    tail.next = head
    return new_head

def cyclic_right(head, x):
    if not head or not head.next or x == 0:
        return head
    tail = head
    length = 1
    while tail.next:
        tail = tail.next
        length += 1
    x %= length
    if x == 0:
        return head
    return cyclic_left(head, length - x)

head = None

while True:
    vals = [int(i) for i in input().split()]
    if vals[0] == 0:
        break
    elif vals[0] == 1:
        head = insert(head, Node(vals[1]), vals[2])
    elif vals[0] == 2:
        head = remove(head, vals[1])
    elif vals[0] == 3:
        printAll(head)
    elif vals[0] == 4:
        head = replace(head, vals[1], vals[2])
    elif vals[0] == 5:
        head = reverse(head)
    elif vals[0] == 6:
        head = cyclic_left(head, vals[1])
    elif vals[0] == 7:
        head = cyclic_right(head, vals[1])