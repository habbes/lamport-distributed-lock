rm result.csv

make clean

make

./node 4 0 10 &
./node 4 1 10 &
./node 4 2 10 &
./node 4 3 10 &
./node 4 4 10 &

