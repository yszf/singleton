#ifndef __SINGLETON_H__2020_12_12
#define __SINGLETON_H__2020_12_12
#include <pthread.h>

#define barrier() __asm__ __volatile__("" ::: "memory")

template<typename T>
class Singleton {
public:
	volatile static Singleton* GetInstance() {
		if (nullptr == instance_) {
			pthread_mutex_lock(&mutex_);
			if (nullptr == instance_) {
				Singleton* temp = new Singleton;
				barrier();
				instance_ = temp;
			}
			pthread_mutex_unlock(&mutex_);
		}
		return instance_;
	}
private:
	Singleton() {}
	Singleton(const Singleton&){};
	volatile static Singleton<T>* instance_;
	static pthread_mutex_t mutex_;
};

template<typename T>
volatile Singleton<T>* Singleton<T>::instance_ = nullptr;

template<typename T>
pthread_mutex_t Singleton<T>::mutex_ = PTHREAD_MUTEX_INITIALIZER;

#endif // singleton