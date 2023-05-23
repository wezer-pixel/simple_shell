#include "command.h"

void execute_command(char** args) {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("Error forking");
    } else {
        // Parent process
        wait(NULL);
    }
}
