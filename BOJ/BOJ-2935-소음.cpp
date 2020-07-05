#include<iostream>

int main () {
	std::string A, B;
	char ope;
	std::cin >> A >> ope >> B;
	if(ope == '*'){
		std::cout << 1;
		for(int i = 0; i < A.size() + B.size() - 2; ++i)
			std::cout << 0;
	}
	else if(ope == '+' && A.size() > B.size()){
		for(int i = 0; i < A.size() - B.size(); ++i)
			std::cout << A[i];
		for(int i = 0; i < B.size(); ++i)
			std::cout << B[i];		
	}
	else if(ope == '+' && A.size() < B.size()){
		for(int i = 0; i < B.size() - A.size(); ++i)
			std::cout << B[i];
		for(int i = 0; i < A.size(); ++i)
			std::cout << A[i];
	}
	else{
		std::cout << 2;
		for(int i = 0; i < A.size() - 1; ++i)
			std::cout << 0;
	}
	return 0;
}
