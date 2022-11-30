emcc ccall.cc \
--std=c++11 \
-o ccall.html \
-s WASM=1 \
-s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "getValue"]' \
--post-js post-script.js


