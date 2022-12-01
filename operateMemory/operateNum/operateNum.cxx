// add one to the value in the input ptr and write this to the content of the output ptr
extern "C"
{
    void addOne(int *input_ptr, int *output_ptr)
    {
        *output_ptr = (*input_ptr) + 1;
    }
}
