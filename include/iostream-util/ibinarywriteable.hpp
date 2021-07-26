#ifndef IOSTREAMUTIL_IBINARYWRITEABLE_HPP
#define IOSTREAMUTIL_IBINARYWRITEABLE_HPP

#include<iostream>

namespace iou {
class IBinaryWriteable {
public:
    virtual void WriteToBinaryStream(std::istream& istr) = 0;
};
}

#endif