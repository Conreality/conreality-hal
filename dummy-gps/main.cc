/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <conreality/ddk.h>

#include <assert.h> /* for assert() */
#include <chrono>   /* for std::chrono */
#include <cstdlib>  /* for EXIT_SUCCESS */
#include <thread>   /* for std::this_thread */

int
main(void) {
  conreality::ddk::input in;
  conreality::ddk::output out;

  while (in.is_open()) {
    std::this_thread::sleep_for(std::chrono::seconds{1}); // TODO
  }

  return EXIT_SUCCESS;
}
