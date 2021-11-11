rm -rf build
mkdir build
cd build
CC=cc
CXX=CC
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/.local -DCMAKE_C_COMPILER=$CC -DCMAKE_CXX_COMPILER=$CXX -DCMAKE_BUILD_TYPE=DEBUG 
make -j install

#export CPATH=$HOME/.local/include:$CPATH
#export LIBRARY_PATH=$HOME/.local/lib:$HOME/.local/lib64:$LIBRARY_PATH

