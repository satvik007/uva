#include <stdio.h>
#include <string.h>

char get_next_token() {
    char line[10];
    scanf("%s", line);
    return line[0] >= 'a' ? line[0] - 'a' + 'A' : line[0];
}

int count_execution_paths() {
    char token;
    int execution_paths = 1;
    while ((token = get_next_token()) != 'E') {
        if (token == 'S')
            continue;
        if (token == 'I')
            execution_paths *= (count_execution_paths()
                    + count_execution_paths());
    }
    return execution_paths;
}
int main() {
    int t;
    for (scanf("%d", &t); t; t--)
        printf("%d\n", count_execution_paths());
    return 0;
}
