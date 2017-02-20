######################################################

#Created By:
#Abhijeet sharma	
#B15102
#IIT Mandi

######################################################

inc =  -lm 

all:  main.o
	g++ -w -o my_exe  main.o -Wno-deprecated -I ${inc} 

main.o: main.cpp
	g++ -c main.cpp -Wno-deprecated -I ${inc}

clean:
	rm -f *.o
