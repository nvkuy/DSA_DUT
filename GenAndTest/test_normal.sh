set -e
g++ gen.cpp -o gen
g++ bf.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > inp
    ./brute < inp > out
    echo "Stress test: "  $i
done