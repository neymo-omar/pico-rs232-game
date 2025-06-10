#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#ifdef _WIN32

#include <windows.h>

#else

#include <unistd.h>

#endif



#include "rs232.h" // Ensure rs232.c and rs232.h are in your project



#define COM_PORT    27     // COM28 (0-based index for RS232 library)

#define BAUD_RATE   9600   // Baud rate for communication

#define BUFFER_SIZE 256    // Maximum buffer size for messages

#define DELAY_MS    100    // Delay in milliseconds between operations



void wait_ms(int ms);

void display_message(const char *message);

int read_from_pico(int port, char *buffer, int buffer_size);

void send_to_pico(int port, const char *message);

void play_game(int port);

int handle_replay(int port);



int main() {

    char buffer[BUFFER_SIZE];

    int port = COM_PORT;



    // Open the COM port

    if (RS232_OpenComport(port, BAUD_RATE, "8N1", 0)) {

        fprintf(stderr, "Error: Unable to open COM28 for communication.\n");

        return EXIT_FAILURE;

    }



    display_message("Connected to COM28. Game starting...\n");



    // Main game loop

    while (1) {

        play_game(port);



        // Handle replay prompt

        if (!handle_replay(port)) {

            display_message("Exiting game. Goodbye!\n");

            break;

        }

    }



    RS232_CloseComport(port);  // Close the COM port before exiting

    return EXIT_SUCCESS;

}



// Function to play the game by communicating with the Pico

void play_game(int port) {

    char buffer[BUFFER_SIZE];



    // Wait for the Pico to send the sequence

    display_message("Waiting for the sequence from Pico...\n");

    if (read_from_pico(port, buffer, BUFFER_SIZE)) {

        display_message("Sequence received: ");

        printf("%s\n", buffer);

    } else {

        display_message("Error: Failed to receive sequence from Pico.\n");

        return;

    }



    // Prompt user for input

    printf("Enter the sequence: ");

    char user_input[BUFFER_SIZE];

    fgets(user_input, BUFFER_SIZE, stdin);

    user_input[strcspn(user_input, "\n")] = '\0';  // Remove newline



    // Send the user's input to the Pico

    send_to_pico(port, user_input);



    // Wait for the Pico's response

    if (read_from_pico(port, buffer, BUFFER_SIZE)) {

        display_message("Pico's response: ");

        printf("%s\n", buffer);

    } else {

        display_message("Error: Failed to receive response from Pico.\n");

    }

}



// Function to handle replay prompts

int handle_replay(int port) {

    char buffer[BUFFER_SIZE];

    char replay_response;



    display_message("Do you want to play again? (y/n): ");

    scanf(" %c", &replay_response);

    getchar();  // Consume the leftover newline character



    // Send replay response to Pico

    snprintf(buffer, BUFFER_SIZE, "%c\n", replay_response);

    send_to_pico(port, buffer);



    // Check if user wants to exit

    return (replay_response == 'y' || replay_response == 'Y');

}



// Function to send a message to the Pico

void send_to_pico(int port, const char *message) {

    RS232_SendBuf(port, (unsigned char *)message, strlen(message));

    display_message("Message sent to Pico.\n");

}



// Function to read a message from the Pico

int read_from_pico(int port, char *buffer, int buffer_size) {

    int bytes_received = RS232_PollComport(port, (unsigned char *)buffer, buffer_size - 1);

    if (bytes_received > 0) {

        buffer[bytes_received] = '\0'; // Null-terminate the received string

        printf("Data from the Pico: %s\n", buffer);

        return 1; // Success

    }

    printf("No data from the Pico.\n");

    return 0; // Failure

}



// Function to display a message with delay

void display_message(const char *message) {

    printf("%s", message);

    fflush(stdout);

    wait_ms(DELAY_MS);

}



// Cross-platform function to pause execution for a specified number of milliseconds

void wait_ms(int ms) {

#ifdef _WIN32

    Sleep(ms);

#else

    usleep(ms * 1000);

#endif

}

