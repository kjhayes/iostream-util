#ifndef CFDUMP_STREAMREADER_HPP
#define CFDUMP_STREAMREADER_HPP

#include<iostream>
#include<stdint.h>

namespace iou {

uint8_t GetNextU8(std::istream& istr, std::ostream& err);
//Big Endian
uint16_t GetNextBEU16(std::istream& istr, std::ostream& err);
uint32_t GetNextBEU32(std::istream& istr, std::ostream& err);
uint64_t GetNextBEU64(std::istream& istr, std::ostream& err);
//Little Endian
uint16_t GetNextLEU16(std::istream& istr, std::ostream& err);
uint32_t GetNextLEU32(std::istream& istr, std::ostream& err);
uint64_t GetNextLEU64(std::istream& istr, std::ostream& err);
}

#endif