# bfloat16
Convert single precision float to bfloat16 (Brain Floating Point) floating-point format

## Build the shared lib
    g++ -shared -c -fPIC fp32tobf16.c -o fp32tobf16.o
    g++ -shared -Wl,-soname,fp32tobf16.so -o fp32tobf16.so fp32tobf16.o

To binnd with python, see test_fp32tobf16.py
