.PHONY=all run clean install

#custom parameters
EXECUTABLE:=knoxh
EXTENSION:=.exe
BUILD_DIR:=build

#compilation flags
FLAGS:=-Werror -std=c++17

#include folders
INCLUDE_FOLDERS:=-Iinclude -Isrc
#lib folder
LIB_FOLDER:=-Llib
#libs to require
LIB:=-lglew32 -lglfw3 -lopengl32 -lgdi32

#cpp files to be compiled
DEPENDENCIES:=test.o window.o funclib.o engine.o registry.o queue.o texture.o
#headers to be added as dependencies so changes to them cause the build to become outdated
HEADERS:=window.h funclib.h engine.h registry.h queue.h texture.h

#each folder containing files needs to be here
VPATH=build:src:src/knoxh/core:src/knoxh/util:src/knoxh/graphics

#lists available options
all:
	@echo build, run, clean

#assimilating binary files and linking libraries
build: ${DEPENDENCIES} ${HEADERS}
	g++ $(addprefix ${BUILD_DIR}/,${DEPENDENCIES}) ${LIB_FOLDER} ${LIB} -o ${BUILD_DIR}/${EXECUTABLE}${EXTENSION} ${FLAGS}

#compile cpp source files to binary
%.o: %.cpp
	$(foreach file,$?, g++ -c ${file} -o ${BUILD_DIR}/$@ ${FLAGS} ${INCLUDE_FOLDERS})

#install output to computer
install:
	@echo Not yet implemented

#running output file, for some reason a make error is always thrown even if there is no problem with the executable
run:
	@echo.
	@cd ${BUILD_DIR} && ${EXECUTABLE}${EXTENSION}

#deletes all files in build directory
clean:
	DEL /Q ${BUILD_DIR}\\*.*
