emcc operateNum.cxx \
-o operateNum.js \
-s WASM=1 \
-s EXPORTED_FUNCTIONS='["_addOne"]' \
-s EXPORTED_RUNTIME_METHODS='["cwrap", "getValue", "setValue", "malloc", "free"]'