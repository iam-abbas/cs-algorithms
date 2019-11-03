from math import sqrt, pow

def distance(a, b):
  return sqrt(pow(a[0] - b[0],2) + pow(a[1] - b[1],2))

def bruteMin(points, current=float("inf")):
  if len(points) < 2: return current
  else:
    head = points[0]
    del points[0]
    newMin = min([distance(head, x) for x in points])
    newCurrent = min([newMin, current])
    return bruteMin(points, newCurrent)

def divideMin(points):
  half = len(sorted(points))/2
  minimum = min([bruteMin(points[:half]), bruteMin(points[half:])])
  nearLine = filter(lambda x: x[0] > half - minimum and x[0] < half + minimum, points)
  return min([bruteMin(nearLine), minimum])

list1 = [(12,30), (40, 50), (5, 1), (12, 10), (3,4)]
print divideMin(list1)
@ask2sm
