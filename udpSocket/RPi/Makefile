all:
	g++ -Wall main.cpp SocketUDP.cpp SyrupMeasure.cpp MsgHandler.cpp -o main
pi:
	arm-rpizw-g++ -Wall main.cpp SocketUDP.cpp SyrupMeasure.cpp -o main
	scp main root@10.9.8.2:

clean:
	rm main