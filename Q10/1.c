#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    // First fork: parent exits, child runs in background
    if (fork())
        exit(0);

    // Create new session and detach from terminal
    setsid();

    // Second fork: ensures daemon cannot regain terminal
    if (fork())
        exit(0);

    // Change working directory to avoid locking current directory
    chdir("/");

    // Close standard input, output, error
    close(0);
    close(1);
    close(2);

    // Redirect stdin/stdout/stderr to /dev/null
    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);

    // Daemon loop: runs forever in background
    while (1)
    {
        // Open log file in append mode
        int fd = open("/tmp/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

        // Write log message
        write(fd, "Daemon is running\n", 19);

        // Close file descriptor
        close(fd);

        // Sleep to avoid CPU overuse
        sleep(5);
    }
}