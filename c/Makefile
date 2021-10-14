test:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runtest --verbose -j8 -f
main:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runmain
clean:
	rm -rf build