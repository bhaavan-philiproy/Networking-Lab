#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(12345);

    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    memset(buffer, 0, 1024);
    sprintf(buffer, "%d", n);
    write(client_socket, buffer, strlen(buffer));

    memset(buffer, 0, 1024);
    read(client_socket, buffer, 1023);

    int result = atoi(buffer);
    printf("Factorial of %d is %d\n", n, result);

    close(client_socket);

    return 0;
}
