bin: lib/library.a
	@echo "hello make"

test: lib/library.a
	@echo "hello make test"

lib: 
	ar r lib/libcs240utils.a utils/obj/*.o

clean:
	rm -f lib/*
	rm -f obj/*
	rm -f bin/*
