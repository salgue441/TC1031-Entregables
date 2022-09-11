g++ -std=c++2a main.cpp -o app
mkdir my_outputs

for i in 1 2 3 4 
do
	./app input$i.txt ./my_outputs/solution$i.txt
	diff output$i.txt ./my_outputs/solution$i.txt
done
