emcc dependent.cc \
-s WASM=1 \
-s 'EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"]' \
--post-js post-script.js \
-o dependent.js
