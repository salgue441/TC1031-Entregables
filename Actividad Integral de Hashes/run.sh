for i in 1 2 3 4
do
    ./app input$i.txt out$i.txt
    diff output$i.txt out$i.txt
done