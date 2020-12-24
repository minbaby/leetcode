test:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runtest --verbose -j4 -f
main:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runmain
clean:
	rm -rf build