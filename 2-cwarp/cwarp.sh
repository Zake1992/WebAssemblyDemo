# 暴露Cxx文件中的所有方法
emcc fib.cxx  \
-o fib.js \
-s WASM=1 \
-s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]'