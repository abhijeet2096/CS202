/**************************
*Name: Abhijeet sharma
*Date: 20/03/2017
*Roll No. B15102
*********************/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "stack.hpp"

std::string itoa(int ans){
	std:string a = "";

	while(ans){
		a = (char)(ans%10 + 48) + a;
		ans /= 10;
	}

	std::cout<<"a :"<<a<<std::endl;
	return a;

}

int atoi(const char* string){
02
	int len = strlen(string);
	int ans = 0;
	for(int i = 0; i < len; i++)
		ans = ans * 10 + (string[i] - 48);

	std::cout<<"ans :"<<ans<<std::endl;
	return ans;
}

int main(){

	std::string in, t;
	stack <std::string> A,B;

	int a, b, ans;
	while(1){
		std::cin >> in;

		if(in[0] == 'q'){
			if(A.size() == 3){
				b = atoi((A.pop()).c_str());
				a = atoi((A.pop()).c_str());
				t = A.pop();

				if(t[0] >= '0' && t[0] <= '9'){
					std::cout<<"Wrong format"<<std::endl;
					exit(EXIT_SUCCESS);
				}
				
				std::cout<<"opertor : "<<t<<std::endl;

				switch(t[0]){
				case '+' : ans = a + b;
								A.push(itoa(ans));
								break;

					case '-' : ans = a - b;
								A.push(itoa(ans));
								break;

					case '*' : ans = a * b;
								A.push(itoa(ans));
								break;

					case '/' : ans = a / b;
								A.push(itoa(ans));
								break;	
				}
			}
			
			if(A.size() != 1){
				std::cout<<"Invalid Format"<<std::endl;
				exit(EXIT_SUCCESS);
			}

			break;
		}

		if(in != ")")
			A.push(in.c_str());
		else{
			b = atoi((A.pop()).c_str());
			a = atoi((A.pop()).c_str());
			t = A.pop();

			if(t[0] >= '0' && t[0] <= '9'){
					std::cout<<"Wrong format"<<std::endl;
					exit(EXIT_SUCCESS);
				}
			std::cout<<"opertor : "<<t<<std::endl;
			A.pop();

			switch(t[0]){
				case '+' : ans = a + b;
								A.push(itoa(ans));
								break;

					case '-' : ans = a - b;
								A.push(itoa(ans));
								break;

					case '*' : ans = a * b;
								A.push(itoa(ans));
								break;

					case '/' : ans = a / b;
								A.push(itoa(ans));
								break;
			}
		}
	}

	A.display();

	return 0;
}