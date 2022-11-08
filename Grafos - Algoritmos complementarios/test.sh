for i in 1 2 3 4 
    do
        g++ -std=c++20 test$i.cpp -o runTest$i
        ./runTest$i
    done