#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#include <mavlink/common/mavlink.h>

#define BUFFER_SIZE 512

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    mavlink_message_t msg;
    mavlink_status_t status;

    for (size_t i = 0; i < size; i++) {
        if (mavlink_parse_char(MAVLINK_COMM_0, data[i], &msg, &status)) {
            // TODO
        }   
        // printf("[CSE569] Parsed a MAVLink message\n");
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    uint8_t buffer[BUFFER_SIZE];
    size_t len = fread(buffer, 1, BUFFER_SIZE, fp);
    fclose(fp);

    LLVMFuzzerTestOneInput(buffer, len);

    return 0;
}
