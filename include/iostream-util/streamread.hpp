#ifndef IOSTREAMUTIL_STREAMREAD_HPP
#define IOSTREAMUTIL_STREAMREAD_HPP

#include<iostream>
#include<stdint.h>

namespace iou {

inline uint8_t GetNextU8(std::istream& istr, std::ostream& err = std::cerr) {
    if(istr.eof()){err<<"iostream-util Error: Expected Atleast One More Byte But EOF Reached."<<std::endl; std::exit(1); return 0;}
    else{
        last_read = istr.tellg();
        return istr.get();
    }
}

//Big Endian
inline uint16_t GetNextBEU16(std::istream& istr, std::ostream& err = std::cerr){
    uint16_t u = ((uint16_t)GetNextU8(istr, err)) << 8;
    u |= (uint16_t)GetNextU8(istr, err);
    return u;   
}
inline uint32_t GetNextBEU32(std::istream& istr, std::ostream& err = std::cerr){
    uint32_t u = ((uint32_t)GetNextBEU16(istr, err)) << 16;
    u |= (uint32_t)GetNextBEU16(istr, err);
    return u;
}
inline uint64_t GetNextBEU64(std::istream& istr, std::ostream& err = std::cerr){
    uint64_t u = ((uint64_t)GetNextBEU32(istr, err)) << 32;
    u |= (uint64_t)GetNextBEU32(istr, err);    
    return u;
}

//Little Endian
inline uint16_t GetNextLEU16(std::istream& istr, std::ostream& err = std::cerr){
    uint16_t u = (uint16_t)GetNextU8(istr);
    u |= (((uint16_t)GetNextU8(istr)) << 8);
    return u;
}
inline uint32_t GetNextLEU32(std::istream& istr, std::ostream& err = std::cerr){
    uint32_t u = (uint32_t)GetNextLEU16(istr);
    u |= (((uint32_t)GetNextLEU16(istr)) << 16);
    return u;
}
inline uint64_t GetNextLEU64(std::istream& istr, std::ostream& err = std::cerr){
    uint64_t u = (uint64_t)GetNextLEU32(istr);
    u |= (((uint64_t)GetNextLEU32(istr)) << 32);
    return u;
}

}

#endif