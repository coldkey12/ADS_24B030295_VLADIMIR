class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def insert_node(head, data, position):
    new_node = Node(data)
    if position == 0:
        new_node.next = head
        return new_node

    cur = head
    index = 0
    while cur and index < position - 1:
        cur = cur.next
        index += 1

    new_node.next = cur.next
    cur.next = new_node
    return head

n = int(input())
head = None
tail = None
for _ in range(n):
    val = int(input())
    node = Node(val)
    if not head:
        head = node
        tail = node
    else:
        tail.next = node
        tail = node

data = int(input())
position = int(input())
head = insert_node(head, data, position)

cur = head
out = []
while cur:
    out.append(str(cur.val))
    cur = cur.next
print(' '.join(out))