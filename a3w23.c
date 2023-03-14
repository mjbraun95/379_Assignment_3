#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 3
#define BUF_SIZE 256

// TODO: Check these are the same in assignment description
#define BUFSIZE 80
#define MAXCMD 10
#define MAXPATH 50
#define MAXWORD 32
#define MAX_PACKET_TYPE_LEN 6
#define NCLIENT 3
#define NUM_PACKET_TYPES 7

// Define structs
typedef enum { PUT, GET, DELETE, GTIME, TIME, OK, ERROR } Packet_Type;
typedef struct { char message[MAXWORD]; } Message;
typedef struct { Packet_Type packet_type; Message message; } Packet;

char* process_message(Message received_message) {
   char* file_name = malloc(sizeof(char) * MAXWORD);
   strcpy(file_name, received_message.message);
   return file_name;
}

//Modified code from fifoMsg.c on eClass
void send_packet (int fd, Packet_Type packet_type, Message *message)
{
    Packet  packet;
    assert (fd >= 0);
    memset( (char *) &packet, 0, sizeof(packet) );
    packet.packet_type= packet_type;
    packet.message=  *message;
    write (fd, (char *) &packet, sizeof(packet));
}

//Modified code from fifoMsg.c on eClass
Packet receive_packet (int fd)
{
    int    len; 
    Packet  packet;
    assert (fd >= 0);
    memset( (char *) &packet, 0, sizeof(packet) );
    len= read (fd, (char *) &packet, sizeof(packet));
    if (len != sizeof(packet))
        printf("Warning: Received packet has length= %d (expected= %d)\n", len, sizeof(packet));
    return packet;		  
}

void launch_client() {
    // TODO: Call socket
}

void launch_server(int portnumber) {
    // TODO: Create socket
    // TODO: Initialize socket
    //Source: https://stackoverflow.com/questions/18886470/socket-programming-in-linux-by-c
    int server_fd;
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(portnumber);

    if ((server_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 10) == -1) {
        perror("listen");
        return 1;
    }
    // TODO: Bind host address
    // TODO: Start listening for up to NCLIENT clients
    // TODO: Accept incoming connections
}

int main(int argc, char *argv[]) {
    // Argument variables
    int portNumber, idNumber;
    char* inputFile, serverAddress;

    // Socket variables
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length;
    char buffer[BUF_SIZE];

    // Check arguments
    if (argc < 3) {
        printf("Usage: %s -s portNumber (server) | %s -c idNumber inputFile serverAddress portNumber (client)\n", argv[0], argv[0]);
        exit(1);
    }
    if (strcmp(argv[1], "-s") == 0) {
        // TODO: Parse arguments
        portNumber = atoi(argv[2]);

        // TODO: Call server

    } else if (strcmp(argv[1], "-c") == 0) {
        if (argc < 6) {
            printf("Usage: %s -s portNumber (server) | %s -c idNumber inputFile serverAddress portNumber (client)\n", argv[0], argv[0]);
            exit(1);
        }
        // TODO: Parse arguments
        idNumber = atoi(argv[2]);
        portNumber = atoi(argv[5]);

        // TODO: Call client
    }
}