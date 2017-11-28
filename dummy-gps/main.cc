/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <conreality/ddk.h>

#include <assert.h> /* for assert() */
#include <chrono>   /* for std::chrono */
#include <cstdio>   /* for stderr, std::fprintf() */
#include <cstdlib>  /* for EXIT_SUCCESS, std::atof() */
#include <random>   /* for std::default_random_engine */
#include <thread>   /* for std::this_thread */
#include <unistd.h> /* for getopt() */

static void
usage(const char* const program) {
  std::fprintf(stderr, "usage: %s [-i INTERVAL] [-n NOISE] [LAT] [LON]\n", program);
}

int
main(int argc, char* const argv[]) {
  using std::chrono::milliseconds;

  /* Define default parameters: */
  milliseconds interval{1000}; // -i %f
  double noise{0.0};           // -n %f
  double latitude{0.0};
  double longitude{0.0};

  /* Parse command-line options: */
  const char* program = argv[0];
  {
    int c;
    while ((c = getopt(argc, argv, "i:n:?h")) != -1) {
      switch (c) {
        case 'i':
          interval = milliseconds{static_cast<long>(std::atof(optarg) * 1000.0)};
          break;
        case 'n':
          noise = std::atof(optarg);
          break;
        case '?': case 'h': // fall through
        default:
          return usage(program), EXIT_SUCCESS;
      }
    }
    argc -= optind, argv += optind;
  }

  /* Parse command-line arguments: */
  if (argc >= 1) latitude  = atof(argv[0]);
  if (argc >= 2) longitude = atof(argv[1]);
  if (argc >= 3) return usage(program), EXIT_FAILURE;

  /* Open input/output streams: */
  conreality::ddk::input in;
  conreality::ddk::output out;

  /* Initialize the random-number generator: */
  std::default_random_engine rand;
  std::uniform_real_distribution<double> noise_dist{-1.0, 1.0};

  /* Generate sensor readings to the output stream: */
  while (in.is_open()) {
    double lat = latitude, lon = longitude;
    if (noise > 0.0) {
      lat += noise * noise_dist(rand);
      lon += noise * noise_dist(rand);
    }
    out.write_tuple(lon, lat);

    std::this_thread::sleep_for(interval);
  }

  return EXIT_SUCCESS;
}
