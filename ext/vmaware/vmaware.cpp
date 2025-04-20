// we have to wrap because msvc moment
#include "../vmaware_wrapper/vmaware_wrapper.h"

#include "ruby.h"
#include <cstdint>
#include <string>

VALUE rb_vm_detect(VALUE self) {
  bool is_vm = vm_detect();
  return is_vm ? Qtrue : Qfalse;
}

VALUE rb_vm_percentage(VALUE self) {
  uint8_t percentage = vm_percentage();
  return INT2NUM(percentage);
}

VALUE rb_vm_brand(VALUE self) {
  size_t len = vm_brand(NULL, 0);
  char *buf = new char[len];

  vm_brand(buf, len);

  VALUE rb_brand = rb_str_new(buf, len);

  delete[] buf;
  return rb_brand;
}

VALUE rb_vm_type(VALUE self) {
  size_t len = vm_type(NULL, 0);
  char *buf = new char[len];

  vm_type(buf, len);

  VALUE rb_type = rb_str_new(buf, len);
  delete[] buf;

  return rb_type;
}

VALUE rb_vm_conclusion(VALUE self) {
  size_t len = vm_conclusion(NULL, 0);
  char *buf = new char[len];

  vm_conclusion(buf, len);

  VALUE rb_conclusion = rb_str_new(buf, len);
  delete[] buf;

  return rb_conclusion;
}

VALUE rb_vm_detected_count(VALUE self) {
  uint8_t detected_count = vm_detected_count();
  return INT2NUM(detected_count);
}

extern "C" void Init_vmaware(void) {
  VALUE module = rb_define_module("VmAware");
  rb_define_module_function(module, "detect", rb_vm_detect, 0);
  rb_define_module_function(module, "percentage", rb_vm_percentage, 0);
  rb_define_module_function(module, "brand", rb_vm_brand, 0);
  rb_define_module_function(module, "type", rb_vm_type, 0);
  rb_define_module_function(module, "conclusion", rb_vm_conclusion, 0);
  rb_define_module_function(module, "detected_count", rb_vm_detected_count, 0);
}
