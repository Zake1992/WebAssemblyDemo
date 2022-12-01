# 命令里面的，-s SIDE_MODULE=2，这个标记的作用是告诉Emscripten不用在生成的模块中包含像C标准库这样的内容，
# 也不用生成任何其他的文件。-O1（大写字母O）是优化标记，如果不添加优化标记，默认不优化，在这个环节，如果不进行优化，
# 就会在试图加载WebAssembly模块时产生链接错误，这个模块的代码中需要若干函数和全局变量，
# 但是我并没有提供，通过移除多余导入可以解决这个问题，所以使用了优化。
# 在Emscripten中，优化等级从下到上分别为：-O0、-O1、-O2、-Os、-Oz、-O3。
# 此外，还需要将函数add指定为导出函数，这样才能够被JavaScript调用，否则在编译过程函数名会发生变化。
# 为了实现这一要求，需要添加-s EXPORTED_FUNCTION[ ]，然后包含函数名。
# 最后，输出文件的后缀应为.wasm。如果不指定文件名，Emscripten会创建一个名为a.out.wasm的文件。

emcc add.cxx \
-s SIDE_MODULE=2 \
-O1 \
-s EXPORTED_FUNCTIONS='["_add"]' \
-o add.wasm
