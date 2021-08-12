#ifndef IOSTREAMUTIL_STREAMWRITE_HPP
#define IOSTREAMUTIL_STREAMWRITE_HPP

#include<iostream>
#include<stdint.h>

namespace iou {

inline void PutU8(std::ostream& ostr, const uint8_t& i) {
    ostr.write((char*)(&i), 1);
}

//Big Endian
inline void PutBEU16(std::ostream& ostr, const uint16_t& i) {
    PutU8(ostr, ((i&0xFF00)>>8));
    PutU8(ostr, (i&0x00FF)); 
}
inline void PutBEU32(std::ostream& ostr, const uint32_t& i) {
    PutBEU16(ostr, ((i&0xFFFF0000)>>16));
    PutBEU16(ostr, (i&0x0000FFFF)); 
}
inline void PutBEU64(std::ostream& ostr, const uint64_t& i) {
    PutBEU32(ostr, ((i&0xFFFFFFFF00000000)>>32));
    PutBEU32(ostr, (i&0x00000000FFFFFFFF)); 
}
//Little Endian
inline void PutLEU16(std::ostream& ostr, const uint16_t& i) {
    PutU8(ostr, (i&0x00FF)); 
    PutU8(ostr, ((i&0xFF00)>>8));
}
inline void PutLEU32(std::ostream& ostr, const uint32_t& i) {
    PutLEU16(ostr, (i&0x0000FFFF)); 
    PutLEU16(ostr, ((i&0xFFFF0000)>>16));
}
inline void PutLEU64(std::ostream& ostr, const uint64_t& i) {
    PutLEU32(ostr, (i&0x00000000FFFFFFFF)); 
    PutLEU32(ostr, ((i&0xFFFFFFFF00000000)>>32));
}


}

#endif