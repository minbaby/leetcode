test:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runtest -j8 -f
one:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runtest --filter 't_148_sortList/*' -f
main:
	cmake -Bbuild -GNinja && ninja -C build && ./build/runmain
clean:
	rm -rf build