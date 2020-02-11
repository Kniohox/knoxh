.PHONY=all run clean

#custom parameters
EXECUTABLE:=knoxh
EXTENSION:=.exe
BUILD_DIR:=build

FLAGS:=-Werror -std=c++17

INCLUDE_FOLDERS:=-Iinclude -Isrc
LIB_FOLDER:=-Llib
LIB:=-lglfw3 -lopengl32 -lgdi32

DEPENDENCIES:=template.o window.o util.o
HEADERS:=window.h util.h

VPATH=build:src:src/core

all:
	@echo "build, run, clean"

build: ${DEPENDENCIES} ${HEADERS}
	g++ $(addprefix ${BUILD_DIR}/,${DEPENDENCIES}) ${LIB_FOLDER} ${LIB} -o ${BUILD_DIR}/${EXECUTABLE}${EXTENSION} ${FLAGS}

%.o: %.cpp
	$(foreach file,$?, g++ -c ${file} -o ${BUILD_DIR}/$@ ${FLAGS} ${INCLUDE_FOLDERS})

run:
	-@${BUILD_DIR}/${EXECUTABLE}${EXTENSION}
	@echo --Ignore the error, it only happens when running the executable using make run--

clean:
	DEL /Q ${BUILD_DIR}\\*.*
