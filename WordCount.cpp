#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
    FILE *fp;
    int cnt = 0; // 计数器 
    if ((fp=fopen(argv[2], "r")) == NULL){
        puts("error!\n");
        return 0;
    }
    
    // 统计单词
    if (argv[1][1] == 'w') {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF){
            cnt ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词个数=%d\n", cnt);
    }
    
    // 统计字符
    else if (argv[1][1] == 'c') {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符个数数=%d", cnt);
    }
    
    fclose(fp);
    return 0;
}


