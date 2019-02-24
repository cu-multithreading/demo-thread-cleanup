#include<iostream>
#include<vector>
#include<thread>

using std::cout;
using std::endl;

void countTo1Million()
{
	for(int i = 0; i < 1000000; i++) {}
}

int main(int argc, char * argv[])
{
	std::vector<std::thread> threads;

	for(int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread{countTo1Million});
	}


	//Run with '-forgetful' to skip thread cleanup (will cause error)
	if( argc < 2 || argv[1] != "-forgetful")
	{
		//Join all threads
		for(auto & iter : threads)
		{
			iter.join();
		}
	}

	std::cin.get();

	return 0;
}