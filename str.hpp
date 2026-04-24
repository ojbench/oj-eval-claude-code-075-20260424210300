#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
    char *data;
    size_t length;

    void allocate_and_copy(const char *s, size_t len) {
        length = len;
        if (length > 0) {
            data = new char[length + 1];
            std::memcpy(data, s, length);
            data[length] = '\0';
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

public:
    str() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
    }

    str(const char &c) : data(nullptr), length(1) {
        data = new char[2];
        data[0] = c;
        data[1] = '\0';
    }

    str(const char *&& s_) : data(nullptr), length(0) {
        if (s_) {
            length = std::strlen(s_);
            data = new char[length + 1];
            std::memcpy(data, s_, length + 1);
        } else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    str &operator=(const char *&& s_) {
        delete[] data;
        if (s_) {
            length = std::strlen(s_);
            data = new char[length + 1];
            std::memcpy(data, s_, length + 1);
        } else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
        return *this;
    }

    str(const str &other) : data(nullptr), length(other.length) {
        if (other.data) {
            data = new char[length + 1];
            std::memcpy(data, other.data, length + 1);
        } else {
            data = new char[1];
            data[0] = '\0';
            length = 0;
        }
    }

    str &operator=(const str &other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            if (other.data) {
                data = new char[length + 1];
                std::memcpy(data, other.data, length + 1);
            } else {
                data = new char[1];
                data[0] = '\0';
                length = 0;
            }
        }
        return *this;
    }

    char &operator[](size_t pos) {
        return data[pos];
    }

    const char &operator[](size_t pos) const {
        return data[pos];
    }

    size_t len() const {
        return length;
    }

    str join(const std::vector<str> &strs) const {
        if (strs.empty()) {
            return str();
        }

        size_t total_length = 0;
        for (size_t i = 0; i < strs.size(); ++i) {
            total_length += strs[i].len();
        }
        total_length += length * (strs.size() - 1);

        char *result = new char[total_length + 1];
        size_t pos = 0;

        for (size_t i = 0; i < strs.size(); ++i) {
            if (strs[i].data) {
                std::memcpy(result + pos, strs[i].data, strs[i].len());
                pos += strs[i].len();
            }

            if (i < strs.size() - 1 && data) {
                std::memcpy(result + pos, data, length);
                pos += length;
            }
        }

        result[total_length] = '\0';

        str ret;
        delete[] ret.data;
        ret.data = result;
        ret.length = total_length;

        return ret;
    }

    str slice(size_t l, size_t r) const {
        if (l >= r || l >= length) {
            return str();
        }

        size_t slice_len = (r > length) ? length - l : r - l;
        str result;
        delete[] result.data;
        result.data = new char[slice_len + 1];
        std::memcpy(result.data, data + l, slice_len);
        result.data[slice_len] = '\0';
        result.length = slice_len;

        return result;
    }

    ~str() {
        delete[] data;
    }
};