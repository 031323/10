yt.wasm:3.cpp
	emcc 3.cpp -o yt.js -s USE_SDL=2 -s WASM=1 -O3 -s EXPORTED_RUNTIME_METHODS=["ccall"]