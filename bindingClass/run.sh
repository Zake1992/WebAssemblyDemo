emcc --bind -Oz myClass.cxx -o myClass.js \
-s WASM=1 -s NO_EXIT_RUNTIME=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']" \
|| exit 1