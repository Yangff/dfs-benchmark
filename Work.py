import os, shutil
from functools import *

# clean
def cleanup():
	if (os.path.exists("./Workspace/dfs")):
		os.remove("./Workspace/dfs")
	if (os.path.exists("./Workspace/pdfs")):
		os.remove("./Workspace/pdfs")
	if (os.path.exists("./Workspace/dm")):
		os.remove("./Workspace/dm")
	if (os.path.exists("./Workspace/in")):
		os.remove("./Workspace/in")
	if (os.path.exists("./Workspace/1.out")):
		os.remove("./Workspace/1.out")
def compile(klass, name ,o2):
	if (o2):
		os.system("g++ -O2 -o./Workspace/%s %s/%s.cpp -I."%(name, klass, name))
	else:
		os.system("g++ -o./Workspace/%s %s/%s.cpp -I."%(name, klass, name))
	if (not os.path.exists("./Workspace/%s"%name)):
		print("Cannot compile %s/%s.cpp."%(klass, name));
		exit(0)
def doTest(name, t):
	os.chdir("./Workspace")
	ret = 0
	for i in range(0, t):
		os.system("./%s > ./1.out"%(name))
		f = open("1.out")
		ret += reduce(lambda x,y:x/float(y), map(int, f.readline().split(" ")))
	os.chdir("../")
	return ret/float(t)
print("Test1 Union-Set");
#cleanup()
#compile("UnionSet", "dfs", False)
#compile("UnionSet", "pdfs", False)

#t1 = doTest("dfs", 10)
#t2 = doTest("pdfs", 10)
#print("Test1 Result: Dfs: %lf, PDfs:%lf"%(t1,t2))
#cleanup()
print("Test2 Tarjan");
cleanup()
compile("Tarjan", "dm", True)
compile("Tarjan", "dfs", True)
compile("Tarjan", "pdfs", True)
os.chdir("./Workspace")
os.system("./dm")
os.chdir("../")
t1 = doTest("dfs", 10)
t2 = doTest("pdfs", 10)
print("Test2 Result: Dfs: %lf, PDfs:%lf"%(t1,t2))
cleanup()
