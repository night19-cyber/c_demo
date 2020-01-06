#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#ifndef C_FILE_FILE_OPERATE_H
#define C_FILE_FILE_OPERATE_H

#define READ(file_path) readFile(file_path);

void getPath(char pwd[]);

char *getFileName(char *pwd, char *path);

void readFile(char *file_path);

void writeFile(char *file_path, char *content);

void copyFile(char *read_path, char *copy_path);

void getFileSize(char *file_path);

void crpypt(char normal_path[], char crypt_path[]);

void decrpypt(char normal_path[], char crypt_path[]);

void crpypt_pwd(char *normal_path, char *crypt_path, char *password);

void decrpypt_pwd(char *crypt_path, char *decrypt_path, char *password);

#endif //C_FILE_FILE_OPERATE_H
