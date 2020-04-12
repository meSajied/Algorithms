class Node:
    def __init__(self, data:int) -> int:  
        self.data = data  
        self.next = None

class LinkedList:
    def __init__(self): 
        self.head = None

    def push(self, new_data:int) -> int:
        new_node = Node(new_data) 
        new_node.next = self.head 
        self.head = new_node
        return self.head.data

    def middle_element(self) -> int:
        slow_pointer = self.head
        fast_pointer = self.head
        if self.head is not None: 
            while (fast_pointer is not None and fast_pointer.next is not None): 
                fast_pointer = fast_pointer.next.next
                slow_pointer = slow_pointer.next
            return slow_pointer.data
        else:
            print("Found Nothing....")
            
if __name__ == "__main__":
    link = LinkedList()
    N = int(input().strip())

    for i in range(N):
        data = int(input().strip())
        link.push(data)
    print(link.middle_element())