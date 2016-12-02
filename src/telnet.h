#ifndef TELNET_H
#define TELNET_H
#include <string>
#include <pthread.h>
using namespace std;

class Telnet
{
    int socketDescriptor;
    pthread_mutex_t writeMutex;
    void respond(unsigned char command, unsigned char option);
    void sendGA();
public:
    Telnet(int socket);
    // 'socket' must be open connection descriptor
    void readLine(string* line);
    // Read exactly one line and save it to argument string.
    // Resulting string ends with "\r\n".
    // Throws SocketError on error or SocketClosedError when read() returns 0.
    void writeLine(string* line);
    // Add new line sequence "\r\n" to string and write it to Telnet connection.
    // Throws SocketError or SocketClosedError.
};


#endif
