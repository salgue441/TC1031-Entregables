for i in 1 2 3 4
do  
    g++ -std=c++2a main.cpp -o app
    ./app input$i.txt mysolution$i.txt
    diff output$i.txt mysolution$i.txt
done