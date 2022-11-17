g++ -std=c++2a main.cpp -o app

for i in 0 1 2 3 4 
do
    ./app input$i.txt out$i.txt
    diff out$i.txt output$i.txt
done