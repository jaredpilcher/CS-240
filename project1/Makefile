BIN_FILE = bin/project1
OBJ_FILES = obj/project1.o
TEST_BIN_FILE = bin/testProject1
TEST_OBJ_FILES = testProject1.o
LIBRARY = lib/libcs240utils.a
LIBRARY_OBJ_FILES = utils/obj/StringUtil.o utils/obj/URLInputStream.o utils/obj/FileInputStream.o \
					utils/obj/HTTPInputStream.o utils/obj/CommandRunner.o utils/obj/FileSystem.o \
					utils/obj/HTMLToken.o utils/obj/HTMLTokenizer.o

#Create Project 1 executable
bin: $(BIN_FILE)

#Create Project 1 test executable and run
test: $(TEST_BIN_FILE)
	$(BIN_FILE) &

#Create CS240 Library
lib: $(LIBRARY)

#remove all library, object files, and executables
clean:
	rm -f lib/*
	rm -f obj/*
	rm -f bin/*

#Create test executable
$(TEST_BIN_FILE): $(TEST_OBJ_FILES) $(LIBRARY)
	g++ -o $(TEST_BIN_FILE) $(TEST_OBJ_FILES)
	chmod ugo+x $(TEST_BIN_FILE)
	
#Create test executable
$(BIN_FILE): $(OBJ_FILES) $(LIBRARY)
	g++ -o $(BIN_FILE) $(OBJ_FILES)	$(LIBRARY)
	chmod ugo+x $(BIN_FILE)

#Create CS240 library
$(LIBRARY): $(LIBRARY_OBJ_FILES)
	ar r $(LIBRARY) $(LIBRARY_OBJ_FILES)


################################################
#Poject 1 Object Files

obj/project1.o: src/project1.cpp $(LIBRARY_OBJ_FILES)
	g++ -c -o ../obj/project1.o -I inc/ -I utils/include/ project1.cpp




################################################
#Project 1 Test Object Files

obj/testProject1.o: src/testProject1.cpp




################################################
#CS240 Library Object Files

utils/obj/StringUtil.o:

utils/obj/URLInputStream.o:

utils/obj/FileInputStream.o:

utils/obj/HTTPInputStream.o:

utils/obj/CommandRunner.o:

utils/obj/FileSystem.o:

utils/obj/HTMLToken.o:

utils/obj/HTMLTokenizer.o:


