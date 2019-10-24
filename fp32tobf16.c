extern "C" float fp32tobf16(float x)
{
    float y = x;
    int *p = (int *) &y;
    unsigned int exp, man;
    exp = *p & 0x7F800000u;
    man = *p & 0x007FFFFFu;
    if (exp == 0 && man == 0) {
        // zero
        return x; 
    }
    if (exp == 0x7F800000u) {
        // infinity or Nans
        return x;
    }
    // Normalized number
    // round to nearest
    float r = x;
    int *pr = (int *) &r;
    *pr &= 0xff800000; // r has the same exp as x
    r = r / 256;
    y = x + r;

    *p &= 0xffff0000;

    return y;
}
