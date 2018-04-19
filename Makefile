fight: barbarian.cpp vampire.cpp medusa.cpp bluemen.cpp harrypotter.cpp validate.cpp queuenode.cpp main.cpp
	g++ -std=c++11 barbarian.cpp vampire.cpp medusa.cpp bluemen.cpp harrypotter.cpp validate.cpp queuenode.cpp main.cpp -o fight

clean:
	rm fight
