#include "std.h"
#include "kb.h"

INT printf(const CHAR* str);

VOID EVM_events(BYTE key)
{
    switch (key)
    {
        case KEY_A:
            printf("[EVENTO URNA] VOTO EM BRANCO\n");
            break;
        case KEY_B:
            printf("[EVENTO URNA] CORRIGIR DIGITACAO\n");
            break;
        case KEY_C:
            printf("[EVENTO URNA] CONFIRMAR VOTO (TU-TU-TU!)\n");
            break;
        default:
            printf("[EVENTO URNA] DIGITO: %c\n", tecla);
            break;
    }
}

INT main()
{
    init_keyboard(EVM_events);
    
    tract_key(0x01, 0x08);
    tract_key(0x02, 0x02);
    tract_key(0x04, 0x08);

    return 0;
}
