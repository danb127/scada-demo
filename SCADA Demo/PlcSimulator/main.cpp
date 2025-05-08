#include <winsock2.h> // the windows socket
#include <windows.h> // the windows header for the sleep function
#include <iostream> // the standard input output header
#include <cstdlib> // the standard library header for the rand function
#pragma comment(lib, "ws2_32.lib") // link the ws2_32.lib library for the windows socket

int main(){
    // Initialize the windows socket API
    WSADATA wsa;

    // if Winsock 2.2 is not available, return an error
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0){ 
        std::cerr << "Failed to initialize Winsock. Error code: " << WSAGetLastError() << std::endl;
        return 1;
    }

    // Create a UDP socket for the server (AF_INET = IPv4, SOCK_DGRAM = UDP, IPPROTO_UDP = UDP protocol)
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET){
        std::cerr << "Failed to create socket. Error code: " << WSAGetLastError() << std::endl;
        WSACleanup(); // cleanup the Winsock API
        return 1;
    } 

    // Configure destination (localhost: 5500)
    sockaddr_in dest{}; 
    dest.sin_family = AF_INET; // socket interney family INET
    dest.sin_port = htons(5500) // host to network short (port number)
    dest.sin_addr.s_addr = inet_addr("127.0.0.1"); // socket internet address (localhost address) 

    // Publish sensor values every 500 ms
    std::cout << "Publishing sensor values...\n";
    while(true){
        int sensorValue = rand() % 100; // generate a random sensor value between 0 and 99

        sendto(
            sock, // socket
            reinterpret_cast<const char*>(&sensorValue), // data we are sending (cast to char* because sendto expects a character pointer)
            sizeof(sensorValue), // size of the data we are sending
            0, // flags (0 means no flags)
            reinterpret_cast<sockaddr*>(&dest), // destination address (cast to sockaddr* because sendto expects an address pointer)
            sizeof(dest) // size of the destination address
        );
        Sleep(500); // sleep for 500 milliseconds (0.5 seconds) before sending the next value  
    }

    // Close the socket and cleanup the Winsock API (this code will never be reached because of the infinite loop above)
    closesocket(sock); // close the socket
    WSACleanup(); // cleanup the Winsock API
    return 0; // return 0 to indicate success

}