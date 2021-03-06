#ifndef IOSTREAMUTIL_IBINARYWRITEABLE_HPP
#define IOSTREAMUTIL_IBINARYWRITEABLE_HPP

#include<iostream>

namespace iou {
class IBinaryWriteable {
public:
    virtual void WriteToBinaryStream(std::ostream& ostr) const = 0;
};
}

#endif