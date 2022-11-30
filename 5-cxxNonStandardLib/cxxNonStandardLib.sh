# 增加了第三方依赖
emcc cxxNonStandardLib.cxx tinyexpr.c  \
-o cxxNonStandardLib.js \
-s WASM=1 