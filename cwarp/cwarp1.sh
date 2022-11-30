# 暴露Cxx文件中的特定方法
emcc fib.cxx  \
-o fib.js \
-s WASM=1 \
-s EXPORTED_FUNCTIONS='["_fib", "_main"]' \
-s EXPORTED_RUNTIME_METHODS='["cwrap"]'