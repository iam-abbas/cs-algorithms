class Node: 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  
class LinkedList: 
    def __init__(self): 
        self.head = None
    
    # Push value to the end of the list
    def push(self, data): 
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node

    # Floyd Cycle Loop Detection
    def detect_loop(self): 
        slow_p = self.head 
        fast_p = self.head 
        while(slow_p and fast_p and fast_p.next): 
            slow_p = slow_p.next
            fast_p = fast_p.next.next
            if slow_p == fast_p: 
                print("Found loop at value: ", slow_p.data)
                return 
  
    def print_list(self): 
        node = self.head 
        while(node): 
            print(node.data)
            node = node.next
  
linked_list = LinkedList() 
linked_list.push(1) 
linked_list.push(2) 
linked_list.push(3) 
linked_list.push(4) 
linked_list.push(5)
linked_list.push(6) 
linked_list.push(7) 

linked_list.print_list()

linked_list.head.next.next.next.next = linked_list.head.next.next
linked_list.detect_loop() 