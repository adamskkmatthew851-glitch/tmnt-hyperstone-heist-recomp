/* MinGW entry shim: the bundled SDL2main.lib is MSVC-built and clashes with
 * MinGW's CRT startup. main.c's main() is remapped to SDL_main by SDL_main.h,
 * so provide a real main() that marks SDL ready and forwards. */
#define SDL_MAIN_HANDLED
#include <SDL.h>
extern int SDL_main(int argc, char *argv[]);
int main(int argc, char *argv[]) {
    SDL_SetMainReady();
    return SDL_main(argc, argv);
}
