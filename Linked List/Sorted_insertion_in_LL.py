class Node:
	def __init__(self, data):
		self.val = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def sortedInsert(self, new_node):
		if not self.head:
			new_node.next=self.head
			self.head = new_node

		elif new_node.val <= self.head.val : 
			new_node.next = self.head
			self.head = new_node

		else:
			current = self.head
			while(current.next is not None and current.next.val < new_node.val):
				current = current.next
			new_node.next = current.next
			current.next = new_node

	def push(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node

	def printList(self):
		temp = self.head
		while(temp):
			print(temp.val)
			temp = temp.next

# driver code
llist = LinkedList() 
new_node = Node(5) 
llist.sortedInsert(new_node) 
new_node = Node(10) 
llist.sortedInsert(new_node) 
new_node = Node(7) 
llist.sortedInsert(new_node) 
new_node = Node(3) 
llist.sortedInsert(new_node) 
new_node = Node(1) 
llist.sortedInsert(new_node) 
new_node = Node(9) 
llist.sortedInsert(new_node) 
print("Create Linked List")
llist.printList() 
new_node = Node(4)
llist.sortedInsert(new_node)
print("Updated")
llist.printList()
