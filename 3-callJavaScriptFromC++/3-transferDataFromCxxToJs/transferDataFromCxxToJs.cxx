#include <time.h>   // for time
#include <stdlib.h> // for rand
#include <stdio.h>
#include <emscripten.h>

// 在C++调用JS时，从C++向JS传递数据
extern "C"
{
    int main()
    {
        printf("WASM is running!\n");

        srand(time(NULL));          // initialize random seed
        int color_idx = rand() % 3; // could be 0, 1 or 2

        EM_ASM(
            // here you can write inline javascript code!
            console.log("(1) I have been printed from inline JavaScript!");
            console.log("I have no parameters and I do not return anything :(");
            // end of javascript code
        );

        // note the underscore and the curly brackets (to pass one or more parameters)
        EM_ASM_({
            console.log("(2) I have received a parameter! It is:", $0);
            console.log("Setting the background to that color index!");
            set_background_color($0);
        },
                color_idx);

        // note that you have to specify the return type after EM_ASM_
        int result = EM_ASM_INT({
            console.log("(3) I received two parameters! They are:", $0, $1);
            console.log("Let's return their sum!");
            return sum($0, $1);

            function sum(a, b)
            {
                return a + b;
            }
        },
                                13, 10);

        printf("(4) The C code received %d as result!\n", result);

        return 0;
    }
}
