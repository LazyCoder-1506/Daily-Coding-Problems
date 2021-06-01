class Node:
  def __init__(self, val, left = None, right = None):
    self.val = val
    self.left = left
    self.right = right

def serialise(root):
  if not root:
    return '#'
  s = str(root.val) + ' ' + serialise(root.left) + ' ' + serialise(root.right)
  return s

def deserialise(s):
  ss = s.split(' ')
  if len(ss) == 0 or ss[0] == '#':
    print ('Root none')
    ss.pop(0)
    return [None, (' '.join(ss))]
  newroot = Node(int(ss[0]))
  print ('root ' + ss[0])
  ss.pop(0)
  print('going left')
  [newroot.left, s] = deserialise(' '.join(ss))
  print('going right')
  [newroot.right, s] = deserialise(s)
  return [newroot, s]

if __name__ == '__main__':
  root = Node(1)
  root.left = Node(2)
  root.right = Node(3)
  root.left.left = Node(4)
  root.left.right = Node(5)

  s = serialise(root)

  print(s)

  deserialise(s)