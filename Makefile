compiler.build:
	cmake -S./msl-compiler -B./msl-compiler/bin -G "MinGW Makefiles" -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++
	make -C./msl-compiler/bin

clean:
	rmdir /s /q "msl-compiler/bin"
