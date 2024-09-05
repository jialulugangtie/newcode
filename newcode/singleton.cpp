#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>


class Singleton1 {
public:
	

private:
	Singleton1() {}
	~Singleton1() {
		std::cout << "~Singleton1()\n";
	}

	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;
	Singleton1(Singleton1&&) = delete;
	Singleton1& operator=(Singleton1&&) = delete;


	static Singleton1* instance;
};

Singleton1* Singleton1::instance = nullptr;



class Singleton3 {
public:
	static Singleton3* GetInstance() {
		std::lock_guard<std::mutex> lock(_mutex);
		if (_instance == nullptr) {
			_instance = new Singleton3();
			atexit(Destructor);
		}
	}

private:
	static void Destructor() {
		if (_instance != nullptr) {
			delete _instance;
			_instance = nullptr;
		}
	}


	static Singleton3* _instance;
	static std::mutex _mutex;
};




class Singleton4 {
public:
	static Singleton4* GetInstance() {
		Singleton4* temp = _instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);
		if (!temp) {
			std::lock_guard<std::mutex> lock(_mutex);
			temp = _instance.load(std::memory_order_relaxed);
			if (!temp) {
				temp = new Singleton4;
				std::atomic_thread_fence(std::memory_order_release);
				_instance.store(temp, std::memory_order_relaxed);
				atexit(Destructor);
			}
		}
	}

private:
	static void Destructor() {
		Singleton4* temp = _instance.load(std::memory_order_relaxed);
		if (!temp) {
			delete temp;
		}
	}

	Singleton4() {}
	~Singleton4() {
		std::cout << "~Singleton4()\n";
	}

	Singleton4(const Singleton4&) = delete;
	Singleton4(Singleton4&&) = delete;
	Singleton4& operator=(const Singleton4&) = delete;
	Singleton4& operator=(Singleton4&&) = delete;

	static std::atomic<Singleton4*> _instance;
	static std::mutex _mutex;
};


class Singleton5 {
public:
	static Singleton5* GetInstance() {
		static Singleton5 instance; //c++11 局部静态变量有线程安全的特性
		return &instance; 
	}

private:
	Singleton5() {
		std::cout << "Singleton5()\n";
	}
	~Singleton5() {
		std::cout << "~Singleton5()\n";
	}
	Singleton5(const Singleton5&) = delete;
	Singleton5& operator=(const Singleton5) = delete;
	Singleton5(Singleton5&&) = delete;
	Singleton5 operator=(Singleton5&&) = delete;
};

int main() {

	{
		auto temp = Singleton5::GetInstance();
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));

	return 0;
}