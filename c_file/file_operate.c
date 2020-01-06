#include "file_operate.h"

/**
 * 读取文件
 * @return
 */
void readFile(char *file_path) {
    FILE *fp = fopen(file_path, "r");
    printf("\n");
    //读取
    char buff[50]; //缓冲
    while (fgets(buff, 50, fp)) {
        printf("%s", buff);
    }
    printf("\n");
    //关闭
    fclose(fp);
}

/**
 * 写入文本文件
 */
void writeFile(char *file_path, char *content) {
    FILE *fp = fopen(file_path, "w+");
    fputs(content, fp);
    fclose(fp);
}

void copyFile(char *read_path, char *copy_path) {
    FILE *read_fp = fopen(read_path, "r");
    FILE *write_fp = fopen(copy_path, "w+");
    //复制
    int buff[50];
    long len = 0;
    while ((len = fread(buff, sizeof(int), 50, read_fp)) != 0) {
        fwrite(buff, sizeof(int), len, write_fp);
    }
    //关闭流
    fclose(read_fp);
    fclose(write_fp);
}

/**
 * 获取文件大小
 */
void getFileSize(char *file_path) {
    FILE *fp = fopen(file_path, "r");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("\n文件的大小:%ld\n", size);
}

/**
 * 获取代码根目录
 */
void getPath(char *pwd) {
    char basePath[100];
    // 打印当前路径
    memset(basePath, '\0', sizeof(basePath));
    memset(pwd, '\0', sizeof(basePath));
    getcwd(basePath, 999);
    char search = '/';
    char *address = strrchr(basePath, search);
    long index = address - basePath;
    memccpy(pwd, basePath, 0, index);
}

/**
 *
 */
char *getFileName(char *pwd, char *fileName) {
    memset(pwd, '\0', sizeof(pwd));
    getPath(pwd);
    char *str = strcat(pwd, fileName);
    return str;
}

/**
 * 简单异或加密
 */
void crpypt(char normal_path[], char crypt_path[]) {
    FILE *normal_fp = fopen(normal_path, "r");
    FILE *crypt_fp = fopen(crypt_path, "w+");
    int ch;
    while ((ch = fgetc(normal_fp)) != EOF) { //End of File
        fputc(ch ^ 9, crypt_fp);
    }
    fclose(crypt_fp);
    fclose(normal_fp);
}

/**
 * 简单异或解密
 */
void decrpypt(char crypt_path[], char decrypt_path[]) {
    FILE *normal_fp = fopen(crypt_path, "r");
    FILE *crypt_fp = fopen(decrypt_path, "w+");
    int ch;
    while ((ch = fgetc(normal_fp)) != EOF) { //End of File
        fputc(ch ^ 9, crypt_fp);
    }
    fclose(crypt_fp);
    fclose(normal_fp);
}

/**
 * 使用密码进行异或加密
 * @param normal_path
 * @param crypt_path
 * @param password
 */
void crpypt_pwd(char *normal_path, char *crypt_path, char *password) {
    FILE *normal_fp = fopen(normal_path, "rb");
    FILE *crypt_fp = fopen(crypt_path, "wb+");
    int ch;
    int i = 0;
    unsigned pwd_len = strlen(password);
    while ((ch = fgetc(normal_fp)) != EOF) { //End of File
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    fclose(crypt_fp);
    fclose(normal_fp);
}

/**
 * 使用密码进行异或解密
 * @param crypt_path
 * @param decrypt_path
 * @param password
 */
void decrpypt_pwd(char *crypt_path, char *decrypt_path, char *password) {
    FILE *normal_fp = fopen(crypt_path, "rb");
    FILE *crypt_fp = fopen(decrypt_path, "wb+");
    int ch;
    long i = 0;
    unsigned long pwd_len = strlen(password);
    while ((ch = fgetc(normal_fp)) != EOF) { //End of File
        fputc(ch ^ password[i % pwd_len], crypt_fp);
        i++;
    }
    fclose(crypt_fp);
    fclose(normal_fp);

}
