#include "singleton.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
//	volatile Singleton<int>* instance = Singleton<int>::GetInstance();
	shared_ptr<volatile Singleton<int>> instance(Singleton<int>::GetInstance());
	
	return 0;
}