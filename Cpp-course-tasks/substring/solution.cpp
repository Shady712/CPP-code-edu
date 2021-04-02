#include <cstdio>
#include <cstring>
#include <cstdlib>

void end(FILE* file, bool found) {
    fprintf(stdout, "%s", found ? "Yes" : "No");
    fclose(file);
}
bool compare(const char* t, const char* arg, size_t id) {
    size_t k = 0;
    for (size_t i = id; i < strlen(arg); i++) {
        if (t[i] != arg[k++]) {
            return false;
        }
    }
    for (size_t i = 0; i < id; i++) {
        if (t[i] != arg[k++]) {
            return false;
        }
    }
    return true;
}
int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Invalid program arguments. Provide such arguments: <Filename> <Word>");
        return -1;
    }
    FILE* input = fopen(argv[1], "rb");
    if (input == nullptr) {
        fprintf(stderr, "File %s can not be opened", argv[1]);
        return -1;
    }
    const char* word = argv[2];
    size_t n = strlen(word);
    char* t = (char*) malloc((n + 1) * sizeof(char));
    size_t id;
    int symbol = 1;
    for (id = 0; id < n; id++) {
        symbol = fgetc(input);
        if (symbol == EOF) {
            if (ferror(input)) {
                fprintf(stderr, "Error during reading");
                free(t);
                fclose(input);
                return -1;
            }
            break;
        }
        t[id] = symbol;
    }
    if (id < n) {
        end(input, false);
        free(t);
        return 0;
    }
    if (compare(t, word, 0)) {
        end(input, true);
        free(t);
        return 0;
    }
    if (symbol == EOF) {
        end(input, false);
        free(t);
        return 0;
    }
    id = 0;
    for (symbol = fgetc(input); symbol != EOF; symbol = fgetc(input)) {
        t[id++] = symbol;
        if (id == n) {
            id = 0;
        }
        if (compare(t, word, id)) {
            end(input, true);
            free(t);
            return 0;
        }
    }
    if (ferror(input)) {
        fprintf(stderr, "Error during reading");
        free(t);
        fclose(input);
        return -1;
    }
    end(input, compare(t, word, id));
    free(t);
    return 0;
}
