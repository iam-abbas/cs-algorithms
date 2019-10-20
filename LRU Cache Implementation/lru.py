from lru import LRU
l = LRU(5)         # Create an LRU container that can hold 5 items

print (l.peek_first_item(), l.peek_last_item())  #return the MRU key and LRU key
# Would print None None

for i in range(5):
   l[i] = str(i)
print(l.items())    # Prints items in MRU order
# Would print [(4, '4'), (3, '3'), (2, '2'), (1, '1'), (0, '0')]

print(l.peek_first_item(), l.peek_last_item())  #return the MRU key and LRU key
# Would print (4, '4') (0, '0')

l[5] = '5'         # Inserting one more item should evict the old item
print(l.items())
# Would print [(5, '5'), (4, '4'), (3, '3'), (2, '2'), (1, '1')]

l[3]               # Accessing an item would make it MRU
print(l.items())
# Would print [(3, '3'), (5, '5'), (4, '4'), (2, '2'), (1, '1')]
# Now 3 is in front

l.keys()           # Can get keys alone in MRU order
# Would print [3, 5, 4, 2, 1]

del l[4]           # Delete an item
print(l.items())
# Would print [(3, '3'), (5, '5'), (2, '2'), (1, '1')]

print(l.get_size())
# Would print 5

l.set_size(3)
print(l.items())
# Would print [(3, '3'), (5, '5'), (2, '2')]
print(l.get_size())
# Would print 3
print(l.has_key(5))
# Would print True
print(2 in l)
# Would print True

l.get_stats()
# Would print (1, 0)


l.update(5='0')           # Update an item
print l.items()
# Would print [(5, '0'), (3, '3'), (2, '2')]

l.clear()
print l.items()
# Would print []

def evicted(key, value):
  print "removing: %s, %s" % (key, value)

l = LRU(1, callback=evicted)

l[1] = '1'
l[2] = '2'
# callback would print removing: 1, 1

l[2] = '3'
# doesn't call the evicted callback

print l.items()
# would print [(2, '3')]

del l[2]
# doesn't call the evicted callback

print l.items()
# would print []