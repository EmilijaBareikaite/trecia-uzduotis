cmake -G Xcode .
cmake --install .
cmake --build .
cp src/studentai1000.txt Debug/studentai1000.txt
cp src/studentai10000.txt Debug/studentai10000.txt
cp src/studentai100000.txt Debug/studentai100000.txt
cp src/studentai1000000.txt Debug/studentai1000000.txt
cp src/studentai10000000.txt Debug/studentai10000000.txt
cd Debug
./antra_uzd
 
