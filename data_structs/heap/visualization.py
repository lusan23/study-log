import cProfile

from heap import Heap
hp = Heap()
hp.set_name("Heap Data Structure")
cProfile.run("hp.insert(hp.root, 10)\nhp.insert(hp.root, 20)\nhp.insert(hp.root, 20)")
