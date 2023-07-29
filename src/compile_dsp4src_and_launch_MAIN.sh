#! /bin/bash 

# THIS SCRIPT HAS TO BE PLACED IN THE TOP LAYER OF dsp4sdr/src

BUILD_DIR=../build
EXECUTABLE=main
INCLUDE_DIR="../includes//"

SRC="./*.cpp ./*/*.cpp ../utils/*.cpp"
COMPILER=g++
LINKER_FLAG="-lhackrf"

COMPILE_STRING="$SRC -I $INCLUDE_DIR $LINKER_FLAG -o $BUILD_DIR/$EXECUTABLE"


#CREATE BUILD DIRECTORY IF NOT EXIST
if [[ ! -d "$BUILD_DIR" ]]; then =
    echo "missing build directory..."
    echo "creating build directory"
    mkdir $BUILD_DIR
fi

# REMOVE OLD EXECUTABLE
if [[ -e "$BUILD_DIR/$EXECUTABLE" ]]; then
    echo "removing old executable..."
    rm $BUILD_DIR/$EXECUTABLE
fi

# COMPILE AND LAUNCH
$COMPILER $COMPILE_STRING && ./$BUILD_DIR/$EXECUTABLE

