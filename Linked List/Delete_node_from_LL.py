class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def DeleteNode(self, value):
		if self.head==None:
			print('Empty List')
		else:
			prev = None
			curr = self.head 
			while(curr):
				if curr.data == value:
					if prev:
						prev.next = curr.next
					else:
						self.head = curr.next
					return True
				prev = curr
				curr = curr.next
			return False
	
			

	def push(self, new_node):
		if not self.head:
			self.head = new_node
		else:
			current=self.head
			while(current.next):
				current = current.next
			current.next = new_node
			new_node.next = None 



	def printlist(self):
		curr = self.head
		while(curr):
			print(curr.data)
			curr = curr.next

# driver code
llist = LinkedList()
newval = Node(2)
llist.push(newval)
newval = Node(6)
llist.push(newval)
newval = Node(1)
llist.push(newval)
newval = Node(5)
llist.push(newval)
print("Created Linked List")
llist.printlist()
if(llist.DeleteNode(1)):
	print('Deleted')
else:
	print("Node not found")
llist.printlist()
if(llist.DeleteNode(9)):
	print('Deleted')
else:
	print("Node not found")
llist.printlist()