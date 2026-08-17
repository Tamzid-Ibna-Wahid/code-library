for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > input.txt
    diff -w <(./a < input.txt) <(./brute < input.txt) || break
done