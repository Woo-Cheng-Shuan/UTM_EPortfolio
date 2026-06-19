echo “Hello world” > helloworld.jar
mkdir cars; mkdir dates; mkdir fruits drinks
cd cars; echo “Honda Accord” > accord.c
cp accord.c civic.c; echo proton > proton.c; cd ../dates; 
date > dateoftheday
cat dateoftheday > appointment
cd ../fruits; echo apple > apple.txt; cat apple.txt > orange.txt
cd drinks; cp ../cars/*.* .; cp ../fruits/*.* .; 
cp ../*.jar .