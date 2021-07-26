#ifndef IOSTREAMUTIL_IJSONWRITEABLE_HPP
#define IOSTREAMUTIL_IJSONWRITEABLE_HPP

#include<iostream>

namespace iou {
struct JSONFormatting {
    int spacing = 1;
    int depth = 0;
    bool write_objects_inline = false;
    bool increase_object_element_depth = true;
};

class IJSONWriteable {
public:
    virtual void WriteJSON(std::ostream& ostr, JSONFormatting formatting, const bool& is_last = false) const = 0;

    static void WriteJSONObject(std::ostream& ostr, const char* name, const IJSONWriteable& obj, JSONFormatting formatting) {
        for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"\""<<name<<"\": {";
        if(!formatting.write_objects_inline){ostr<<std::endl;}
        if(formatting.increase_object_element_depth){formatting.depth++;}
        obj.WriteJSON(ostr, formatting);
        if(formatting.increase_object_element_depth){formatting.depth--;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"}";
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    static void WriteJSONString(std::ostream& ostr, const char* name, const char* string, JSONFormatting formatting, const bool& is_last = false) {
        for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"\""<<name<<"\": \""<<string<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONUnsigned(std::ostream& ostr, const char* name, const T& unsigned_number, JSONFormatting formatting, const bool& is_last = false) {
        for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"\""<<name<<"\": "<<((uintmax_t)unsigned_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONSigned(std::ostream& ostr, const char* name, const T& signed_number, JSONFormatting formatting, const bool& is_last = false) {
        for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"\""<<name<<"\": "<<((intmax_t)signed_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONHexString(std::ostream& ostr, const char* name, const T& hex_num, JSONFormatting formatting, const bool& is_last = false) {
        for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"\""<<name<<"\": \"0x"<<std::hex<<((uintmax_t)hex_num)<<std::dec<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
};

}
#endif