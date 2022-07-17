
#include "engine.h"

void file_read_all(ifstream *stream_src, string *dest_string) {
    string buffer;
    while (getline(*stream_src, buffer)) {
	*dest_string += buffer + '\n';
    }
}
