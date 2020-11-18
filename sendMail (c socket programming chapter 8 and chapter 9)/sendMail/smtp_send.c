#include "lib.h"
#include <ctype.h>
#include <stdarg.h>

#define MAXINPUT 512
#define MAXRESPONSE 1024

void get_input(const char* prompt, char* buffer)
{
	printf("%s", prompt);
	buffer[0] = 0;
	fgets(buffer, MAXINPUT, stdin);
	const int read = strlen(buffer);
	if (read > 0)
		buffer[read - 1] = 0;
}

void send_format(SOCKET server, const char* text)
{
	char buffer[1024];
	va_list args;
	va_start(args, text);
	// check bufferoverflow later.
	vsprintf_s(buffer, 1024, text, args);
	//vsprintf(buffer, text, args);
	va_end(args);
	
	send(server, buffer, strlen(buffer), 0);

	printf("C: %s", buffer);
}

int parse_response(const char* response) {
	const char* k = response;
	if (!k[0] || !k[1] || !k[2]) return 0;
	for (; k[3]; ++k) {
		if (k == response || k[-1] == '\n') {
			if (isdigit(k[0]) && isdigit(k[1]) && isdigit(k[2])) {
				if (k[3] != '-') {
					if (strstr(k, "\r\n")) {
						return strtol(k, 0, 10);
					}
				}
			}
		}
	}
	return 0;
}


void wait_on_response(SOCKET server, int expecting)
{
	char response[MAXRESPONSE + 1];
	char* p = response;
	char* end = response + MAXRESPONSE;

	int code = 0;

	do
	{
		int bytes_received = recv(server, p, end - p, 0);

		if (bytes_received < 1)
		{
			fprintf(stderr, "Connection dropeed.\n");
			exit(1);
		}

		p += bytes_received;

		*p = 0;

		if (p == end)
		{
			fprintf(stderr, "Server response too large:\n");
			fprintf(stderr, "%s", response);
			exit(1);
		}
		code = parse_response(response);
	} while (code == 0);

	if (code != expecting)
	{
		fprintf(stderr, "Error from server:\n");
		fprintf(stderr, "%s", response);
		exit(1);
	}

	printf("S: %s", response);


}

SOCKET connect_to_host(const char* hostname, const char* port)
{
	printf("Configuring remote address...\n");
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints)); // set every element of hints to zero.
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo* peer_address;

	if (getaddrinfo(hostname, port, &hints, &peer_address))
	{
		fprintf(stderr, "getaddrinfo() failed. (%d)\n", GETSOCKETERRNO());
		exit(1);
	}

	printf("Remote address is: ");

	char address_buffer[100];
	char service_buffer[100];

	getnameinfo(peer_address->ai_addr, peer_address->ai_addrlen,
		address_buffer, sizeof(address_buffer),
		service_buffer, sizeof(service_buffer),
		NI_NUMERICHOST);


	printf("%s %s\n", address_buffer, service_buffer);


	printf("Creating socket...\n");
	SOCKET server;
	server = socket(peer_address->ai_family, peer_address->ai_socktype,
		peer_address->ai_protocol);


	if (!ISVALIDSOCKET(server))
	{
		fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
		exit(1);
	}

	printf("Connecting...\n");

	if (connect(server, peer_address->ai_addr, peer_address->ai_addrlen))
	{
		fprintf(stderr, "connect() failed. (%d)\n", GETSOCKETERRNO());
		exit(1);
	}

	freeaddrinfo(peer_address);

	printf("Connected.\n\n");

	return server;
}

int main()
{
#if defined(_WIN32)
	WSADATA d;
	if (WSAStartup(MAKEWORD(2, 2), &d))
	{
		fprintf(stderr, "Failed to initialize.\n");
		return 1;
	}
#endif

	//char hostname[] = "smtp-relay.sendinblue.com";
	//"smtp.gmail.com";
	
	char hostname[] = "smtp.gmail.com";
	char port[] = "587";
	
	//get_input("mail server: ", hostname);

	printf("Connecting to host: %s:%s\n", hostname, port);

	SOCKET server = connect_to_host(hostname, port);

	wait_on_response(server, 220);


	send_format(server, "EHLO elgun\r\n");
	wait_on_response(server, 250);



	send_format(server, "STARTTLS\r\n");

	wait_on_response(server, 220);

	send_format(server, "EHLO elgun\r\n");
	wait_on_response(server, 220);
	//get_input(">>" , port);

	send_format(server, "AUTH LOGIN\r\n");
	wait_on_response(server, 334);

	send_format(server, "LOGIN BASE64\r\n");
	wait_on_response(server, 334);

	send_format(server, "PASSWORD BASE64\r\n");
	wait_on_response(server, 235);


	//char sender[MAXINPUT];
	//get_input("from: ", sender);
	
	char sender[] = "SENDER MAIL";
	send_format(server, "MAIL FROM:<%s>\r\n", sender);
	wait_on_response(server, 250);

	//char recipient[MAXINPUT];
	//get_input("to: ", recipient);

	char recipient[] = "RECIPIENT MAIL";
	send_format(server, "RCPT TO:<%s>\r\n", recipient);
	wait_on_response(server, 250);

	send_format(server, "DATA\r\n");
	wait_on_response(server, 354);

	//char subject[MAXINPUT];
	//get_input("subject: ", subject);

	char subject[] = "test";
	send_format(server, "From:<%s>\r\n", sender);
	send_format(server, "To:<%s>\r\n", recipient);
	send_format(server, "Subject:<%s>\r\n", subject);

	time_t timer;
	time(&timer);

	struct tm* timeinfo;

	timeinfo = gmtime(&timer);

	char date[128];

	strftime(date, 128, "%a, %d %b %Y %H:%M:%S +0000", timeinfo);

	send_format(server, "Date:%s\r\n", date);

	send_format(server, "\r\n");

	printf("Enter your email text, end with '.' on a line by itself.\n");

	while (1)
	{
		char body[MAXINPUT];
		get_input("> ", body);
		send_format(server, "%s\r\n", body);

		if (strcmp(body, ".") == 0)
		{
			break;
		}
	}

	printf("after while");
	wait_on_response(server, 250);

	send_format(server, "QUIT\r\n");

	wait_on_response(server, 221);


	printf("\nClosing socket...\n");

	CLOSESOCKET(server);

#if defined(_WIN32)
	WSACleanup();
#endif

	printf("Finished.\n");
	return 0;
}