#ifndef IOSTREAMUTIL_BINARYSTREAM_HPP
#define IOSTREAMUTIL_BINARYSTREAM_HPP

#include<iostream>

namespace iou {
class IBinaryReadable {
public:
    //Loads This Instance From A Binary Stream
    virtual void ReadFromBinaryStream(std::istream& istr, std::ostream& err = std::cerr) = 0;
};
}

#endif
