#include<iostream>

#include "Memory.hpp"

bool Memory::can_allocate(int64_t size)
{
    return size <= memory;
}

void Memory::allocate(int64_t size)
{
    memory -= size;
}

void Memory::release(int64_t size)
{
    memory += size;
}
