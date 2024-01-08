#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void createDirectories(int argc, char *argv[]) {
    // Kiểm tra xem có đủ số lượng tham số không
    if (argc < 2) {
        printf("Usage: %s <dir1> <dir2> ... [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Tạo các thư mục
    for (int i = 1; i < argc - 1; ++i) {
        if (!CreateDirectory(argv[i], NULL)) {
            perror("CreateDirectory");
            exit(EXIT_FAILURE);
        }
    }

    // Xác định tên tệp văn bản đầu ra
    const char *outputFileName = (argc > 2) ? argv[argc - 1] : "output.txt";

    // Tạo tệp văn bản để chứa danh sách các thư mục con
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Ghi danh sách thư mục con vào tệp văn bản
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("*", &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        perror("FindFirstFile");
        exit(EXIT_FAILURE);
    }

    fprintf(outputFile, "List of subdirectories:\n");

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            fprintf(outputFile, "%s\n", findFileData.cFileName);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    // Đóng tệp và handle
    fclose(outputFile);
    FindClose(hFind);

    printf("Directories and subdirectories created successfully.\n");
}

int main(int argc, char *argv[]) {
    createDirectories(argc, argv);
    return 0;
}
