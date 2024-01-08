#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Định nghĩa cấu trúc BMP
typedef struct BMP
{
    int width;
    int height;
    int size;
} BMP;

// Hàm kiểm tra số lượng hàng xóm sống của một ô cụ thể trong Game of Life
int Live(int** currentGen, int x, int y, int w, int h) {
    int count = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            // Kiểm tra xem ô có thuộc biên không
            if ((i == y && j == x) || (i < 0 || j < 0) || (i >= h || j >= w)) {
                continue; // Bỏ qua nếu là ô ở biên
            }
            if (currentGen[i][j] == 1) {
                count++;
            }
        }
    }
    // Quy tắc sống/chết của Game of Life
    if (currentGen[y][x]) {
        if (count >= 2 && count <= 3) return 1; // Sống tiếp
        return 0; // Chết
    } else {
        if (count == 3) return 1; // Sinh lại
        return 0; // Giữ nguyên trạng thái
    }
}

// Hàm thực hiện một bước trong trò chơi Game of Life
void GameOfLife(int **currentGen, int width, int height) {
    // Tạo ma trận mới để lưu trạng thái tiếp theo
    int **nextGen = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        nextGen[i] = (int*)malloc(sizeof(int) * width);
    }

    int x, y;
    // Tính trạng thái tiếp theo dựa trên trạng thái hiện tại
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (Live(currentGen, x, y, width, height)) {
                nextGen[y][x] = 1; // Sống
            } else {
                nextGen[y][x] = 0; // Chết
            }
        }
    }
    // Sao chép trạng thái mới vào trạng thái hiện tại
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            currentGen[y][x] = nextGen[y][x];
        }
    }
    // Giải phóng bộ nhớ của ma trận mới
    for (int i = 0; i < height; i++) {
        free(nextGen[i]);
    }
    free(nextGen);
}

int main(int argc, char* argv[]) {
    BMP image;
    unsigned char *inputFile, *outputDir;
    int max_iter = 100;
    int dump_freq = 1;
    int i, j, padding;

    // Đọc tham số dòng lệnh
    for (i = 1; i < argc; i++) {
        if (strstr(argv[i], "--input")) {
            inputFile = argv[i + 1];
        } else if (strstr(argv[i], "--output")) {
            outputDir = argv[i + 1];
        } else if (strstr(argv[i], "--max_iter")) {
            max_iter = atoi(argv[i + 1]);
        } else if (strstr(argv[i], "--dump_freq")) {
            dump_freq = atoi(argv[i + 1]);
        }
    }

    FILE *f = fopen(inputFile, "rb");
    if (f == NULL) {
        printf("File not found !");
        return 0;
    }

    unsigned char header[54];
    // Đọc thông tin cơ bản của tệp BMP
    fread(header, 54, 1, f);
    image.size = header[2] + (header[3] << 8) + (header[4] << 16) + (header[5] << 24);
    image.width = header[18] + (header[19] << 8) + (header[20] << 16) + (header[21] << 24);
    image.height = header[22] + (header[23] << 8) + (header[24] << 16) + (header[25] << 24);
    int starting_offset = header[10] + (header[11] << 8) + (header[12] << 16) + (header[13] << 24);
    header[10] = 0x36;
    header[11] = 0;
    header[12] = 0;
    header[13] = 0;

    // Đọc dữ liệu pixel từ tệp BMP
    unsigned char* original = (unsigned char*)malloc((image.size - starting_offset) * sizeof(unsigned char));
    fseek(f, starting_offset, SEEK_SET);
    fread(original, sizeof(unsigned char), image.size, f);

    int **data = (int**)malloc(image.height * sizeof(int*));
    for (i = 0; i < image.height; i++) {
        data[i] = (int*)malloc(image.width * sizeof(int));
    }
    int padding_size = (image.width * 3) % 4;
    int k = 0;
    // Chuyển đổi dữ liệu pixel sang ma trận số 0 và 1
    for (i = image.height - 1; i >= 0; i--) {
        for (j = 0; j < image.width; j++) {
            if (original[k] == 255) {
                data[i][j] = 0; // Ảnh đen
            } else {
                data[i][j] = 1; // Ảnh trắng
            }
            k += 3;
        }
        for (padding = 0; padding < padding_size; padding++) { // Padding ở cuối mỗi hàng
            k++;
        }
    }

    int byteCounter;
    // Thực hiện Game of Life và xuất ảnh kết quả
    for (int iter = 0; iter < max_iter; iter++) {
        GameOfLife(data, image.width, image.height);
        if (iter % dump_freq != 0) {
            continue;
        }
        char outputFile[20];
        char filepath[100] = "";
        strcat(filepath, outputDir);
        strcat(filepath, "/");
        strcat(filepath, itoa(iter, outputFile, 10));
        strcat(filepath, ".bmp");
        FILE *output = fopen(filepath, "wb");
        // Ghi thông tin BMP vào tệp mới
        fwrite(header, 1, 54, output);

        byteCounter = 0;
        // Chuyển đổi ma trận số 0 và 1 thành dữ liệu pixel BMP
        for (i = image.height - 1; i >= 0; i--) {
            for (j = 0; j < image.width; j++) {
                for (k = 0; k < 3; k++) {
                    if (data[i][j] == 1) {
                        original[byteCounter] = 0; // Ảnh trắng
                    } else {
                        original[byteCounter] = 255; // Ảnh đen
                    }
                    byteCounter++;
                }
            }
            for (padding = 0; padding < padding_size; padding++) {
                original[byteCounter] = 0; // Padding
                byteCounter++;
            }
        }
        // Ghi dữ liệu pixel vào tệp mới
        fwrite(original, sizeof(unsigned char), image.size, output);
        fclose(output);
    }
    // Giải phóng bộ nhớ
    for (i = 0; i < image.height; i++) {
        free(data[i]);
    }
    free(data);
    free(original);
    return 0;
}
