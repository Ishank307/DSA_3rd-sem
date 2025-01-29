#include <stdio.h>

int main() {
        if (remove("/C:/ishank_github/DSA_3rd-sem/stack/tempCodeRunnerFile.c") == 0) {
                printf("File deleted successfully.\n");
        } else {
                printf("Error: unable to delete the file.\n");
        }
        return 0;
}