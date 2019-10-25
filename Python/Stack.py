class Stack:
    """Stack implementation in Python.
    Usage:
        s = Stack()
        print(s.is_empty())
        s.push(4)
        s.push('dog')
        print(s.peek())
        s.push(True)
        print(len(s))
        print(s.is_empty())
        s.push(8.4)
        print(s.pop())
        print(s.pop())
        print(len(s))
     """
     def __init__(self, items=None):
         self.items = [] if not items else items

     def is_empty(self):
         return bool(self.items)

     def push(self, item):
         self.items.append(item)

     def pop(self):
         if len(self.items) == 0:
             return None
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items) - 1]

     def __len__(self):
         return len(self.items)

