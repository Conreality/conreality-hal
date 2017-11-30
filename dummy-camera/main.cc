/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <conreality/ddk.h>

#include <assert.h> /* for assert() */
#include <chrono>   /* for std::chrono */
#include <cstdio>   /* for stderr, std::fprintf() */
#include <cstdlib>  /* for EXIT_* */
#include <thread>   /* for std::this_thread */
#include <unistd.h> /* for getopt() */

static void
usage(const char* const program) {
  std::fprintf(stderr, "usage: %s\n", program);
}

int
main(int argc, char* const argv[]) {
  /* Parse command-line options: */
  const char* program = argv[0];
  {
    int c;
    while ((c = getopt(argc, argv, "?h")) != -1) {
      switch (c) {
        case '?': case 'h': // fall through
        default:
          return usage(program), EXIT_SUCCESS;
      }
    }
    argc -= optind, argv += optind;
  }

  /* Parse command-line arguments: */
  if (argc >= 0) return usage(program), EXIT_FAILURE;

  try {
    /* Open the driver input & output streams: */
    conreality::ddk::input in;
    conreality::ddk::output out;

    /* Generate sensor readings to the output stream: */
    while (in.is_open()) {
      std::this_thread::sleep_for(std::chrono::seconds{1}); // TODO
    }

    return EXIT_SUCCESS;
  }
  catch (const std::exception& error) {
    std::fprintf(stderr, "%s: %s\n", program, error.what());
    return EXIT_FAILURE;
  }
}
