BIN_FILE = bin/project1
OBJ_FILES = obj/project1.o
TEST_BIN_FILE = bin/testProject1
TEST_OBJ_FILES = obj/testProject1.o
LIBRARY = lib/libcs240utils.a
LIBRARY_OBJ_FILES = utils/obj/StringUtil.o utils/obj/URLInputStream.o utils/obj/FileInputStream.o \
					utils/obj/HTTPInputStream.o utils/obj/CommandRunner.o utils/obj/FileSystem.o \
					utils/obj/HTMLToken.o utils/obj/HTMLTokenizer.o

#Create Project 1 executable
bin: $(BIN_FILE)

#Create Project 1 test executable and run
test: $(TEST_BIN_FILE)
	$(TEST_BIN_FILE) &

#Create CS240 Library
lib: $(LIBRARY)

#remove all library, object files, and executables
clean:
	-rm -f lib/*
	-rm -f obj/*
	-rm -f bin/*
	-rm -f utils/obj/*

#Create test executable
$(TEST_BIN_FILE): $(TEST_OBJ_FILES) $(LIBRARY)
	g++ -o $(TEST_BIN_FILE) $(TEST_OBJ_FILES) $(LIBRARY)
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
	g++ -c -Wall -o obj/project1.o -I inc/ -I utils/include/ src/project1.cpp




################################################
#Project 1 Test Object Files

obj/testProject1.o: src/testProject1.cpp $(LIBRARY)
	g++ -c -Wall -o obj/testProject1.o -I inc/ -I utils/include/ src/testProject1.cpp




################################################
#CS240 Library Object Files

utils/obj/StringUtil.o: utils/inc/StringUtil.h utils/src/StringUtil.cpp
	g++ -c -Wall -o utils/obj/StringUtil.o -I utils/inc/ utils/src/StringUtil.cpp
	

utils/obj/URLInputStream.o: utils/inc/URLInputStream.h utils/src/URLInputStream.cpp
	g++ -c -Wall -o utils/obj/URLInputStream.o -I utils/inc/ utils/src/URLInputStream.cpp

utils/obj/FileInputStream.o: utils/inc/FileInputStream.h utils/src/FileInputStream.cpp
	g++ -c -Wall -o utils/obj/FileInputStream.o -I utils/inc/ utils/src/FileInputStream.cpp

utils/obj/HTTPInputStream.o: utils/inc/HTTPInputStream.h utils/src/HTTPInputStream.cpp
	g++ -c -Wall -o utils/obj/HTTPInputStream.o -I utils/inc/ utils/src/HTTPInputStream.cpp

utils/obj/CommandRunner.o: utils/inc/CommandRunner.h utils/src/CommandRunner.cpp
	g++ -c -Wall -o utils/obj/CommandRunner.o -I utils/inc/ utils/src/CommandRunner.cpp

utils/obj/FileSystem.o: utils/inc/FileSystem.h utils/src/FileSystem.cpp
	g++ -c -Wall -o utils/obj/FileSystem.o -I utils/inc/ utils/src/FileSystem.cpp

utils/obj/HTMLToken.o: utils/inc/HTMLToken.h utils/src/HTMLToken.cpp
	g++ -c -Wall -o utils/obj/HTMLToken.o -I utils/inc/ utils/src/HTMLToken.cpp

utils/obj/HTMLTokenizer.o: utils/inc/HTMLTokenizer.h utils/src/HTMLTokenizer.cpp
	g++ -c -Wall -o utils/obj/HTMLTokenizer.o -I utils/inc/ utils/src/HTMLTokenizer.cpp


