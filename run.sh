if [ ! -d "build" ]; then
  mkdir build
fi
cd build
echo "cmake start:"
cmake ..
echo "make start:"
make
cd ..
echo "========================================"
echo "run web server:"
# ./testResponse
./web