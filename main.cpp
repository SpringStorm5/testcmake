#include <iostream>
#include <string>
#include <vector>
#include <thread>
void foo()
{
 using namespace std::chrono_literals;
 auto start = std::chrono::high_resolution_clock::now();
 std::this_thread::sleep_for(10s);

 auto end = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double, std::milli> elapsed = end-start;
 std::cout << "Waited " << elapsed.count() << " ms\n";
}
int main()
{
 using Threads = std::vector<std::thread>;
 Threads threads;
 const auto thread_count = std::thread::hardware_concurrency();
 for (int i = 0; i < thread_count; ++i)
 threads.emplace_back(std::thread(foo));
 for (auto& t:threads)
 t.join();
 return 0;
}
