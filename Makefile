yt.wasm:3.cpp nc.xbm
	emcc 3.cpp -o yt.js -s EXPORTED_RUNTIME_METHODS=ccall -s USE_SDL=2 -s WASM=1 -O3
