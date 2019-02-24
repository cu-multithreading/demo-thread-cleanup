#include<iostream>
#include<vector>
#include<thread>
#include<string>

using std::cout;
using std::endl;

using std::string;

void countTo1Million(int threadNo)
{
	for(int i = 0; i < 1000000 * threadNo; i++) {}

	cout << "Thread " << threadNo << " finished." << endl;
}

int main(int argc, char * argv[])
{
	std::vector<std::thread> threads;

	for(int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread{countTo1Million, i});
	}

	//Run with '-forgetful' to skip thread cleanup (will cause error)
	if( argc == 1 || string(argv[1]) != "-forgetful")
	{
		cout << "Joining threads" << endl;

		//Join all threads
		for(int i = 0; i < threads.size(); i++)
		{
			threads[i].join();
			cout << "Thread " << i << " joined." << endl;
		}
	}	

	return 0;
}
