import sys
f = open(sys.argv[1]+"/A/index.h", "w+")
f.write("int magicConst = 42;")
f.close()
