#include "vmaware.hpp"
#include "ruby.h"
#include "ruby/backward/cxxanyargs.hpp"
#include <cstdint>
#include <string>

VALUE vm_detect(VALUE self) {
  bool is_vm = VM::detect();
  return is_vm ? Qtrue : Qfalse;
}

VALUE vm_percentage(VALUE self) {
  uint8_t percentage = VM::percentage();
  return INT2NUM(percentage);
}

VALUE vm_brand(VALUE self) {
  std::string brand = VM::brand();
  VALUE rb_brand = rb_str_new(brand.data(), brand.size());
  return rb_brand;
}

VALUE vm_type(VALUE self) {
  std::string type = VM::type();
  VALUE rb_type = rb_str_new(type.data(), type.size());
  return rb_type;
}

VALUE vm_conclusion(VALUE self) {
  std::string conclusion = VM::conclusion();
  VALUE rb_conclusion = rb_str_new(conclusion.data(), conclusion.size());
  return rb_conclusion;
}

VALUE vm_detected_count(VALUE self) {
  uint8_t detected_count = VM::detected_count();
  return INT2NUM(detected_count);
}

extern "C" void Init_vmaware(void) {
  VALUE module = rb_define_module("VmAware");
  rb_define_module_function(module, "detect", vm_detect, 0);
  rb_define_module_function(module, "percentage", vm_percentage, 0);
  rb_define_module_function(module, "brand", vm_brand, 0);
  rb_define_module_function(module, "type", vm_type, 0);
  rb_define_module_function(module, "conclusion", vm_conclusion, 0);
  rb_define_module_function(module, "detected_count", vm_detected_count, 0);
}
