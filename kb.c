#include "kb_utils.h"
#include "kb.h"

static EVMCallback callback_events = 0;
static BYTE last_pressed_key = INVALID_KEY;
static DWORD ticks_debouncing = 0;

VOID init_keyboard(EVMCallback callback)
{
    callback_events = callback;
    last_pressed_key = INVALID_KEY;
    ticks_debouncing = 0;
}

VOID tract_key(BYTE line_mask, BYTE column_mask)
{
    BYTE lin = get_bit(line_mask);
    BYTE col = get_bit(column_mask);

    if (lin >= 4 || col >= 4) return;
    BYTE key = key_map[lin][col];

    if (key == INVALID_KEY) return;
  
    if (key == last_pressed_key && ticks_debouncing < 50)
    {
        ticks_debouncing++;
        return;
    }

    last_pressed_key = key;
    ticks_debouncing = 0;

    if (callback_events)
    {
        callback_events(key);
    }
}
