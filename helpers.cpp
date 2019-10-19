#include "helpers.hpp"
#include <algorithm>
#include <string>

constexpr const int MAX_DIGITS = 5;

int get_last_result_value(FILE *file)
{
    fseek(file, 0, SEEK_END);
    int pos = (int) ftell(file);
    char digit_chars[MAX_DIGITS + 1];
    int num_digits = 0;
    char buf = 0;

    while (pos > 0) {
        pos -= 1;
        fseek(file, pos, SEEK_SET);
        fread(&buf, sizeof(char), 1, file);
        if (buf == ',') {
            // what precedes is a number
            // read till beginning of line
            while (pos > 0 && buf != '\n' && num_digits < MAX_DIGITS) {
                pos -= 1;
                fseek(file, pos, SEEK_SET);
                fread(&digit_chars[num_digits], 1, 1, file);
                num_digits++;
            }
            break;
        }
    }
    if (num_digits > 0) {
        // reverse digits and convert to number
        std::reverse(digit_chars, digit_chars);
        digit_chars[num_digits] = '\0';
        return atoi(digit_chars);
    }

    return 0;
}

void write_result_line(FILE *file, int value, int node_id)
{
    std::string val_str = std::to_string(value);
    std::string id_str = std::to_string(node_id);
    char col_sep = ',';
    char line_sep = '\n';
    fwrite(val_str.c_str(), sizeof(char), val_str.size(), file);
    fwrite(&col_sep, sizeof(char), 1, file);
    fwrite(id_str.c_str(), sizeof(char), id_str.size(), file);
    fwrite(&line_sep, sizeof(char), 1, file);
}
