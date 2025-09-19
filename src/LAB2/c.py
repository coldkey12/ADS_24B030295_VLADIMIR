class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, val):
        new_node = Node(val)
        if not self.head:
            self.head = new_node
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = new_node

    def delete_every_second(self):
        cur = self.head
        while cur and cur.next:
            # skip the next node
            cur.next = cur.next.next
            cur = cur.next

    def to_list(self):
        res = []
        cur = self.head
        while cur:
            res.append(str(cur.val))
            cur = cur.next
        return res

n = int(input())
arr = list(map(int, input().split()))

ll = LinkedList()
for x in arr:
    ll.append(x)

ll.delete_every_second()
print(' '.join(ll.to_list()))