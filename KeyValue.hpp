#include <string>

class KeyValue {
public:
    KeyValue(const std::string &tkey, const std::string &tval) {
        key = tkey;
        value = tval;
        size = key.length()+value.length();
    }

    std::string getKey() {
        return key;
    }

    std::string getValue() {
        return value;
    }

    void setKey(const std::string &tkey) {
        key = tkey;
    }

    void setValue(const std::string &tval) {
        value = tval;
    }


    int64_t getSize() {
        return size;
    }

    bool operator < (const KeyValue& toComp) const
    {
        return (key < toComp.key);
    }

    KeyValue() {
    }
private:
    std::string key;
    std::string value;
    int64_t size;
};
