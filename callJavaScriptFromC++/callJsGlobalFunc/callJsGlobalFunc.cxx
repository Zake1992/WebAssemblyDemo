#include <stdio.h>
#include <emscripten.h>

extern "C"
{
    int main()
    {
        printf("WASM is running!");
        emscripten_run_script("set_background_color(1)");
        return 0;
    }
}
