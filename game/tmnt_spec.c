#include "game_spec.h"
#include "genesis_runtime.h"
#include <stddef.h>
#include <stdint.h>

static void tmnt_call_entry_point(void) {
    recomp_call_addr(0x000208u);
}
static void tmnt_call_vblank(void) {
    recomp_call_addr(0x0004DEu);
}
static void tmnt_call_hblank(void) {
    recomp_call_addr(0x0004DCu);
}

const GameSpec g_game_spec = {
    .display_name        = "TMNT: The Hyperstone Heist",
    .short_name          = "TMNT",
    .expected_rom_crc32  = 0x679C41DEu,
    .expected_rom_size   = 0x100000u,
    .tier3_floor_default = 1,
    .call_entry_point    = tmnt_call_entry_point,
    .call_vblank         = tmnt_call_vblank,
    .call_hblank         = tmnt_call_hblank,
};
