#include "file_operate.h"

int main(void) {
    char read[100];
    char write[100];
    char copy[100];
    char encode[100];
    char decode[100];
    char* read_file =getFileName(read,"/article/read.txt");
    char* write_file =getFileName(write,"/article/write.txt");
    char* copy_file =getFileName(copy,"/article/copy.txt");
    char* encode_file =getFileName(encode,"/article/encode.txt");
    char* decode_file =getFileName(decode,"/article/decode.txt");
    // 读取文件
    readFile(read_file);
    // 写入文件
    char* content = "这是要写入文件的内容~";
    writeFile(write_file,content);
    // 读取文件长度
    getFileSize(write_file);

    copyFile(read_file, copy_file);
    // 进行加密操作
//    crpypt(read_file,encode_file);
//    decrpypt(encode_file,decode_file);
    crpypt_pwd(read_file,encode_file,"password");
    decrpypt_pwd(encode_file,decode_file,"password");
    READ(write_file);
    READ(copy_file);
    READ(encode_file);
    READ(decode_file);
    return 0;
}



