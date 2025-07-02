src=$(wildcard src/*.cpp)

hserver:
	g++ -std=c++11 -pthread -g \
	ThreadPool.cpp \
	http_test3.cpp \
	-o hserver

clean:
	rm hserver