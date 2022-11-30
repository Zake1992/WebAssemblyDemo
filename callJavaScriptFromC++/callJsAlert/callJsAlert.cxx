#include <stdio.h>
#include <emscripten.h>

extern "C"
{
    int main()
    {
        printf("WASM is running!");
        emscripten_run_script("alert('I have been called from C!')");
        return 0;
    }
}
