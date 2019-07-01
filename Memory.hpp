class Memory {
public:
    bool can_allocate(int64_t size);
    void allocate(int64_t size);
    void release(int64_t size);
    void init(int64_t size) {
        memory = size;
    }
private:
    int64_t memory;
};
