######################################################

#Created By:
#Abhijeet sharma	
#B15102
#IIT Mandi

######################################################

inc =  -lm 

all:  driver_sorter.o
	g++ -w -o my_exe  driver_sorter.o -Wno-deprecated -I ${inc} 

main.o: driver_sorter.cpp
	g++ -c driver_sorter.cpp -Wno-deprecated -I ${inc}

clean:
	rm -f *.o
