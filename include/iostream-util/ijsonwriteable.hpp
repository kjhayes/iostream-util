#ifndef IOSTREAMUTIL_IJSONWRITEABLE_HPP
#define IOSTREAMUTIL_IJSONWRITEABLE_HPP

#include<iostream>

namespace iou {
struct JSONFormatting {
    int spacing = 0;
    int depth = 0;
    bool write_objects_inline = false;
    bool increase_object_element_depth = true;
};

class IJSONWriteable {
public:
    virtual void WriteJSON(std::ostream& ostr, JSONFormatting formatting) const = 0;
};

}
#endif