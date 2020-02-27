.PHONY=all run clean install

#custom parameters
EXECUTABLE:=knoxh
EXTENSION:=.exe
BUILD_DIR:=build

#compilation flags
FLAGS:=-Werror -std=c++17
#c++ preprocessor
#use DEBUG for additional output, RELEASE for standard output
CPPPRE:=-D DEBUG

#include folders
INCLUDE_FOLDERS:=-Iinclude -Isrc
#lib folder
LIB_FOLDER:=-Llib
#libs to require
LIB:=-lglew -lglfw3 -lopengl32 -lgdi32

#core engine
C_ENGINE_B:=window.o funclib.o engine.o registry.o queue.o texture.o voidregistry.o shader.o legacymesh.o
C_ENGINE_H:=window.h funclib.h engine.h registry.h queue.h texture.h voidregistry.h shader.h legacymesh.h

#test project
C_GAME_B:=test.o basicshader.o
C_GAME_H:=basicshader.h

#cpp files to be compiled
DEPENDENCIES:=${C_ENGINE_B} ${C_GAME_B}
#headers to be added as dependencies so changes to them cause the build to become outdated
HEADERS:=${C_ENGINE_H} ${C_GAME_H}

#each folder containing files needs to be here
VPATH=build:src:src/knoxh/core:src/knoxh/util:src/knoxh/graphics

#lists available options
all:
	@echo build, run, clean

#assimilating binary files and linking libraries
build: ${DEPENDENCIES} ${HEADERS}
	g++ $(addprefix ${BUILD_DIR}/,${DEPENDENCIES}) ${LIB_FOLDER} ${LIB} -o ${EXECUTABLE}${EXTENSION} ${FLAGS}
#g++ $(addprefix ${BUILD_DIR}/,${DEPENDENCIES}) ${LIB_FOLDER} ${LIB} -o ${BUILD_DIR}/${EXECUTABLE}${EXTENSION} ${FLAGS}

#install output to computer
install:
	@echo Not yet implemented

#running output file, for some reason a make error is always thrown even if there is no problem with the executable
run:
	@echo.
	@${EXECUTABLE}${EXTENSION}
#@cd ${BUILD_DIR} && ${EXECUTABLE}${EXTENSION}

#deletes all files in build directory
clean:
	DEL /Q ${BUILD_DIR}\\*.*
	DEL /Q ${EXECUTABLE}${EXTENSION}

#compile cpp source files to binary
%.o: %.cpp
		$(foreach file,$?, g++ -c ${file} -o ${BUILD_DIR}/$@ ${FLAGS} ${CPPPRE} ${INCLUDE_FOLDERS})
