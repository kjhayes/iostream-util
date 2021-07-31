#ifndef IOSTREAMUTIL_BYTESTREAM_HPP
#define IOSTREAMUTIL_BYTESTREAM_HPP

#include<iostream>

namespace iou {

class ByteBuffer : std::stream_buf<char> {
    ByteBuffer(char* begin, char* end){
        setg(begin, begin, end);
    }
};

class ByteIStream : std::istream {
    ByteIStream() {}
    ByteIStream(ByteBuffer& buf) {
        in(buf);
    }
    ByteIStream(char* begin, char* end) {
        ByteBuffer buf(begin, end);
        in(buf);
    }
};

}

#endif