if [ ! -d "build" ]; then
  mkdir build
fi
cd build
echo "cmake start:"
cmake ..
echo "make start:"
make
cd ..
# echo "========================================"
# echo "config hexo:"
# cd hexo
# hexo clean
# hexo g
# cd ..
# cp ./static/images/favicon-32x32.png ./static/favicon.ico
echo "========================================"
echo "run web server:"
./web