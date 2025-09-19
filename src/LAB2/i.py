class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add_front(self, value):
        node = Node(value)
        if not self.head:
            self.head = self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node
        print("ok")

    def add_back(self, value):
        node = Node(value)
        if not self.tail:
            self.head = self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        print("ok")

    def erase_front(self):
        if not self.head:
            print("error")
            return
        val = self.head.value
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        print(val)

    def erase_back(self):
        if not self.tail:
            print("error")
            return
        val = self.tail.value
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        print(val)

    def front(self):
        if not self.head:
            print("error")
        else:
            print(self.head.value)

    def back(self):
        if not self.tail:
            print("error")
        else:
            print(self.tail.value)

    def clear(self):
        self.head = self.tail = None
        print("ok")

dll = DoublyLinkedList()
while True:
    try:
        cmd = input().strip().split()
    except EOFError:
        break
    if not cmd:
        continue
    if cmd[0] == "add_front":
        dll.add_front(cmd[1])
    elif cmd[0] == "add_back":
        dll.add_back(cmd[1])
    elif cmd[0] == "erase_front":
        dll.erase_front()
    elif cmd[0] == "erase_back":
        dll.erase_back()
    elif cmd[0] == "front":
        dll.front()
    elif cmd[0] == "back":
        dll.back()
    elif cmd[0] == "clear":
        dll.clear()
    elif cmd[0] == "exit":
        print("goodbye")
        break