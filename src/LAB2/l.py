class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def findMaxSum(n: int, head: ListNode) -> int:
    max_sum = head.val
    current_sum = head.val
    node = head.next
    while node:
        current_sum = max(node.val, current_sum + node.val)
        max_sum = max(max_sum, current_sum)
        node = node.next
    return max_sum

n = int(input())
a = list(map(int, input().split()))
head = ListNode(a[0])
tail = head
for i in range(1, n):
    tmp = ListNode(a[i])
    tail.next = tmp
    tail = tmp
print(findMaxSum(n, head))