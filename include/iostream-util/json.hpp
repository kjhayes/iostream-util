#ifndef IOSTREAMUTIL_JSON_HPP
#define IOSTREAMUTIL_JSON_HPP

#include "iostream-util/ijsonwriteable.hpp"

namespace iou {
//static 
class JSON {
public:
    static void WriteJSONObject(std::ostream& ostr, const char* name, const IJSONWriteable& obj, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": {";
        if(!formatting.write_objects_inline){ostr<<std::endl;}
        if(formatting.increase_object_element_depth){formatting.depth++;}
        obj.WriteJSON(ostr, formatting);
        if(formatting.increase_object_element_depth){formatting.depth--;}
        for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        ostr<<"}";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    static void WriteJSONString(std::ostream& ostr, const char* name, const char* string, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": \""<<string<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONUnsigned(std::ostream& ostr, const char* name, const T& unsigned_number, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": "<<((uintmax_t)unsigned_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONSigned(std::ostream& ostr, const char* name, const T& signed_number, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": "<<((intmax_t)signed_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONNumber(std::ostream& ostr, const char* name, const T& streamed, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": "<<streamed;
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONHex(std::ostream& ostr, const char* name, const T& hex_num, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": \"0x"<<std::hex<<((uintmax_t)hex_num)<<std::dec<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    static void BeginWriteJSONStringStreamed(std::ostream& ostr, const char* name, JSONFormatting formatting){
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": \"";
    }
    static void EndWriteJSONStringStreamed(std::ostream& ostr, JSONFormatting formatting, const bool& is_last = false){
        ostr<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }
    static void BeginWriteJSONArray(std::ostream& ostr, const char* name, JSONFormatting formatting){
        if(!formatting.write_objects_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<name<<"\": [";
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    static void EndWriteJSONArray(std::ostream& ostr, JSONFormatting formatting, const bool& is_last = false){
        ostr<<"]";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_objects_inline){ostr<<std::endl;}
    }


    static void WriteJSONArrayObject(std::ostream& ostr, const IJSONWriteable& obj, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
            if(formatting.increase_array_element_depth){formatting.depth++;}
            obj.WriteJSON(ostr, formatting);
            if(formatting.increase_array_element_depth){formatting.depth--;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        else{
            bool temp = formatting.write_objects_inline;
            formatting.write_objects_inline = false;
            obj.WriteJSON(ostr, formatting, true)
            formatting.write_objects_inline = temp;
        }
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    static void WriteJSONArrayString(std::ostream& ostr, const char* string, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\""<<string<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONArrayUnsigned(std::ostream& ostr, const T& unsigned_number, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<((uintmax_t)unsigned_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONArraySigned(std::ostream& ostr, const T& signed_number, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<((intmax_t)signed_number);
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONArrayNumber(std::ostream& ostr, const T& streamed, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<streamed;
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    template<class T>
    static void WriteJSONArrayHex(std::ostream& ostr, const T& hex_num, JSONFormatting formatting, const bool& is_last = false) {
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\"0x"<<std::hex<<((uintmax_t)hex_num)<<std::dec<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    static void BeginWriteJSONArrayStringStreamed(std::ostream& ostr, JSONFormatting formatting){
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"\"";
    }
    static void EndWriteJSONArrayStringStreamed(std::ostream& ostr, JSONFormatting formatting, const bool& is_last = false){
        ostr<<"\"";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
    static void BeginWriteJSONArrayArray(std::ostream& ostr, JSONFormatting formatting){
        if(!formatting.write_arrays_inline){
            for(int i = 0; i < formatting.spacing; i++){ostr<<std::endl;}
            for(int i = 0; i < formatting.depth; i++){ostr<<"\t";}
        }
        ostr<<"[";
    }
    static void EndWriteJSONArrayArray(std::ostream& ostr, JSONFormatting formatting, const bool& is_last = false){
        ostr<<"]";
        if(!is_last){ostr<<", ";}
        if(!formatting.write_arrays_inline){ostr<<std::endl;}
    }
};
}

#endif