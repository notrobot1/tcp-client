#include <winsock2.h>
#include <iostream>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    std::cout << "Hello World!" << std::endl;
     if(WSAStartup(DLLVersion, &wsaData) != 0){
        std::cout <<"errror" <<std::endl;
        exit(1);
     }
     SOCKADDR_IN addr;
     int sizeofaddr = sizeof(addr);
     addr.sin_addr.s_addr = inet_addr( "192.168.0.106");
     addr.sin_port = htons(4444);
     addr.sin_family = AF_INET;


     SOCKET Connection = socket(AF_INET, SOCK_STREAM, 0);

     if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
         std::cout << "Error: failed connect to server.\n";
         return 1;
     }
     std::cout << "Connected!\n";
     char msg[256];
     char m[256] = "tilox";
     send(Connection, m, sizeof(m), 0);

     while (1) {

         ssize_t count = recv(Connection, msg, sizeof(msg), 0);

         if (count==0) {
                break;
         } else if (count < 0) {
             std::cerr << "recv() failed" << std::endl;
             exit(EXIT_FAILURE);
             }
             msg[count] = 0;
             std::cout << msg << std::endl;
         //std::cout << recv(Connection, msg, sizeof(msg)-1, 0) << std::endl;
     }
     //std::cout << "Hello World!" << std::endl;
    return 0;
}
