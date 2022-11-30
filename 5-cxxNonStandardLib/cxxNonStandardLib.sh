# 增加了第三方依赖
# 如果需要使用tinyexpr.c中的函数，包括在cxxNonStandardLib.cxx的main()函数中使用，需要将tinyexpr.c加入到下面语句中。
emcc cxxNonStandardLib.cxx tinyexpr.c  \
-o cxxNonStandardLib.js \
-s WASM=1 