#include "kb_utils.h"

static BYTE get_bit(BYTE byte)
{
    BYTE pos = 0;
    
    while ((byte > 1) && (pos < 4))
    {
        byte >>= 1;
        pos++;
    }
    return pos;
}
