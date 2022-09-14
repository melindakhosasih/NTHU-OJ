#include <iostream>
#include "function.h"

oj::Vector::Vector(){
    begin_ = new Int[0];
    end_ = last_ = begin_;
}

oj::Vector::~Vector(){
    delete [] begin_;
}

std::size_t oj::Vector::capacity() const {
    return end_ - begin_;
}

std::size_t oj::Vector::size() const {
    return last_ - begin_;
}

void oj::Vector::pop_back() {
    if(size() > 0) last_--;
}

void oj::Vector::push_back(value_type val) {
    size_type old_capacity = capacity();
    if(size() == capacity()) {
        if(old_capacity + 1 > old_capacity *3) reserve(old_capacity + 1);
        else reserve(old_capacity*3);
    }
    *last_ = val;
    last_++;
}

void oj::Vector::insert(size_type pos, size_type count, value_type val) {
    size_type old_capacity = capacity();
    size_type old_size = size();
    if(pos + count > old_capacity) {
        if(old_capacity + old_capacity/2 > old_capacity + count) reserve(old_capacity + old_capacity/2);
        else reserve(old_capacity + count);
    }
    resize(old_size + count);
    for(size_type i = size()-1; i >= pos + count; i--)
        begin_[i] = begin_[i-count];
    for(size_type i = pos; i < pos+count; i++)
        begin_[i] = val;
}

void oj::Vector::reserve(size_type new_capacity) {
    size_type old_size = size();
    if(new_capacity > capacity()) {
        pointer new_begin = new Int [new_capacity];
        for(size_type i = 0; i < old_size; i++)
            new_begin[i] = begin_[i];
        delete [] begin_;
        begin_ = new_begin;
        last_ = &begin_[old_size];
        end_ = &begin_[new_capacity];
    }
}

void oj::Vector::resize(size_type new_size) {
    size_type old_size = size();
    size_type old_capacity = capacity();
    if(new_size < old_size) {
        for(size_type i = old_size; i > new_size; i--)
            pop_back();
    }
    else if(new_size > old_size) {
        if(new_size > old_capacity)
            reserve(new_size);
        for(size_type i = old_size; i < new_size; i++)
            push_back(0);
    }
}
