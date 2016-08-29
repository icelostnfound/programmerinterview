#include <thread>
#include<iostream>
#include <chrono>
struct PrintNum {
	void operator()(int i) const
	{
		std::cout << i << '\n';
	}
};
void f1(int n)
{
	for (int i = 0; i < 5;++i)
	{
		std::cout << "Thread 1 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void f2(int&n)
{
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Thread 2 executing\n";
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
int main()
{
	
	std::cout<<"Hello waiter"<<std::endl;
	//C++11定时方法
	auto start=std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Waited " << elapsed.count() << " ms\n";
	int n = 0; 
	std::thread t1;
	std::thread t2(f1, n + 1);
	std::thread t3(f2,std::ref(n));
	std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
	t2.join();
	t4.join();
	std::cout << "Final value of n is " << n << '\n';
	system("pause");
	return 0;
}