#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = 1234;
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);

    printf("Write Data: ");
    fgets(str, 100, stdin);

    printf("Data written in memory: %s\n", str);
    shmdt(str);
    return 0;
}
