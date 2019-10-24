# first, build the shared library
# g++ -shared -c -fPIC fp32tobf16.c -o fp32tobf16.o
# g++ -shared -Wl,-soname,fp32tobf16.so -o fp32tobf16.so fp32tobf16.o
#

from ctypes import *
import argparse

parser = argparse.ArgumentParser(description='Convert fp32 to bfloat16 Example')
parser.add_argument('floats', type=float, metavar='F', nargs='+',
                    help='input float numbers')
parser.add_argument('--lib', type=str, default="./fp32tobf16.so",
                    help='filename for the shared lib')

args = parser.parse_args()
lib = CDLL(args.lib)
fp32tobf16 = lib.fp32tobf16
fp32tobf16.argtypes = [c_float]
fp32tobf16.restype = c_float

for x in args.floats:
    y = fp32tobf16(x)
    print("float32 {} -> bfloat16 {}".format(x, y))
